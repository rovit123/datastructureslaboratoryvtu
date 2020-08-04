/*program name :queue operations
 program author: rlf
 */
#include<stdio.h>
#include<stdlib.h>
#define max 4
char a[max],item;
int front=-1,rear=-1,i;
void insert();
void delete();
void display();
void main()
{
	int choice;
	while(1)
	{
		printf("menu \n 1.insert \n 2.delete \n 3.display \n 4.exit \n enter your choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
						break;
			case 2:delete();
						break;
			case 3: display();
						break;
			case 4:exit(0);
			default:printf("invalid input \n");
						break;
		}
	}
}
void insert()
{
	if(front==(rear+1)%max)
		printf("overflow");
	else
	{
		rear=(rear+1)%max;
		printf("enter the item \n");
		scanf("%*c%c",&item);
		a[rear]=item;
		if(front==-1)
		{
			front++;
		}
	}
}
void delete()
{
	if(front==-1)
	{
	printf("underflow");
	}
	else
	{
		item=a[front];
		printf("deleted element is %c ",item);
		if(front==rear)
			front=rear=-1;
		else
			front=(front+1)%max;
	}
}
void display()
{
	if(front==-1)
	{
		printf("queue is empty");
	}
	else
	{
		i=front;
		while(i!=rear)
		{
			printf("%c \t",a[i]);
			i=(i+1)%max;
		}
		printf("%c \t",a[i]);
	}
}


