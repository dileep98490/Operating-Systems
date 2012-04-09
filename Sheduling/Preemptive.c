#include<stdio.h>
#include<string.h>
#include<conio.h>
int main()
{FILE *fp;
    int i,n,fl,k,j,min,temp,MT=0,sw=0,flag,t;
float AV_WT,AV_TA;
char pro_name[20][10],tempch[10];
int e[20],w[20],ta[20],a[20],l[20],ex[20],pr[20];
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
for(i=0;i<n;i++)
ex[i]=e[i];


AV_WT=0;
AV_TA=0;
for(i=0;i<n;i++)
if(a[i]<a[i+1])
break;
i=i+1;
fl=1;
while(fl)
{fl=0;
//



//
e[18]=10000;
min=18;
//To find the minimum element
for(j=0;j<i;j++)
if(l[j]!=1)
{if(e[j]<e[min])
min=j;}

//


flag=1;
while(i<=n)
{flag=0;
//printf("\n%d\t%d\n",MT,a[i]);
          if(MT+e[min]>a[i])
          {flag=1;i++;}
else
break;
if(flag==1)
//
{
           if(a[min]<MT)
{
              e[min]=e[min]-a[i-1]+MT;

MT=a[i-1];

}
else
{
   e[min]=e[min]-a[i-1]+a[min];
pr[min]=a[i-1]-a[min];
MT=a[i-1];

}

printf("\nThe process executed just is %s",pro_name[min]);
         e[18]=10000;
min=18;
         for(j=0;j<i;j++)
if(l[j]!=1)
{if(e[j]<e[min])
min=j;}

//printf("\n%d",e[min]);

}}//
if(flag==0)
{
           if(a[min]<MT)
{MT=MT+e[min];
}
else
{MT=a[min]+e[min];
}

}
printf("\nThe process completed just is %s",pro_name[min]);
l[min]=1;
w[min]=MT-a[min]-ex[min];
ta[min]=w[min]+ex[min];
AV_WT=AV_WT+w[min];
AV_TA=AV_TA+ta[min];



/*for(j=0;j<i;j++)
if(l[j]==0)
{fl=1;break;}
*/


//


for(i=0;i<n;i++)
if(l[i]!=1)
if(a[i]>MT)
break;
//

for(j=0;j<n;j++)
if(l[j]==0)
{fl=1;break;}


}
AV_WT/=n;
AV_TA/=n;


printf("\nThe processes you entered along with waiting times and turn around times are:\n");
printf("Process name   Exectime   Waitingtime   Turnaroundtime\n");
for(i=0;i<n;i++)
                printf("%s\t\t\t%d\t%d\t%d\n",pro_name[i],e[i],w[i],ta[i]);


printf("The Final time after execution is %d\n\nThe avarage waiting time is %f\n\nThe avarage turn around time is %f\n",MT,AV_WT,AV_TA);





getche();
         return 0;}




