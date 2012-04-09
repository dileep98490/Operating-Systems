#include<stdio.h>
#include<sys/types.h>
main()
{int pid;

printf("The process id of the parent process is %d\n",getpid());
pid=fork();
if(pid==0)
printf("The process id of the child process is %d\n",getpid());
else if(pid<0)
printf("Sorry, couldn't create the child process");
else
printf("The process id of parent process is %d\n",getpid());


}

