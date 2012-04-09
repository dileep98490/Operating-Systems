#include<stdio.h>
#define SIZE 3
int full=0;//To check whether all frames are filled
int a[21];//To take the input
int ref[SIZE];
char r=1;
 
int frame[SIZE];
unsigned char addref[SIZE]={0};
int repptr=0;
int count=0;
int display()
{int i;
printf("\nThe elements in the frame are\n");
for(i=0;i<full;i++)
printf("%d\n",frame[i]);
    
    
    
}
//For showing bits
int bitrep(char f)//Program for showing the bits
{char p,fl;
int j;
 char i=1;
 for(j=7;j>=0;j--)
 {p=i<<j;
 fl=p&f;
 if(fl==0)
 printf("0");
 else
 printf("1");
}
  printf("\n");  
    
    
}
//For showing bit wise

int additionalreference()
{
 int i,min;

 
 min=0;
 for(i=1;i<SIZE;i++)
 if(addref[min]>addref[i])//Finding the smallest decimal value from all the strings available
 min=i;
 repptr=min;
 return repptr;
    
    
    
}
    

int Pagerep(int ele)
{
 int temp;
repptr=additionalreference();                   
 temp=frame[repptr];
 frame[repptr]=ele;
 ref[repptr]=1;

 return temp;   
}
int Pagefault(int ele)
{if(full!=SIZE)
{ref[full]=1;
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
 {   flag=1;ref[i]=1;
    break;
}}
 return flag;   
}
int main()
{int n,i,k;
r=r<<7;
bitrep(r);
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
                      printf("\nThe values in shift registers related to three frames are\n");  
                  
                  
                  //Shifing of registers
                    for(k=0;k<SIZE;k++)
                    {
                                       addref[k]=addref[k]>>1;//Shifting all the shift registers by one bit
          
                    if(ref[k]==1)
                    { addref[k]=(r|addref[k]);//Bit OR operation for shifting
                    ref[k]=0;
                    }
                    
              
    bitrep(addref[k]);
                  
          
                     }
                    //End of shifting
                    
                    
                    }
                    printf("\nThe number of page faults are %d\n",count);
                    getche();
return 0;
}
    
    
