// Disk Scheduling - SSTF
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int start,n,i,dist=0,curr,j,min=1000,index,count=0;
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
	printf("\n\n Scheduling : \n\n");
	curr = start;
	while(count<n)
	{
		for(j=0;j<n;j++)
		{
			if(arr[j]!=0)
			{
				if(abs(curr-arr[j])!=0)
				{
					if(abs(curr-arr[j])<min)
					{
						min = abs(curr-arr[j]);
						index= j;
					}
				}
			}
		}
		for(j=0;j<n;j++)
		{
			if(arr[j]==curr)
				arr[j]=0;
		}
		dist += min;
		if(count ==0)
			printf("| %d | ",curr);
		else
			printf("-> | %d | ",curr);
		curr= arr[index];
		min=1000;
		count++;
	}
	printf("-> | %d | ",curr);
	printf("\n\n Total Head Movement : %d",dist);

}