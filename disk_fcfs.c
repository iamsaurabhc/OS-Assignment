// Disk Scheduling - FCFS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int start,n,i,dist=0;
	int *arr;
	printf("Enter the Head Start Address: \n");
	scanf("%d",&start);
	printf("Enter the number of Elements in Disk Queue : \n");
	scanf("%d",&n);
	arr = (int *)malloc(n*sizeof(n));
	printf("\n Enter all the Disk Queue : \n\n");
	for(i=0;i<n;i++)
	{
		printf("\n String [%d] : ",i+1);
		scanf("%d",&arr[i]);
	}
	dist = abs(arr[0]-start);
	for(i=1;i<n;i++)
	{
		dist += abs(arr[i]-arr[i-1]);
	}
	printf("\n Total Head Movement : %d",dist);

}