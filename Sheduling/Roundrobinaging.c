#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{FILE *fp;
    int i,n,fl,k,j,min,temp,MT=0,sw=0,flag,fl1;
float AV_WT,AV_TA;
char pro_name[20][10],tempch[10];
int e[20],w[20],ta[20],a[20],l[20],ex[20],ts,tsa,pre,ag;
fp=fopen("Input.txt","r");
printf("Enter the number of processes:\n");
fscanf(fp,"%d",&n);
for(i=0;i<n;i++)
l[i]=0;
printf("Enter the name of process, it's arrival time and it's execution time, side by side as per the order they arrived:\n");
for(i=0;i<n;i++)
fscanf(fp,"%s%d%d",&pro_name[i],&a[i],&e[i]);
//
fclose(fp);
for(i=0;i<n;i++)
{sw=0;
for(j=1;j<n-i;j++)
{if(a[j]<a[i])
{temp=a[j];
a[j]=a[i];
a[i]=temp;
//
strcpy(tempch,pro_name[j]);
strcpy(pro_name[j],pro_name[i]);
strcpy(pro_name[i],tempch);
//
temp=e[j];
e[j]=e[i];
e[i]=temp;
sw=sw+1;}
}
if(sw==0)
break;
}
//
printf("The processes you entered after sorting are:\nName\tArr_time\tExec_time\n");
for(i=0;i<n;i++)
printf("%s\t%d\t%d\n",pro_name[i],a[i],e[i]);
//
for(i=0;i<n;i++)
l[i]=0;
//To find maximum solution
ag=18;
e[ag]=1;
for(i=0;i<n;i++)
if(e[i]>e[ag])
ag=i;
//
for(i=0;i<n;i++)
ex[i]=e[i];

AV_WT=0;
AV_TA=0;
//Roundrobin start

ts=2;
fl=1;
MT=0;
tsa=ts;
pre=ts;
while(fl)
{fl=0;
for(i=0;i<n;i++)
{if(l[i]!=1)
{if(MT>a[i])
{fl1=0;
            if(i==ag)
{if(e[i]>tsa)
{fl1=1;
           MT=MT+tsa;
e[i]=e[i]-tsa;
         printf("\nThe process executed just is %s",pro_name[i]); }}
          else
          {
           if(e[i]>ts)
{fl1=1;
           MT=MT+ts;
e[i]=e[i]-ts;
printf("\nThe process executed just is %s",pro_name[i]);}}



if(fl1!=1)
{
    MT=MT+e[i];
    w[i]=MT-a[i]-ex[i];
ta[i]=w[i]+ex[i];
AV_WT=AV_WT+w[i];
AV_TA=AV_TA+ta[i];

l[i]=1;
printf("\nThe process executed just is %s",pro_name[i]);
}}
else
{fl1=0;
    if(i==ag)
{if(e[i]>tsa)
         {fl1=1;
             MT=a[i]+tsa;
e[i]=e[i]-tsa; 
          printf("\nThe process executed just is %s",pro_name[i]);
          }}
else
    {if(e[i]>ts)
{fl1=1;
MT=a[i]+ts;
e[i]=e[i]-ts;
printf("\nThe process executed just is %s",pro_name[i]);}}
if(fl1!=1)
{
    MT=a[i]+e[i];
w[i]=MT-a[i]-ex[i];
ta[i]=w[i]+ex[i];
AV_WT=AV_WT+w[i];
AV_TA=AV_TA+ta[i];
l[i]=1;
printf("\nThe process executed just is %s",pro_name[i]);
}}}

}
for(j=0;j<n;j++)
if(l[j]==0)
fl=1;
tsa=2*pre+tsa;
pre=2*pre;

}




















//Round Robin end
AV_WT/=n;
AV_TA/=n;


printf("\nThe processes you entered along with waiting times and turn around times are:\n");
printf("Process name   Exectime   Waitingtime   Turnaroundtime\n");
for(i=0;i<n;i++)
                printf("%s\t\t\t%d\t%d\t%d\n",pro_name[i],e[i],w[i],ta[i]);


printf("The Final time after execution is %d\n\nThe avarage waiting time is %f\n\nThe avarage turn around time is %f\n",MT,AV_WT,AV_TA);





getche();
         return 0;}




