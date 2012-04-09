/*
  Name: Dining Philospher
  Copyright: 
  Author: 
  Date: 21/03/11 21:52
  Description: In this the philosopher grabs the left chopstick first and then the right chopstick and then proceeds for eating
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

int Chopstick[5];//Each chopstick is a semaphore
//If chopstick=1, the chopstick is free, otherwise someone grabbed it
int l;
int TE[5][2];//For storing the eating and thinking time of philosophers

Wait(int i)
{
      while(1)
      {while(Chopstick[i]==0)//He goes on checking for left chopstick
      sleep(2);
      Chopstick[i]=0;//Immediately grabs the left chopstick
   
      if(Chopstick[(i+1)%5]==0)//If right chopstick found he breaks
      break;
      Chopstick[i]=1;//Otherwise he will release the left chopstick and again goes back
 
      }
    
  Chopstick[(i+1)%5]=0; //Right chopstick is also grabbed
      
      }
Signal(int i)
{Chopstick[i]=1;
Chopstick[(i+1)%5]=1;
}


DWORD WINAPI Eat(LPVOID *Param)
{DWORD i=*Param;
//Thinking
sleep(TE[i][0]*1000);
//End of thinking time
Wait(i);

//Eating
sleep(TE[i][1]*1000);
//Eating over
Signal(i);

printf("Philosopher %d has completed eating\n",*(DWORD*)Param+1);


return 0;
}

int main()
{int i,j;
    l=4;
    while(l!=-1)
{Chopstick[l]=1;
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



getche();
         return 0;
         }
