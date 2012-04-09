#include<stdio.h>
#define SIZE 3
int full=0;//To check whether all frames are filled
int a[21];//To take the input of reference string

int frame[SIZE];//This is for frames
int repptr=0;//The pointer for the page that needs to be replaced
int count=0;//For counting number of page faults
int display()//To display the elements of the frame
{int i;
printf("\nThe elements in the frame are\n");
for(i=0;i<full;i++)
printf("%d\n",frame[i]);
    
    
    
}
int Pagerep(int ele)
{
 int temp;
                    
 temp=frame[repptr];
 frame[repptr]=ele;
 repptr++;//The pointer moves to the next frame since the current frame became the newest
  if(repptr==SIZE)
 repptr=0;

 return temp;   //Returns the victim page
}
int Pagefault(int ele)
{if(full!=SIZE)
               frame[full++]=ele;//Untill all the frames fill, there is no call for page replacement

else
printf("The page replaced is %d",Pagerep(ele));//Displaying of victim page
}
int Search(int ele)//This would search and return the flag that tells whether the page is already present in the frame or not
{int i,flag;
    flag=0;
    if(full!=0)
    {
    for(i=0;i<full;i++)
    if(ele==frame[i])
 {   flag=1;
    break;
}}
 return flag;   
}
int main()
{int n,i;
    FILE *fp;//For taking input from a file
    //Start
    fp=fopen("Input.txt","r");
    printf("The number of elements in the reference string are :");
    fscanf(fp,"%d",&n);
    printf("%d",n);
    for(i=0;i<n;i++)
    fscanf(fp,"%d",&a[i]);
    fclose(fp);
    printf("\nThe elements present in the string are\n");
    for(i=0;i<n;i++)
    printf("%d  ",a[i]);
    printf("\n\n");
    //End
    for(i=0;i<n;i++)
    {
                    if(Search(a[i])!=1)
                    {Pagefault(a[i]);
                    display();
                    count++;
                    }
                    
                    }
                    printf("\nThe number of page faults are %d\n",count);
                    getche();//For waiting
return 0;
}
    
    
