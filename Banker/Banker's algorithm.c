#include<stdio.h>
int main()
{FILE *fp;
int i,j;
char temp1[10];
fp=fopen("banker.txt","r");
int max[5][5],allo[5][5],need[5][5];//For the processes sake to give maximum, allocated and needed resources
int avai[3];//Available resources
fscanf(fp,"%s",temp1);//Reading from file
printf("%s\n",temp1);
printf("\n");
for(i=0;i<3;i++)
{fscanf(fp,"%s",temp1);
avai[i]=atoi(temp1);
printf("%d\t",avai[i]);
}
printf("\n");
printf("\n");
//For maximum resources start
fscanf(fp,"%s",temp1);//Reading from file
printf("%s\t",temp1);
fscanf(fp,"%s",temp1);//Reading from file
printf("%s\n",temp1);
printf("\n");
for(i=0;i<5;i++)
{for(j=0;j<3;j++)
{fscanf(fp,"%s",temp1);
max[i][j]=atoi(temp1);
printf("%d\t",max[i][j]);
}
printf("\n");}
//Maximum rexsources end
printf("\n\n");
//Allocated resouces start
fscanf(fp,"%s",temp1);//Reading from file
printf("%s\t",temp1);
fscanf(fp,"%s",temp1);//Reading from file
printf("%s\n",temp1);
printf("\n");
for(i=0;i<5;i++)
{for(j=0;j<3;j++)
{fscanf(fp,"%s",temp1);
allo[i][j]=atoi(temp1);
printf("%d\t",allo[i][j]);
}
printf("\n");}
//Allocated resources end
//Needed resources start
printf("\n\n");
printf("Needed Resources\n\n");
for(i=0;i<5;i++)
{for(j=0;j<3;j++)
{
need[i][j]=max[i][j]-allo[i][j];
printf("%d\t",need[i][j]);
}
printf("\n");}
//Needed resources end
//Making the available resources apt
for(j=0;j<3;j++)
for(i=0;i<5;i++)
avai[j]=avai[j]-allo[i][j];
printf("\n");
printf("The available resources at present are:\n");
printf("\n");
for(j=0;j<3;j++)
printf("%d\t",avai[j]);
printf("\n\n");



//End of making available resources apt
//Input start
int id,req[5][3];
printf("Enter the process id number:");
scanf("%d",&id);
printf("Enter the three resources");
scanf("%d%d%d",&req[id][0],&req[id][1],&req[id][2]);
//Input end
//Solution start
int Fin[5];
for(i=0;i<5;i++)
Fin[i]=0;
//Consider the resources are allocated
printf("\nAfter allocating the resources to p-%d the available resources are\n",id);
for(j=0;j<3;j++)
{avai[j]=avai[j]-req[id][j];
allo[id][j]=allo[id][j]+req[id][j];
need[id][j]=max[id][j]-allo[id][j];
printf("%d\t",avai[j]);
}
printf("\n");
//End of consideration
//Checking for safe/Unsafe state
while(1)
{for(i=0;i<5;i++)
{if(Fin[i]==0&&need[i][0]<=avai[0]&&need[i][1]<=avai[1]&&need[i][2]<=avai[2])
break;
}

if(i==5)
break;


for(j=0;j<3;j++)
avai[j]=avai[j]+allo[i][j];
Fin[i]=1;

printf("\nThe process finished is p-%d",i);
}
//End of checking
//Checking for finish of all
for(i=0;i<5;i++)
if(Fin[i]==0)
break;
if(i==5)
printf("\nThe allocation is safe\n");
else
printf("\nThe allocation is unsafe\n");
//End of checking


//Solution end


getche();}
