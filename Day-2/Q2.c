#include<stdio.h>
int main()
{int fd[2];
int n,i,l,a[1];
if(fork()==0)
{read(fd[0],a,1);
a[0]++;printf("%d\n",a[0]);
write(fd[1],a,1);
exit(0);
}
else
{
printf("Enter the number of processes you want:");
scanf("%d",&n);
printf("Enter the number to be incremented:");
scanf("%d",&a[0]);
read(fd[0],a,1);
write(fd[1],a,1);
exit(0);
}

for(i=0;i<n-1;i++)
{l=fork();
if(l==0)
{read(fd[0],a,1);
a[0]++;
write(fd[1],a,1);
exit(0);
}
}
if(i==n)
{read(fd[0],a,1);
printf("%d",a);
exit(0);
}
return 0;
}

