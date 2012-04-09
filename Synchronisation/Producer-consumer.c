#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 5
typedef int buffer_item;

sem_t mutex;//semaphore mutex lock declaration
sem_init(&mutex,0,1);//Getting default attributes to mutex

int empty=0;
int full=1;
int HEAD=-1;
int TAIL=-1;
buffer_item Buffer[SIZE];

//Wait function

void wait(int flag)
{
     if(flag==0)
     {while((HEAD+1)%SIZE==TAIL)
     sleep(2);}
     else
     {while(HEAD==-1 && TAIL==-1)
     sleep(2);
     }

     }
     //Signal function

void signal(int flag)
{
     if(flag==0)
     {
                 if(HEAD==TAIL)
           {HEAD=-1;
           TAIL=-1;
           }
                      else
           TAIL=(TAIL+1)%SIZE;

                }
                else
                {
                    HEAD=(HEAD+1)%SIZE;
                       if(TAIL==-1)
      TAIL=0;
                    }


     }

     //Inserting item function for Producer thread

int insert_item(buffer_item item)
{wait(empty);
sem_wait(&mutex);
//Critical section start

Buffer[((HEAD+1)%SIZE)]=item;

      //Critical section end
      sem_post(&mutex);
      signal(full);
}

//Removing or consuming item function for consumer thread

int remove_item()
{buffer_item temp;
    wait(full);
sem_wait(&mutex);
//Critical section start
temp=Buffer[TAIL];
//Critical section end
sem_post(&mutex);
      signal(empty);
      return temp;
      }

      //Thread for Producer process
    void *producer(void *param)
    {
         buffer_item item;
         item=rand();
         insert_item(item);
         printf("Item - %d successfully produced",item);

         }


         //Thread for consumer process
    void *consumer(void *param)
    {
         buffer_item temp;
         temp=remove_item();
         printf("The item consumed successfully is %d",temp);
         }

int main()
{int i,j;
    pthread_t tid1[5],tid2[5];//Thread id's
pthread_attr_t attr;//Thread attributes

pthread_attr_init(&attr);//Setting thread attributes to their default value
printf("Enter the number of producer and consumer processes you want:");
scanf("%d%d",&i,&j);
while(i)
{pthread_create(&tid1[i],&attr,producer,i);
i--;
}
while(j)
{pthread_create(&tid2[j],&attr,consumer,i);
j--;
}
sleep(60);
}

