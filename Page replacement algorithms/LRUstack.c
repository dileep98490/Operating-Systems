#include<stdio.h>
#define SIZE 3
int full=0;//To check whether all frames are filled
int a[21],n;//To take the input
int frame[SIZE];
int stk[SIZE];//Stack for storing the page numbers as per their reference criteria

int repptr;
int count=0;
int display()
{int i;
printf("\nThe elements in the frame are\n");
for(i=0;i<full;i++)
printf("%d\n",stk[i]);
    
    
    
}
/* A function for removing the referenced element from the stack and keeping it in the top, while moving all
the elements up or down corresepondingly*/
int LRstackopt(int p)//The input to this function is the referenced page
{int temp;
int i;
for(i=0;i<n;i++)
if(stk[i]==p)
break;
temp=stk[i];//Storing the referenced value in temp
while(i!=SIZE-1)//Moving the other elements so that the TOP is empty
{stk[i]=stk[i+1];i++;
}
stk[i]=temp;//Storing the element in the TOP from temp





}
int Pagerep(int ele)
{
 int temp;
 
 repptr=stk[0];//Always the victim page is selected as the first element of stack

 temp=frame[repptr];
 frame[repptr]=ele;
 LRstackopt(repptr);//Now the page that is brought is the latest referenced one, so it is moved to TOP
 
 return temp;   
}
int Pagefault(int ele)
{if(full!=SIZE)
{stk[full]=full;//First stack is populated till all the pages are full
               frame[full++]=ele;}
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
 {   flag=1;LRstackopt(i);//When ever reference is made, but pae fault doesn't occur, the referenced page is moved to TOP
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
                  
                    count++;
                    }
                      display();
                    }
                    printf("\nThe number of page faults are %d\n",count);
                    getche();
return 0;
}
    
    
