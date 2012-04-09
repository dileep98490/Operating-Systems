#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{int n,l;
FILE *fp;
char command[400];//For storing the command
char buf[300];
int fd[2];
printf("Starting the piping process\n");
pipe(fd);
l=fork();
if(l==0)
{close(fd[1]);
printf("Running the child process\n");
n=read(fd[0],buf,300);
sprintf(command,"wc -l %s",buf);

system("command");

}
else if(l<0)
printf("Child cannot be created\n");
else
{close(fd[0]);
printf("Running the parent process\n");
fp=popen("ls -l","r");//For system calls reading
write(fd[1],fp,200);
printf("Wrote to the pipe\n");
}
getche();
return 0;
}

