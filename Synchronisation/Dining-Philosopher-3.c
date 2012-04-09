/*
  Name: Dining Philosopher-3
  Copyright: 
  Author: Dileep kumar
  Date: 21/03/11 21:49
  Description: This is the solution for dining philosopher problem in which the odd philosopher always picks up his left chop stick fist 
  and then his right chop stick and vice versa for an ven philosopher
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

HANDLE Chopstick[5];
int l;
int TE[5][2];

DWORD WINAPI Eat(LPVOID *Param)
{DWORD i=*Param;
//Thinking
sleep(TE[i][0]*1000);
if(i%2==1)
{
WaitForSingleObject(Chopstick[i],INFINITE);
WaitForSingleObject(Chopstick[(i+1)%5],INFINITE);
}
else
{WaitForSingleObject(Chopstick[(i+1)%5],INFINITE);
    WaitForSingleObject(Chopstick[i],INFINITE);

}
//Eating
sleep(TE[i][1]*1000);
ReleaseSemaphore(Chopstick[i],1,NULL);
ReleaseSemaphore(Chopstick[(i+1)%5],1,NULL);
printf("Philosopher %d has completed eating\n",*(DWORD*)Param+1);


return 0;
}

int main()
{int i,j;
    l=4;
    while(l!=-1)
{Chopstick[l]=CreateSemaphore(NULL,1,1,NULL);
l--;
}

printf("Enter the values of thinking and eating for five philosophers:\n");
for(i=0;i<5;i++)
for(j=0;j<2;j++)
scanf("%d",&TE[i][j]);



    HANDLE ThreadHandle[5];
    DWORD ThreadId[5];
    int Param[5];
    l=4;
    while(l!=-1)
    {Param[l]=l;

    ThreadHandle[l]=CreateThread(NULL,0,Eat,&Param[l],0,&ThreadId[l]);
    l--;
}
l=4;
while(l!=-1)
{
        if(ThreadHandle[l]!=NULL)
        {WaitForSingleObject(ThreadHandle[l],INFINITE);
         
        CloseHandle(ThreadHandle[l]);
     
        }
       
       
         l--;
         } 



getche();
         return 0;
         }
