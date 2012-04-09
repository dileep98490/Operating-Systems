#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int mutex;//semaphore mutex lock declaration
int i=0;

char *mode;

//Wait function
int readerwriterlockwait(char *mode)
{
                           if(mode=="write")
                           {while(i!=0)
                           sleep(2);
                           sem_wait(&mutexwrite);
                                                      }
                           else
                          { while(!sem_post(&mutex))
                           sleep(2);
                         i++;
                           }
                           }
//Signal function    
int readerwriterlocksignal(char *mode)
{
                             if(mode=="write")
                             sem_post(&mutex);
                             else
                           i--;
}

//Reader thread
void *reader(void *param)
{mode="read"
     readerwriterlockwait(&mode);
     
     //Reads the item
     
     readerwriterlocksignal(&mode);
          
     }
     
//Writer thread
void *writer(void *param)
{mode="write";
readerwriterlockwait(&mode);

//Modifies an item

readerwriterlocksignal(&mode);
}

int main()

{
    int i,j;
    pthread_t tid1[5],tid2[5];//Thread id's
pthread_attr_t attr;//Thread attributes

pthread_attr_init(&attr);//Setting thread attributes to their default value
printf("Enter the number of reader and Writer processes you want:");
scanf("%d%d",&i,&j);
while(i)
{pthread_create(&tid1[i],&attr,reader,'c');
i--;
}
while(j)
{pthread_create(&tid2[j],&attr,writer,'c');
j--;
}
sleep(60);   
}
