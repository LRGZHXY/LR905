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

void do_ls(char *dirname, int ls_[]);
void ls_l(struct stat *buf);
int lettersort(const void *m, const void *n);
void addcolor(char *name, struct stat *buf);
int timesort(const void *x, const void *y);

/*struct dirent结构体成员:
ino_t d_ino：目录项的 inode 号
off_t d_off：目录项在目录流中的偏移量
unsigned short d_reclen：目录项长度。
unsigned char d_type：目录项的类型，可能的取值包括 DT_UNKNOWN、DT_FIFO、DT_CHR、DT_DIR、DT_BLK、DT_REG、DT_LNK、DT_SOCK 等，表示不同类型的文件或目录。
char d_name[]：目录项的名称，以 null 终止的字符串。*/
void do_ls(char *dirname, int ls_[])
{
    struct stat info;
    struct dirent *ptr;
    int count = 0;
    long filetime[256];
    char **filename = NULL;

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
        if (!ls_[a] && ptr->d_name[0] == '.')
            continue;
        filename = realloc(filename, (count + 1) * sizeof(char *));
        filename[count++] = strdup(ptr->d_name);
    }

    // 按首字母A-Z排序
    qsort(filename, count, sizeof(char *), lettersort);

    // 若按修改时间排序  ls-t
    if (ls_[t])
    {
        qsort(filename, count, sizeof(char *), timesort);
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

    // 显示总用量  ls-s
    if (ls_[s] || ls_[l])
    {
        long long int totall = 0;
        for (int i = 0; i < count; i++)
        {
            struct stat buf; // 定义成指针会显示段错误
            stat(filename[i], &buf);
            long long int size = (buf.st_blocks) / 2;
            totall += size;
        }
        printf("总用量 %lld\n", totall);
    }

    // 构建文件的完整路径
    for (int i = 0; i < count; i++)
    {
        struct stat *buf = malloc(sizeof(struct stat));
        char *path = malloc(strlen(dirname) + strlen(filename[i]) + 2);
        if (path == NULL)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }
        sprintf(path, "%s/%s", dirname, filename[i]);

        if (buf == NULL)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }
        if (lstat(path, buf) == -1)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }

        if (ls_[I])
        {
            printf(" %-8lu ", buf->st_ino);
        }
        if (ls_[s])
        {
            printf("%-10ld ", (long)((buf->st_blocks) / 2));
            // st_blocks 的值通常是以512字节块为单位的整数值，将其除以2可以得到以1024字节块为单位的结果
        }
        if (ls_[l])
        {
            ls_l(buf);
        }
        addcolor(filename[i], buf);
        printf("\n");

        if (ls_[R])
        {
            if (S_ISDIR(buf->st_mode))
            {
                if (strcmp(filename[i], ".") != 0 && strcmp(filename[i], "..") != 0)
                {
                    char *tempptr = malloc(strlen(path) + 1);
                    if (tempptr == NULL)
                    {
                        perror("error");
                        exit(EXIT_FAILURE);
                    }
                    strcpy(tempptr, path);
                    printf("\n%s:\n", tempptr);
                    do_ls(tempptr, ls_);
                    free(tempptr);
                }
            }
        }

        free(buf);
        free(path);
    }
    free(filename);
    closedir(dir);
}

