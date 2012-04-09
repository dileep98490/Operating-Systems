#include<stdio.h>
 int i=0;
int SIZE=10;
int HEAD=-1;
int TAIL=-1;
int a[10];
int mutex=0;
int callp=-1;
int callc=-1;
int prod=0;
int cons=0;
int pr=0;
int cs=0;

                    int switchtoconsumer()
{
    int sw;
    if(callp==-1)
    callp=0;
    printf("\nDo you wanna switch to consume : 1.Yes\t2.No:");
scanf("%d",&sw);
if(sw==1)
{if(callp==1)
{
callc=0;
return 1;}
else
{
         callp=1;
         if(callc==1)
return 1;
else
   {            
               if(cs==0)
              cs=1;
             consumer();
               }
               
 }        }
 return 0;

}
                int switchtoproducer()
{
    int sw;
    if(callc==-1)
    callc=0;
     printf("\nDo you wanna switch to produce : 1.Yes\t2.No:");
scanf("%d",&sw);

if(sw==1)
{if(callc==1)
{
callc=0;
return 1;
}
else
{  callc=1;
if(callp==1)
return 1;
else
{
if(pr==0)
pr=1;
producer();

}      
 }
         }
         return 0;
}
 
                            int producer()
{i=i+1;
int sw;
if(pr==1)
{
if((HEAD+1)%SIZE==TAIL)
printf("\nThe buffer is full, cannot insert");
else
printf("\nItem produced and Buffer is not full");

pr=2;
if(cons!=-1)
{if(switchtoconsumer()==1)
return 0;}
 else
          printf("\nNo need to switch");


}
if(pr==2)
{
printf("\nProducing the item");
if(mutex!=1)
{mutex=1;
HEAD=(HEAD+1)%SIZE;
a[HEAD]=i;
      if(TAIL==-1)
      TAIL=0;
      }
      else
      printf("\nSemaphore is set, cannot produce");
            mutex=0;
            pr=3;
           
     if(cons!=-1)
      {if(switchtoconsumer()==1)
      return 0;}
       else
          printf("\nNo need to switch");
      }
      
   
      return 1;
      }
                               int consumer()
                                   {int sw;
               int temp;
               if(cs==1)
               {
               if(HEAD==-1&&TAIL==-1)
           printf("\nThe buffer is empty cannot consume");
           else
           printf("\nThe buffer is not empty and can consume");
           cs=2;
           if(prod!=-1)
          {if(switchtoproducer()==1)
          return 0;}
         else
          printf("\nNo need to switch");
          }
          if(cs==2)
          {
          printf("\nConsuming the item");
           if(mutex!=1)
           {mutex=1;
           temp=a[TAIL];
           if(HEAD==TAIL)
           {HEAD=-1;
           TAIL=-1;
           }
           else
           TAIL=(TAIL+1)%SIZE;
           }
           else
      printf("\nSemaphore is set, cannot consume");
      
           mutex=0;
           cs=3;
           if(prod!=-1)
          {if( switchtoproducer()==1)
          return 0;}
           else
          printf("\nNo need to switch");
}
         
           return 1;
           }

int main()
{int l=3;
int k;
while(l)
{printf("\nEnter what you wanna do\n0.Exit\t1.Produce\t2.Consume\n");
scanf("%d",&l);
switch(l)
{case 1:while(1)
{
      pr=1;
      if(producer()==1)
printf("\nItem produced");
printf("\nProduce one more:1.Yes\t:");
scanf("%d",&k);
if(k==1)
continue;
prod=-1;
callp=-1;
if(callc!=-1||cons!=0)
consumer();
prod=0;
if(k!=1)
break;
}
break;
case 2:while(1)
{
     cs=1;
     if(consumer()==1)
printf("\nItem consumption process over");
printf("\nConsume one more:1.Yes\t:");
scanf("%d",&k);
if(k==1)
continue;
callc=-1;
cons=-1;
if(callp!=-1||prod!=0)
producer();
cons=0;
if(k!=1)
break;
}
break;
}
}


return 0;         
         }
