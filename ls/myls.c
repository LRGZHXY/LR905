#include <stdio.h>
#include <stdlib.h>       //EXIT_FAILURE  qsort
#include <string.h>       //strlen  strdup
#include <sys/stat.h>     //struct stat
#include <pwd.h>          //struct passwd
#include <grp.h>          //struct group
#include <time.h>         //ctime
#include <dirent.h>       //DIR
#include <linux/limits.h> //PATH_MAX

#define a 1
#define l 2
#define R 3
#define t 4
#define r 5
#define I 6
#define s 7

void do_ls(int ls_[],char *dirname);
void ls_l(struct stat info, char *name);
int lettersort(const void *m, const void *n);
void addcolor(char *name, struct stat info);

/*struct dirent结构体成员:
ino_t d_ino：目录项的 inode 号
off_t d_off：目录项在目录流中的偏移量
unsigned short d_reclen：目录项长度。
unsigned char d_type：目录项的类型，可能的取值包括 DT_UNKNOWN、DT_FIFO、DT_CHR、DT_DIR、DT_BLK、DT_REG、DT_LNK、DT_SOCK 等，表示不同类型的文件或目录。
char d_name[]：目录项的名称，以 null 终止的字符串。*/
void do_ls(int ls_[],char *dirname)
{
    struct stat info;
    struct dirent *ptr;
    char **filename = NULL;
    int count = 0;
    long filetime[256];

    DIR *dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    // 保存目录中的文件名
    while ((ptr = readdir(dir)) != NULL)
    {
        // 如果没有-a命令，则跳过隐藏文件  ls-a
        if (!ls_[a] && ptr->d_name[0] == '.');
          continue;
        filename = realloc(filename, (count + 1) * sizeof(char *));
        filename[count++] = strdup(ptr->d_name);
    }
    closedir(dir);

    // 按首字母A-Z排序
    qsort(filename, count, sizeof(char *), lettersort);

    // 若按修改时间排序  ls-t
    if (ls_[t])
    {
        struct stat info;
        for (int i = 0; i < count; i++)
        {
            if (lstat(filename[i], &info) == -1)
            {
                perror("lstat error");
            }
            filetime[i] = info.st_mtime;
        }
        for (int i = 0; i < count; i++)
        {
            for (int j = i; j < count; j++)
            {
                if (filetime[i] < filetime[j])
                {
                    long int temp = filetime[i];
                    filetime[i] = filetime[j];
                    filetime[j] = temp;
                }
            }
        }
    }

    // 若按Z-A排序  ls-r
    if (ls_[r])
    {
        for (int i = 0; i < count / 2; i++)
        {
            char *temp;
            temp = filename[i];
            filename[i] = filename[count - i - 1];
            filename[count - i - 1] = temp;
        }
    }

    // 构建文件的完整路径
    for (int i = 0; i < count; i++)
    {
        char *path = malloc(strlen(dirname) + strlen(filename[i] + 2));
        if(path==NULL)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }
        sprintf(path, "%s/%s", dirname, filename[i]);
        struct stat *buf = malloc(sizeof(struct stat));
        if (buf == NULL) {
            perror("error");
            exit(EXIT_FAILURE);
        }
        if (lstat(path, buf) == -1)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }  

        // 显示总用量  ls-s
        if (ls_[s] || ls_[l])
        {
            printf("总用量:%-10ld ", (long)((buf->st_blocks) / 2));
            addcolor(dirname, info);
        }

        // 显示节点号  ls-i
        if (ls_[I])
        {
            printf("%ld ", info.st_ino);
            addcolor(dirname, info);
        }

        // ls-l
        if (ls_[l])
        {
            char name[PATH_MAX];
            ls_l(info, name);
        }

        // ls-R
        if (ls_[R])
        {
            if (S_ISDIR(info.st_mode))
            {
                if (strcmp(filename[i], ".") == 0 || strcmp(filename[i], "..") == 0)
                {
                    return;
                }
                else
                {
                    printf("\n%s:\n", path);
                    do_ls(ls_,path);
                }
            }
        }

        free(buf);
        free(path);
        free(filename);
    }
}

