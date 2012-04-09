#include<stdio.h>
//selection sort
#include<conio.h>
int main()
{int a[6],temp,i,n,j;
n=5;
for(i=1;i<=n;i++)
scanf("%d",&a[i]);

for(i=1;i<=n-1;i++)
for(j=i;j<=n;j++)
if(a[i]>a[j])
{temp=a[j];
a[j]=a[i];
a[i]=temp;
}
for(i=1;i<=n;i++)
printf("%d\t",a[i]);
getche();
return 0;
}
