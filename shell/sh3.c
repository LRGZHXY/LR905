#include <stdio.h>
#include <signal.h> //SIGINT  SIGHUP
#include <string.h>
#include <unistd.h>    //getlogin gethostname getcwd
#include <sys/types.h> //pid_t
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <sys/wait.h> //waitpid
#include <fcntl.h>    //O_RDONLY

#define MAX 128

void ignore();    // 设置屏蔽信号
void printInfo(); // 打印信息
// void splitCmd(char *cmd); // 分割命令
// void analysecmd(char *argv[], int num);
void dealCmd(char *cmd); // 处理命令
int executeCmd(char *argv[], int count);
void do_cd(char *argv[]);
void printerror(char *error, int num);
void Redirect(char *argv[], int left, int right);
void doPipe(char *argv[], int left, int right);

char *argv[MAX] = {NULL};
int back = 0;

int main()
{
    ignore();

    while (1)
    {
        printInfo();

        char *cmd = readline(NULL);
        if (cmd == NULL)
        {
            break; // 屏蔽ctrl+D
        }

        if (strlen(cmd) > 0)
        {
            add_history(cmd);
            if (strcmp(cmd, "exit") == 0)
            {
                free(cmd);
                break;
            }
            dealCmd(cmd);
        }
        free(cmd);
    }
    return 0;
}

void ignore()
{
    signal(SIGINT, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
}

void printInfo()
{
    char hostname[MAX];
    char *username;
    char path[MAX];

    username = getlogin(); // 返回一个指向当前登录用户的用户名字符串的指针
    gethostname(hostname, sizeof(hostname));
    getcwd(path, sizeof(path));

    char *lastpath = strrchr(path, '/'); // 返回最后一次出现/的位置的指针
    if (lastpath != NULL)
    {
        lastpath++;
    }

    printf("\033[33m%s\033[0m", username); // 黄色
    printf("@");
    printf("\033[32m%s\033[0m", hostname); // 绿色
    printf("\033[34m%s\033[0m", strcmp(username, lastpath) ? lastpath : "~");
    printf("\033[35m%s\033[0m", " $ ");

    fflush(stdout);
}

void dealCmd(char *cmd)
{
    const char *sign = " ";
    char path[20];
    sprintf(path, "/home/%s", getlogin());
    char *argv[MAX];
    int count = 0;
    char *toke = strtok(cmd, sign);
    while (toke != NULL)
    {
        argv[count] = toke;
        toke = strtok(NULL, sign);
        if (strcmp(argv[count], "~") == 0)
        {
            argv[count] = path;
        }
        count++;
    }
    argv[count] = NULL;

    if (argv[0] == NULL)
    {
        return;
    }

    if (strcmp(argv[0], "cd") == 0)
    {
        do_cd(argv);
        return;
    }

    executeCmd(argv, count);
}

int executeCmd(char *argv[], int count)
{
    int pass = 0;
    pid_t pid = fork();
    if (pid == -1)
    {
        printerror("forkerror", 1);
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(argv[i], "&") == 0)
        {
            pass = 1;
            argv[i] = NULL;
            break;
        }
    }
    if (pid == 0) // 子进程
    {
        // execvp(argv[0], argv);
        //  printerror("pserror",2);
        doPipe(argv, 0, count);
    }
    else if (pid > 0) // 父进程
    {
        if (pass == 0)
        {
            waitpid(pid, NULL, 0); // 参数 0 表示等待子进程完成的行为为阻塞，即父进程将一直等待，直到指定的子进程结束
        }
    }
}

void printerror(char *error, int num)
{
    perror(error);
    exit(num);
}

void do_cd(char *argv[])
{
    char curPath[MAX];

    if (getcwd(curPath, sizeof(curPath)) == NULL)
    {
        printerror("curPath error", 1);
    }

    if (argv[1] == NULL) // 在处理用户输入的cd命令时，如果用户没有提供目标目录参数，则将当前目录切换到用户的主目录
    {
        char *homePath = getenv("HOME");
        if (homePath != NULL)
        {
            if (chdir(homePath) == -1)
            {
                printerror("switchdir error", 2);
            }
        }
        else
        {
            printerror("not found homePath", 1);
        }
        setenv("OLDPWD", curPath, 1);
        return;
    }
    else if (strcmp(argv[1], "-") == 0)
    {
        char *prePath;
        prePath = getenv("OLDPWD");
        if (prePath != NULL)
        {
            if (chdir(prePath) == -1)
            {
                printerror("switchpredir error", 3);
            }
        }
        else
        {
            printerror("not found prePath", 1);
        }
    }
    // else if (strcmp(argv[1], "~") == 0)
    // {
    //     char dir[20];
    //     sprintf(dir, "/home/%s", getlogin());
    //     chdir(dir);
    // }
    else
    {
        if (chdir(argv[1]) == -1)
        {
            printerror("opendir error", 1);
        }
    }

    setenv("OLDPWD", curPath, 1);
}

void doPipe(char *argv[], int left, int right)
{
    int flag[10];
    pid_t pid;
    int num = 0;
    int cmdcnt = num + 1;
    char *cmd[cmdcnt][10];
    int flagpipe = -1;

    for (int i = left; i < right; i++)
    {
        if (argv[i] == NULL)
        {
            continue;
        }
        if (strcmp(argv[i], "|") == 0)
        {
            flagpipe = i;
            break;
        }
    }

    if (flagpipe == -1)
    {
        Redirect(argv, left, right);
        exit(EXIT_FAILURE);
    }
    if (flagpipe + 1 == right)
    {
        printerror("error", EXIT_FAILURE);
    }
    int pipes[2];
    // for (int i = 0; i < num; i++)
    // {
    //     pipe(pipes[i]);
    // }
    if (pipe(pipes) == -1)
    {
        printerror("pipe", EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1)
    {
        printf("fork");
    }
    if (pid == 0)
    {
        close(pipes[0]);
        dup2(pipes[1], STDOUT_FILENO);
        Redirect(argv, left, flagpipe);
    }
    else if (pid > 0)
    {
        close(pipes[1]);
        dup2(pipes[0], STDIN_FILENO);
        doPipe(argv, flagpipe + 1, right);
    }
}

void Redirect(char *argv[], int left, int right)
{

    // int fdout = dup(1);
    // int fdin = dup(0);
    char *strc[MAX] = {NULL};

    for (int i = left; i < right; i++)
    {
        int fd1, fd2, fd3;
        if (strcmp(argv[i], "<") == 0) //<
        {
            fd1 = open(argv[i + 1], O_RDONLY);
            dup2(fd1, STDIN_FILENO);
            argv[i] = NULL;
            i++;
        }
        else if (strcmp(argv[i], ">") == 0) //>
        {

            fd2 = open(argv[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666); // 文件所有者、所属组和其他用户都具有读写权限
            dup2(fd2, STDOUT_FILENO);
            argv[i] = NULL;
            i++;
        }
        else if (strcmp(argv[i], ">>") == 0) //>>
        {

            fd3 = open(argv[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644); // 所有者具有读写权限，而所属组和其他用户只有读权限
            dup2(fd3, STDOUT_FILENO);
            argv[i] = NULL;
            i++;
        }
    }
    char *command[MAX];
    for (int i = left; i < right; i++)
    {
        command[i] = argv[i];
    }
    command[right] = NULL;
    execvp(command[left], command + left);

    printerror("invalid", EXIT_FAILURE);
}