/*program name :stack operations
 program author: rlf
 */
#include<stdio.h>
#include<stdlib.h>
#define max 5
int stack[max],item,top=-1;
void push();
void pop();
void palindrome();
void display();
void main()
{
	int choice;
 while(1)
	{
		printf("menu \n1.push \n2.pop \n3.palindrome \n4.display \n5.exit  \n");
		printf("enter your choice: \n");
		scanf("%d",&choice);
 		switch(choice)
		{
			case 1:push();
						break;
			case 2:pop();
						break;
			case 3:palindrome();
						break;
			case 4:display();
						break;
			case 5:exit(0);
			default:printf("invalid ");

		}
	}
}
void push()
{
	if(top==max-1)
	{
		printf("stack overflow \n");
	}
	else
	{
		printf("enter the element: \n");
		scanf("%d",&item);
		stack[++top]=item;
	}
}
void pop()
{
	if(top==-1)
	{
	printf("stack underflow \n");

	}
	else
	{
		--top;
	}
}
void palindrome()
{
	int i=top,j=0,flag=0;
	while(i>j)
	{
		if(stack[i]!=stack[j])
		{
			flag=1;
			break;
		}
		else
		{
			i--;
			j++;
		}
	}
	if(flag==1)
	{
	printf("it is not a palindrome \n");
	}
	else
  {
 		printf("it is a palindrome \n");
  }
}
void display()
{
	int k;
	if(top!=-1)
	{
		printf("elements in stack are:\n");
		for(k=top;k>=0;k--)
		{
			printf("%d\n",stack[k]);
		}
	}
	else
 		printf("there are no elements \n");
}


