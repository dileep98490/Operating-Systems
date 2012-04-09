#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{FILE *fp;
    int i,n,TET,temp,j;
float AV_WT,AV_TA;
char pro_name[20][10],tempch[10];
int e[20],w[20],ta[20],a[20],sw;
fp=fopen("Input.txt","r");
printf("Enter the number of processes:\n");
fscanf(fp,"%d",&n);
printf("Enter the name of process, it's arrival time and it's execution time, side by side :\n");
for(i=0;i<n;i++)
fscanf(fp,"%s%d%d",&pro_name[i],&a[i],&e[i]);
fclose(fp);
//

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

w[0]=0;
AV_WT=0;
ta[0]=e[0];
AV_TA=ta[0];
for(i=1;i<n;i++)
{
if(a[i]>(a[i-1]+e[i-1]+w[i-1]))
w[i]=0;
else
w[i]=a[i-1]+e[i-1]+w[i-1]-a[i];

AV_WT=AV_WT+w[i];
ta[i]=w[i]+e[i];
AV_TA=AV_TA+ta[i];

}
AV_WT/=n;
AV_TA/=n;
TET=w[i-1]+e[i-1]+a[i-1]-a[0];



printf("The processes you entered along with waiting times and turn around times are:\n");
printf("Process name   Exectime   Waitingtime   Turnaroundtime\n");
for(i=0;i<n;i++)
                printf("%s\t\t\t%d\t%d\t%d\n",pro_name[i],e[i],w[i],ta[i]);


printf("The total execution time is %d\n\nThe avarage waiting time is %f\n\nThe avarage turn around time is %f\n",TET,AV_WT,AV_TA);
getche();
return 0;
}


