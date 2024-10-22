#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;
void enqueue(int value)
{
struct node*ptr;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=value;
ptr->next=NULL;
if((front==NULL)&&(rear==NULL))
{
front=rear=ptr;
}
else
{
rear->next=ptr;
rear=ptr;
}
printf("\nNode is Inserted\n\n");
}
int dequeue()
{
if(front==NULL)
{
printf("\n UNDERFLOW\n");
return -1;
}
else
{
struct node*temp=front;
int temp_data=front->data;
front=front->next;
free(temp);
return temp_data;
}
}
void display()
{
struct node*temp;
if((front==NULL)&&(rear==NULL))
{
printf("\n queue is empty\n");
}
else
{
printf("\nqueue is:\n");
temp=front;
while(temp)
{
printf("\n%d\n",temp->data);
temp=temp->next;
}
printf("\nNULL\n");
}
}
int main()
{
int choice,value;
printf("\nimplementation of queue using linked list\n");
while(choice!=4)
{
printf("\n1.enqueue\n2.Dequeue\n3.Display\n4.Exit");
printf("\nenter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
	printf("\nenter the value to be inserted\n");
	scanf("%d",&value);
	enqueue(value);
	break;
case 2:
	printf("\npopped element is:%d\n",dequeue());
	break;
case 3 :
	display();
	break;
case 4:
	exit(0);
	break;
default:
	printf("\ninvalid choice\n");
	break;
}
}
return 0;
}
