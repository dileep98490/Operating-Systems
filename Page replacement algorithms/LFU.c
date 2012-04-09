#include<stdio.h>
#define SIZE 3
int full=0;//To check whether all frames are filled
int a[21],n;//To take the input
int frame[SIZE];
int ctr[SIZE]={0};//Counter to know the frequency, intially all have zero frequency of use

int repptr;
int count=0;
int display()
{int i;
printf("\nThe elements in the frame are\n");
for(i=0;i<full;i++)
printf("%d\n",frame[i]);
    
    
    
}
int Longestopt()
{int i,min;
    min=0;
    for(i=0;i<SIZE;i++)//The page with least frequency is selected as victim
    if(ctr[min]>ctr[i])
    min=i;
    
    repptr=min;
return repptr;

}
int Pagerep(int ele)
{
 int temp;
 repptr=Longestopt();//The victim page is selected with the help of a function
 temp=frame[repptr];
 frame[repptr]=ele;
 ctr[repptr]=1;//A new page is brought, hence it's counter is set to 1
 

 return temp;   
}
int Pagefault(int ele)
{if(full!=SIZE)
{ctr[full]++;//The counters will increase initially for all frames till they are full
               frame[full++]=ele;
}
else
printf("The page replaced is %d",Pagerep(ele));
}
int Search(int ele)
{int i,flag;
    flag=0;
    if(full!=0)
    {
    for(i=0;i<full;i++)
    if(ele==frame[i])
 {   flag=1;ctr[i]++;//Whenever a reference is made the counter is incremented
    break;
}}
 return flag;   
}
int main()
{int i;
    FILE *fp;
    fp=fopen("Input.txt","r");
    printf("The number of elements in the reference string are :");
    fscanf(fp,"%d",&n);
    printf("%d",n);
    for(i=0;i<n;i++)
    fscanf(fp,"%d",&a[i]);
    printf("\nThe elements present in the string are\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
                    if(Search(a[i])!=1)
                    {Pagefault(a[i]);
                    display();
                    count++;
                    }
                    
                    }
                    printf("\nThe number of page faults are %d\n",count);
                    getche();
return 0;
}
    
    
