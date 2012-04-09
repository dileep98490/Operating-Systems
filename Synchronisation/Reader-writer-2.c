#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int mutex[3],wrt,rd;//semaphore mutex lock declaration
int readercount,writercount;
int read[6][2],write[6][2];

int p(int *mutex)
{
 while(*mutex==0)
 sleep(2);
 *mutex=0;   
    
}
int v(int *mutex)
{
    *mutex=1;
}
//Wait function
int readerwriterlockwait(char *mode)
{
                           if(mode=="write")
                           {p(&mutex[0]);//To make the below atomic and exclusive
                           writercount++;
                           if(writercount==1)//If first writer, then there is a need to check if any one is reading
                           p(&rd);
                           v(&mutex[0]);
                                 p(&wrt);//Write lock, so that when one is modifying, the other cannot touch it
                                                 }
                           else
                          { 
                               p(&mutex[1]);//To make the below atomic and exclusive
                               p(&rd);//Read lock to show that some one has started reading
                               p(&mutex[2]);//To make the below atomic and exclusive and also to avoid signal of other read to modify readercount at the same time
                               readercount++;
                               if(readercount==1)//If he is a first reader, he must make sure that no one is modifying or writing
                               p(&wrt);
                               v(&mutex[2]);
                               v(&rd);//Lock is removed before the reading process has begun because two readers can read at the same time
                               v(&mutex[1]);
                               }
                          
                           }
//Signal function    
int readerwriterlocksignal(char *mode)
{
                             if(mode=="write")
                         { v(&wrt);//Writing lock is removed
                             p(&mutex[0]);//To make the below ones atomic and exclusive
                          writercount--;
                          if(writercount==0)
                          v(&rd);//Reading lock is removed, now any one can read since no writer is modifying
                          v(&mutex[0]);
                          
                          }
                             else
                        {p(&mutex[2]);
                          readercount--;
                        if(readercount==0)
                        v(&wrt);
                        v(&mutex[2]);
                        
                             }
                        
}

//Reader thread
DWORD WINAPI Reader(LPVOID *Param)
{DWORD i=*(DWORD *)Param;
char *mode;
//Not arrived
sleep(read[i][0]*1000);
//Arrived
      mode="read";
     readerwriterlockwait(mode);
     
     //Reads the item
     sleep(read[i][1]*1000);
     //Completed reading
     readerwriterlocksignal(mode);
     printf(" Reader-%d has completed reading\n",i+1);
          
     }
     
//Writer thread
DWORD WINAPI Writer(LPVOID *Param)
{char *mode;
      DWORD i=*(DWORD *)Param;
      //Not arrived
      sleep(write[i][0]*1000);
      //Arrived
      mode="write";
readerwriterlockwait(mode);

//Modifies an item
     sleep(write[i][1]*1000);
//Completed modifying

readerwriterlocksignal(mode);
 printf(" Writer-%d has completed modifying\n",i+1);
}

int main()

{readercount=0;
writercount=0;

mutex[0]=1;
mutex[1]=1;
mutex[2]=1;
wrt=1;
rd=1;
int l;
int Param[6];
  DWORD ThreadId[6];
int i,j;
int readcount,writecount;
//Reader input start
printf("Enter the number of readers:");
scanf("%d",&readcount);
printf("Enter the arrival time and reading time of %d readers\n",readcount);
for(i=0;i<readcount;i++)
for(j=0;j<2;j++)
scanf("%d",&read[i][j]);
//Reader input end
//Writer input start
printf("Enter the number of writers:");
scanf("%d",&writecount);
printf("Enter the arrival time and writing time of %d writers\n",writecount);
for(i=0;i<writecount;i++)
for(j=0;j<2;j++)
scanf("%d",&write[i][j]);
//Writer input end
 HANDLE ThreadHandleReader[6];
   
  l=readcount-1;
    while(l!=-1)
    {Param[l]=l;

    ThreadHandleReader[l]=CreateThread(NULL,0,Reader,&Param[l],0,&ThreadId[l]);
    l--;
}

 HANDLE ThreadHandleWriter[6];

    l=writecount-1;
    while(l!=-1)
    {Param[l]=l;

    ThreadHandleWriter[l]=CreateThread(NULL,0,Writer,&Param[l],0,&ThreadId[l]);
    l--;
}
getche();   
}
