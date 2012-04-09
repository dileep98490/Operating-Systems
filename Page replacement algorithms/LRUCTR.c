#include<stdio.h>
#define SIZE 3
int full=0;//To check whether all frames are filled
int a[21],n;//To take the input
int frame[SIZE];
int ctr[SIZE]={0};
static int f=0;//This is a counter that keeps track of current time
int repptr;
int count=0;
int display()
{int i;
printf("\nThe elements in the frame are\n");
for(i=0;i<full;i++)
printf("%d\n",frame[i]);
    
    
    
}
int Longestopt()//Fucntion for discivering the least recently used page using their corresponding counter values
{int i,min;
    min=0;
    for(i=0;i<SIZE;i++)
    if(ctr[min]>ctr[i])
    min=i;
    
    repptr=min;
return repptr;

}
int Pagerep(int ele)
{
 int temp;
 repptr=Longestopt();//Gets the LRU page from a function
 temp=frame[repptr];
 frame[repptr]=ele;
 ctr[repptr]=f;//When ever a page is brought it's counter is kept as per the current time of use
 

 return temp;   
}
int Pagefault(int ele)
{if(full!=SIZE)
{ctr[full]=f;//Setting the counter as per current time of use
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
 {   flag=1;ctr[i]=f;//If page fault doesn't occur, but the element is referenced, it's counter is set to the current time of use
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
    {f++;//Time of use is incremented
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
    
    
