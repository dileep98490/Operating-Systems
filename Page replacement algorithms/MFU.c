#include<stdio.h>
#define SIZE 3
int full=0;//To check whether all frames are filled
int a[21],n;//To take the input
int frame[SIZE];
int ctr[SIZE]={0};
static int f;
int repptr;
int count=0;
int display()
{int i;
printf("\nThe elements in the frame are\n");
for(i=0;i<full;i++)
printf("%d\n",frame[i]);
      
}
int Longestopt()
{int i,max;
    max=0;//The increment of counter value here is same as that for of LFU
    for(i=0;i<SIZE;i++)//The page with maximum frequency is selected
    if(ctr[max]<ctr[i])
    max=i;
    
    repptr=max;
return repptr;

}
int Pagerep(int ele)
{
 int temp;
 repptr=Longestopt();
 temp=frame[repptr];
 frame[repptr]=ele;
 ctr[repptr]=1;
 

 return temp;   
}
int Pagefault(int ele)
{if(full!=SIZE)
{ctr[full]++;
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
 {   flag=1;ctr[i]++;
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
    {f=i;
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
    
    
