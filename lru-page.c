#include<stdio.h>
#include<conio.h>
#define high 37
void main()
{
int fframe[10],used[10],index;
int count,n1,k,nf,np=0,page[high],tmp,i;
int flag=0,pf=0;
printf("Enter no. of frames:");
scanf("%d",&nf);
for(i=0;count<nf;count++)
fframe[count]=-1;
printf(" lru page replacement algorithm in c ");
printf("Enter pages (press -999 to exit):\n");
for(count=0;count<high;count++)
{
scanf("%d",&tmp);
if(tmp==-999) break;
page[count]=tmp;
np++;
}
for(count=0;count<np;count++)
{
flag=0;
for(n1=0;n1<nf;n1++)
{
if(fframe[n1]==page[count])
{
printf("\n\t");
flag=1;break;
}
}
/* program for lru page replacement algorithm in c */
if(flag==0)
{
for(n1=0;n1<nf;n1++) used[n1]=0;
for(n1=0,tmp=count-1;n1<nf-1;n1++,tmp--)
{
for(k=0;k<nf;k++)
{
if(fframe[k]==page[tmp])
used[k]=1;
}
}
for(n1=0;n1<nf;n1++)
if(used[n1]==0)
index=n1;
fframe[index]=page[count];
printf("\nFault: ");
pf++;
}
for(k=0;k<nf;k++)
printf("%d\t",fframe[k]);
} // lru algorithm in c
printf("\nnumber of total page faults is: %d ",pf);
getch();
}