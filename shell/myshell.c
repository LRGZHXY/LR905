#include <stdio.h>
#include <signal.h> //SIGINT  SIGHUP
#include <string.h>
#include <unistd.h> //getlogin gethostname getcwd
#include <sys/types.h> //pid_t
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <sys/wait.h>//waitpid


#define true 1
#define MAX 128

void ignore();                        // 设置屏蔽信号
void printInfo();                     // 打印信息
void splitCmd(char *cmd);             // 分割命令
void analysecmd(char*argv[],int num);
int dealCmd(char *argv[], int count); // 处理命令
int executeCmd(char*argv[]);
void do_cd(char *argv[]);
void printerror(char *error, int num);
//void Redirect_In(char*argv[]);//
// void Redirect_Out(char*argv[]);//
// void Redirect_AddOut(char*argv[]);//
void Redirect(char*argv[],int count);
void doPipe(char*argv[]);//

char *argv[MAX] = {NULL};
int back = 0;

int main()
{
    ignore();

    while (true)
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
            splitCmd(cmd);
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
    printf("\033[35m%s\033[0m"," $ ");

    fflush(stdout);
}

void splitCmd(char *cmd)
{
    const char *sign = " ";
    int count = 1;
    argv[0] = strtok(cmd, sign);
    while (argv[count] = strtok(NULL, sign))
    {
        count++;
    }
    analysecmd(argv,count);
}

void analysecmd(char*argv[],int num)
{
    int flag=dealCmd(argv,num);
    if(back==1)
    {
        num--;
    }
    // if(flag==1)
    // {
    //     Redirect_In(argv);
    // }
    // else if (flag==2)
    // {
    //     Redirect_Out(argv);
    // }
    // else if(flag==3)
    // {
    //     Redireect_AddOut(argv);
    // }
    else if(flag==4)
    {
        doPipe(argv);
    }
    else if(flag==5)
    {
        executeCmd(argv);
    }
}

int dealCmd(char *argv[], int count)
{
    int flag = 5;

    if (argv[0] == NULL)
    {
        return 0;
    }

    if (strcmp(argv[0], "cd") == 0)
    {
        do_cd(argv);
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(argv[i], "&") == 0)
        {
            back = 1;
            argv[i] = NULL;
            break;
        }
        // if (strcmp(argv[i], "<") == 0)
        //     flag = 1;
        // if (strcmp(argv[i], ">") == 0)
        //     flag = 2;
        // if (strcmp(argv[i], ">>") == 0)
        //     flag = 3;
        if (strcmp(argv[i], "|") == 0)
            flag = 4;
    }
    return flag;
}

int executeCmd(char*argv[])
{
    pid_t pid=fork();
    if(pid==-1)
    {
        printerror("forkerror",1);
    }
    else if(pid==0)//子进程
    {
        execvp(argv[0],argv);
        //printerror("pserror",2);
    }
    else if(pid>0)//父进程
    {
        if(back==1)
        {
            back=0;
            return 0;
        }
        waitpid(pid,NULL,0);//参数 0 表示等待子进程完成的行为为阻塞，即父进程将一直等待，直到指定的子进程结束
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
    else if(strcmp(argv[1], "~") == 0)
    {
        char dir[20];
        sprintf(dir,"/home/%s",getlogin());
        chdir(dir);
    }
    else
    {
        if (chdir(argv[1]) == -1)
        {
            printerror("opendir error", 1);
        }
    }

    setenv("OLDPWD", curPath, 1);
}

void Redirect(char*argv[],int count)
{

}

void doPipe(char*argv[])
{
    
}