void addcolor(char *name, struct stat *buf)
{
    if (S_ISDIR(buf->st_mode))
    { // 目录 蓝色
        printf("\033[01;34m%s\033[0m", name);
    }
    else if (S_ISLNK(buf->st_mode))
    { // 符号链接 青色
        printf("\033[01;36m%s\033[0m", name);
    }
    else if (S_ISCHR(buf->st_mode))
    { // 字符设备文件 黄色
        printf("\033[01;33m%s\033[0m", name);
    }
    else if (S_ISBLK(buf->st_mode))
    { // 块设备文件 黑色
        printf("\033[01;30m%s\033[0m", name);
    }
    else if (S_ISSOCK(buf->st_mode))
    { // 套接字文件 洋红色
        printf("\033[01;35m%s\033[0m", name);
    }
    else if (S_ISFIFO(buf->st_mode))
    { // FIFO文件（命名管道）橙色
        printf("\033[01;31m%s\033[0m", name);
    }
    else if (S_ISREG(buf->st_mode))
    { // 可执行文件 绿色
        if (buf->st_mode & S_IXUSR || buf->st_mode & S_IXGRP || buf->st_mode & S_IXOTH)
        {
            printf("\033[01;32m%s\033[0m", name);
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

typedef struct
{
    struct stat info;
} info;
int timesort(const void *x, const void *y)
{
    info *xt = (info *)x;
    info *yt = (info *)y;
    return xt->info.st_mtime - yt->info.st_mtime;
}

void ls_l(struct stat *buf)
{
    char permissions[11] = {0};
    // 文件类型
    if (S_ISREG(buf->st_mode)) // 普通文件
        permissions[0] = '-';
    else if (S_ISDIR(buf->st_mode)) // 目录
        permissions[0] = 'd';
    else if (S_ISLNK(buf->st_mode)) // 符号链接文件
        permissions[0] = 'l';
    else if (S_ISCHR(buf->st_mode)) // 字符设备文件
        permissions[0] = 'c';
    else if (S_ISBLK(buf->st_mode)) // 块设备文件
        permissions[0] = 'b';
    else if (S_ISSOCK(buf->st_mode)) // 套接字文件
        permissions[0] = 's';
    else if (S_ISFIFO(buf->st_mode)) // FIFO文件（命名管道）
        permissions[0] = 'p';

    // 所有者权限
    /* S_IRUSR 0000 0001 0000 0000(256)
       S_IWUSR 0000 0000 1000 0000(128)
       S_IXUSR 0000 0000 0100 0000 (64)*/
    permissions[1] = buf->st_mode & S_IRUSR ? 'r' : '-';
    permissions[2] = buf->st_mode & S_IWUSR ? 'w' : '-';
    permissions[3] = buf->st_mode & S_IXUSR ? 'x' : '-';

    // 组用户权限
    permissions[4] = buf->st_mode & S_IRGRP ? 'r' : '-';
    permissions[5] = buf->st_mode & S_IWGRP ? 'w' : '-';
    permissions[6] = buf->st_mode & S_IXGRP ? 'x' : '-';

    // 其他用户权限
    permissions[7] = buf->st_mode & S_IROTH ? 'r' : '-';
    permissions[8] = buf->st_mode & S_IWOTH ? 'w' : '-';
    permissions[9] = buf->st_mode & S_IXOTH ? 'x' : '-';

    printf("%s ", permissions);
    // 硬链接数
    printf("  %ld ", buf->st_nlink);

    // 用户ID
    struct passwd *pwd = getpwuid(buf->st_uid);
    printf(" %-8s ", pwd->pw_name);

    // 组ID
    struct group *grp = getgrgid(buf->st_gid);
    printf("%-8s ", grp->gr_name);

    // 文件大小
    // printf("%-10ld ", buf->st_size);
    if (S_ISDIR(buf->st_mode))
    {
        printf(" %-10s", "");
    }
    else
    {
        printf(" %-10ld", (long)buf->st_size);
    }

    // 时间
    char modtime[30];
    strftime(modtime, sizeof(modtime), "%b %d %H:%M", localtime(&buf->st_mtime));
    //"%b"代表月份的缩写，"%d"代表月中的第几天，"%H"代表小时（24小时制），"%M"代表分钟
    printf(" %s  ", modtime);
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
 st_mtime：表示文件的最后修改时间。*/
int main(int argc, char *argv[])
{
    int ls_[8] = {0};
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            for (int j = 1; j < strlen(argv[i]); j++)
            {
                switch (argv[i][j])
                {
                case 'a':
                    ls_[a] = 1;
                    break;
                case 'l':
                    ls_[l] = 1;
                    break;
                case 'R':
                    ls_[R] = 1;
                    break;
                case 't':
                    ls_[t] = 1;
                    break;
                case 'r':
                    ls_[r] = 1;
                    break;
                case 'i':
                    ls_[I] = 1;
                    break;
                case 's':
                    ls_[s] = 1;
                    break;
                default:
                    printf("命令错误");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    int flag = 0;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] != '-')
        {
            flag = 1;
            printf("%s:\n", argv[i]);
            do_ls(argv[i], ls_);
        }
    }
    if (flag == 0)
        do_ls(".", ls_);

    return 0;
}