/*struct stat 结构体成员:
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
void ls_l(struct stat info, char *name)
{
    char permissions[11] = {0};
    // 文件类型
    if (S_ISREG(info.st_mode)) // 普通文件
        permissions[0] = '-';
    else if (S_ISDIR(info.st_mode)) // 目录
        permissions[0] = 'd';
    else if (S_ISLNK(info.st_mode)) // 符号链接文件
        permissions[0] = 'l';
    else if (S_ISCHR(info.st_mode)) // 字符设备文件
        permissions[0] = 'c';
    else if (S_ISBLK(info.st_mode)) // 块设备文件
        permissions[0] = 'b';
    else if (S_ISSOCK(info.st_mode)) // 套接字文件
        permissions[0] = 's';
    else if (S_ISFIFO(info.st_mode)) // FIFO文件（命名管道）
        permissions[0] = 'p';

    // 所有者权限
    /* S_IRUSR 0000 0001 0000 0000(256)
       S_IWUSR 0000 0000 1000 0000(128)
       S_IXUSR 0000 0000 0100 0000 (64)*/
    permissions[1] = info.st_mode & S_IRUSR ? 'r' : '-';
    permissions[2] = info.st_mode & S_IWUSR ? 'r' : '-';
    permissions[3] = info.st_mode & S_IXUSR ? 'r' : '-';

    // 组用户权限
    permissions[4] = info.st_mode & S_IRGRP ? 'r' : '-';
    permissions[5] = info.st_mode & S_IWGRP ? 'r' : '-';
    permissions[6] = info.st_mode & S_IXGRP ? 'r' : '-';

    // 其他用户权限
    permissions[7] = info.st_mode & S_IROTH ? 'r' : '-';
    permissions[8] = info.st_mode & S_IWOTH ? 'r' : '-';
    permissions[9] = info.st_mode & S_IXOTH ? 'r' : '-';

    printf("%s ", permissions);

    // 硬链接数
    printf("%ld ", info.st_nlink);

    // 用户ID
    struct passwd *pwd = getpwuid(info.st_uid);
    printf("%-8s ", pwd->pw_name);

    // 组ID
    struct group *grp = getgrgid(info.st_gid);
    printf("%-8s ", grp->gr_name);

    // 文件大小
    printf("%-10ld ", info.st_size);

    // 时间
    char modtime[30];
    strcpy(modtime, ctime(&info.st_mtime));
    modtime[strlen(modtime) - 1] = '\0';
    printf("%s ", modtime);

    // 文件名
    addcolor(name, info);

    printf("\n");
}

void addcolor(char *name, struct stat info)
{
    if (S_ISDIR(info.st_mode))
    { // 目录 蓝色
        printf("\033[01;34m%s\033[0m\n", name);
    }
    else if (S_ISLNK(info.st_mode))
    { // 符号链接 青色
        printf("\033[01;36m%s\033[0m\n", name);
    }
    else if (S_ISCHR(info.st_mode))
    { // 字符设备文件 黄色
        printf("\033[01;33m%s\033[0m\n", name);
    }
    else if (S_ISBLK(info.st_mode))
    { // 块设备文件 黑色
        printf("\033[01;30m%s\033[0m\n", name);
    }
    else if (S_ISSOCK(info.st_mode))
    { // 套接字文件 洋红色
        printf("\033[01;35m%s\033[0m\n", name);
    }
    else if (S_ISFIFO(info.st_mode))
    { // FIFO文件（命名管道）橙色
        printf("\033[01;31m%s\033[0m\n", name);
    }
    else if (S_ISREG(info.st_mode))
    { // 可执行文件 绿色
        if (info.st_mode & S_IXUSR || info.st_mode & S_IXGRP || info.st_mode & S_IXOTH)
        {
            printf("\033[01;32m%s\033[0m\n", name);
        }
        else
        {
            printf("%-20s ", name);
        }
    }
    else
    {
        printf("%-20s ", name);
    }
}

int lettersort(const void *m, const void *n)
{
    return strcmp(*(const char **)m, *(const char **)n);
}

int main(int argc, char *argv[])
{
    int ls_[8] = {0};
    int cnt = 0;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            int j = 1;
            do
            {
                cnt++;
                switch (argv[i][j])
                {
                case 'a':
                    ls_[a]=1;
                    break;
                case 'l':
                    ls_[l]=1;
                    break;
                case 'R':
                    ls_[R]=1;
                    break;
                case 't':
                    ls_[t]=1;
                    break;
                case 'r':
                    ls_[r]=1;
                    break;
                case 'I':
                    ls_[I]=1;
                    break;
                case 's':
                    ls_[s]=1;
                    break;
                default:
                    printf("命令错误");
                    exit(EXIT_FAILURE);
                }
                j++;
            } while (j < strlen(argv[i]));
        }
    }
    // 只有参数选项(以 '-' 开头的参数),默认使用当前目录作为操作目标
    if (cnt + 1 == argc)
    {
        do_ls(ls_,".");
    }
    // 对命令行中出现的目录进行相应操作
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] != '-')
            {
                printf("%s:\n", argv[i]);
                do_ls(ls_,argv[i]);
            }
        }
    }
    return 0;
}
