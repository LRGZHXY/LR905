#include <stdio.h>
#include <stdlib.h> //EXIT_FAILURE
#include <string.h> //strlen  strdup
#include <sys/stat.h> //struct stat
#include <pwd.h> //struct passwd
#include <grp.h> //struct group
#include <time.h> //ctime
#include <dirent.h> //DIR

#define a 1
#define l 2
#define R 3
#define t 4
#define r 5
#define I 6
#define s 7

int ls_[10]={0};

void do_ls (char*dirname);
void ls_l(struct stat info,char* name);

void do_ls(char*dirname)
{
    struct dirent *ptr;
    char**dirname=NULL;
    int count=0;

    DIR *dir=opendir(dirname);
    if(dir==NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    //保存目录中的文件名
    while(ptr=readdir(dir)!=NULL)
    {
        //如果没有-a命令，则跳过隐藏文件
        if(!ls_[a]&&ptr->d_name[0]=='.');
            continue;
        dirname=realloc(dirname,(count+1)*sizeof(char*));
        dirname[count++]=strdup(ptr->d_name);
    }
    closedir(dir);

    //构建文件的完整路径
    char**filename=(char**)malloc((count+1)*sizeof(char*));
    struct stat*buf=malloc(sizeof(struct stat));

    for(int i=0;i<=count;i++)
    {
        char*filename=(char*)malloc(sizeof(char*)*80);
    }
    for(int i=0;i<count;i++)
    {
        strncpy(filename[i],dirname,strlen(dirname));
        strcat(filename[i],"/");
        strcat(filename[i],ptr->d_name);
        if(lstat(filename[i],buf)==-1)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }
    }

    //显示总用量
    if(ls_[s]||ls_[l])
    {
        
    }
}

/*struct stat 结构成员:
 st_mode：表示文件的类型和访问权限。
 st_ino：表示文件的索引节点号。
 st_dev：表示文件所在的设备的标识号。
 st_nlink：文件的硬链接数。
 st_uid：表示文件所有者的用户 ID。
 st_gid：表示文件所属组的组 ID。
 st_size：表示文件的大小（以字节为单位）。
 st_atime：表示文件的最后访问时间。
 st_mtime：表示文件的最后修改时间。
 st_ctime：表示文件的状态发生变化的时间。*/
void ls_l(struct stat info,char* name)
{
    char permissions[10]={0};
    //文件类型
    if(S_ISREG(info.st_mode))//普通文件
        permissions[0]='-';
    else if(S_ISDIR(info.st_mode))//目录
        permissions[0]='d';
    else if(S_ISLNK(info.st_mode))//符号链接文件
        permissions[0]='l';
    else if(S_ISCHR(info.st_mode))//字符设备文件
        permissions[0]='c';
    else if(S_ISBLK(info.st_mode))//块设备文件
        permissions[0]='b';
    else if(S_ISSOCK(info.st_mode))//套接字文件
        permissions[0]='s';
    else if(S_ISFIFO(info.st_mode))//FIFO文件（命名管道）
        permissions[0]='p';

    //所有者权限
      /* S_IRUSR 0000 0001 0000 0000(256)
         S_IWUSR 0000 0000 1000 0000(128)
         S_IXUSR 0000 0000 0100 0000 (64)*/
    permissions[1]=info.st_mode&S_IRUSR?"r":"-";
    permissions[2]=info.st_mode&S_IWUSR?"w":"-";
    permissions[3]=info.st_mode&S_IXUSR?"x":"-";

    //组用户权限
    permissions[4]=info.st_mode&S_IRGRP?"r":"-";
    permissions[5]=info.st_mode&S_IWGRP?"w":"-";
    permissions[6]=info.st_mode&S_IXGRP?"x":"-";

    //其他用户权限
    permissions[7]=info.st_mode&S_IROTH?"r":"-";
    permissions[8]=info.st_mode&S_IWOTH?"w":"-";
    permissions[9]=info.st_mode&S_IXOTH?"x":"-";

    printf("%s ",permissions);

    //硬链接数
    printf("%ld ",info.st_nlink);

    //用户ID
    struct passwd *pwd=getpwuid(info.st_uid);
    printf("%-8s ",pwd->pw_name);

    //组ID
    struct group *grp=getpwuid(info.st_gid);
    printf("%-8s ",grp->gr_name);

    //文件大小
    printf("%-10ld ",info.st_size);

    //时间
    char modtime[25];
    strcpy(modtime,ctime(&info.st_mtime));
    modtime[strlen(modtime)-1]='\0';
    printf("%s ",modtime);

    //文件名
    printf(" %s",name);

    printf("\n");
}

int main(int argc,char*argv[])
{
    int count=0;
    for(int i=1;i<argc;i++)
    {
        if(argv[i][0]=='-')
        {
            int j=1;
            do{
                switch(argv[i][j])
                {
                    case 'a': 
                        ls_[a]++;
                        break;
                    case 'l':
                        ls_[l]++;
                        break;
                    case 'R':
                        ls_[R]++;
                        break;
                    case 't':
                        ls_[t]++;
                        break;
                    case 'r':
                        ls_[r]++;
                        break;
                    case 'I':
                        ls_[I]++;
                        break;
                    case 's':
                        ls_[s]++;
                        break;
                    default:
                        printf("命令错误");
                        exit(EXIT_FAILURE);
                }
                j++;
            }while(j<strlen(argv[i]));
            count++;
        }
    }
    //只有参数选项(以 '-' 开头的参数),默认使用当前目录作为操作目标
    if(count+1==argc)
    {
        do_ls('.');
    }
    //对命令行中出现的目录进行相应操作
    else
    {
        for(int i=1;i<argc;i++)
        {
            if(argv[i][0]!='-')
            {
                do_ls(argv[i]);
            }
        }
    }
    return 0;
}
