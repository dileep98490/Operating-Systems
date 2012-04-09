#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{int n,l;
char buf[100];
int fd[2];
printf("Starting the piping process\n");
pipe(fd);
l=fork();
if(l==0)
{close(fd[1]);
printf("Running the child process\n");
n=read(fd[0],buf,100);
printf("The value of n is:%d\n",n);
printf("The value received is\n%s\n",buf);
}
else if(l<0)
printf("Child cannot be created\n");
else
{close(fd[0]);
printf("Running the parent process\n");

write(fd[1],"I am a good boy\n",16);
printf("Wrote to the pipe\n");
}
getche();
return 0;
}

