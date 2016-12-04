// Disk Scheduling - SCAN
#include<stdio.h>
#include<math.h>
int main()
{
 int i,j,sum=0,n;
 int d[20];
 int disk;   //loc of head
 int temp,max;     
 int dloc;   //loc of disk in array

 printf("Enter number of locations:\t");
 scanf("%d",&n);
 printf("Enter position of Head:\t");
 scanf("%d",&disk);
 printf("Enter elements of Disk Queue:\n");
 for(i=0;i<n;i++)
 {
	 scanf("%d",&d[i]);
 }
 d[n]=disk;
 n=n+1;
 for(i=0;i<n;i++)    // sorting disk locations
 {
	  for(j=i;j<n;j++)
	  {
		    if(d[i]>d[j])
		    {
			    temp=d[i];
			    d[i]=d[j];
			    d[j]=temp;
		    }
	  }
 }
 max=d[n];
 for(i=0;i<n;i++)   // to find loc of disc in array
 {
	 if(disk==d[i]) 
	 { 
	 	dloc=i; break;  
	 }
 }
 sum += abs(disk - d[dloc]);
 printf("\n|||");
 for(i=dloc;i>=0;i--)
 {
 	printf("%d -->",d[i]);
 	if(i>0)
 		sum += abs(d[i] - d[i-1]);
 }
 printf("0 -->");
 sum +=abs(d[dloc+1] - d[0]);
 for(i=dloc+1;i<n;i++)
 {
	 printf("%d-->",d[i]);
	 if(i == n-1)
	 	printf("%d |||",d[i]);
	 if(i<n-1)
	 	sum += abs(d[i+1] - d[i]);
 }
 printf("\n Total Movement of Disk Cylinders:  %d",sum);
 return 0;
}





