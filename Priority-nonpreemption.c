#include<stdio.h>
main()
{
int n;
printf("Enter the no. of processes: ");
scanf("%d",&n);
int id[n],bt[n],wt[n],tat[n],p[n],i,j,temp;
for(i=0;i<n;i++)
{
  id[i] = i+1;
  printf("\n\nProcess %d : \n",id[i]);
  printf("\nBurst time: ");
  scanf("%d",&bt[i]);
  printf("Priority: ");
  scanf("%d",&p[i]);
}
for(i=0;i<n;i++)
{
  for(j=i+1;j<n;j++)
  {
    if(p[i]>p[j])
    {
      temp=p[i];
      p[i]=p[j];
      p[j]=temp;

      temp=bt[i];
      bt[i]=bt[j];
      bt[j]=temp;

      temp=id[i];
      id[i]=id[j];
      id[j]=temp;
    }
  }
wt[i]=0;
}
for(i=0;i<n;i++)
{
  for(j=0;j<i;j++)
  {
  wt[i]=wt[i]+bt[j];
  }
  tat[i]=wt[i]+bt[i];
}
float avwt=0,avtat=0;
printf("\n\n\nProcess\tP\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
  printf("%d\t%d\t%d\t%d\t%d\n",id[i],p[i],bt[i],wt[i],tat[i]);
  avwt=avwt+wt[i];
  avtat=avtat+tat[i];
}
avwt=avwt/n;
avtat=avtat/n;
printf("Average Waiting Time: %f\n",avwt);
printf("\nAverage Turnaround Time: %f",avtat);
}