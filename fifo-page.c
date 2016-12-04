#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
  {
  int data;
  struct node *next;
  }*curr,*new_node,*current,*start=NULL,*temp,*last;

int arr[100],count,fault,fno;
//--------------------------------
void creat()
 {
 int i;
   
   for(i=0;i< fno;i++)
   {
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data = -99;     // -99 = NULL or Empty Characcter
   new_node->next=NULL;
    
   if(start==NULL)
     {
     start=new_node;
     current=new_node;
     }
   else
     {
     current->next=new_node;
     current=new_node;
     }
   }
 current->next = start;
 }
//--------------------------------
void display()
{
struct node *temp;
temp=start;
  do
   {
   if(temp->data == -99)
       printf("-\t",temp->data);
   else
       printf("%d\t",temp->data);
   temp=temp->next;
   }while(temp!=start);
}
//--------------------------------
int search(int number)
{
int flag;
struct node *temp;
temp=start;
  do
   {
   if(temp->data==number)
         return(1);
   else
         flag = 0;
   temp=temp->next;
   }while(temp!=start);

if(flag ==0)
   return(0);
}
//--------------------------------
void fifo()
{
int res,i;
temp = start;  //Temp Purpose
last = start;  //Repl Purpose
curr = start;  //Curr Purpose ->-99

for(i=0;i< count;i++)
  {
  res = search(arr[i]);

   if(res == 0)
     {
     fault++;
     if(curr->data == -99)
        {
        curr->data = arr[i];
        curr = curr->next;
        }
     else
        {
        last ->data = arr[i];
        last = last->next;
        }
     }//end outer if

  printf("\n\nAfter Inserting (%d)  :: ",arr[i]);
  display();
  printf("    Fault : %d",fault);
  }//end for

printf("\n--------------------------------------------\n");
  printf(" ¯ Total Number of Faults = %d",fault);
printf("\n--------------------------------------------\n");

}
//--------------------------------
void accept()
{
int i;
printf("\nEnter the number of Frames : ");
scanf("%d",&fno);

printf("\nEnter the number of Pages : ");
scanf("%d",&count);

printf("\nEnter the Page No : ");
for(i=0;i< count;i++)
    scanf("%d",&arr[i]);
}
//------------------------------------------------
void main()
{
char ch;
printf("\nAccept Frame Number and Pages");
printf("\n");

accept();
creat();
fifo();

getch();
}