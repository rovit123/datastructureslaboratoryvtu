/*
program :evaluate suffix expression
date:9-09-19
author:rlf

*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
int top=-1,stack[10],i,op1,op2;
char suffix[10],ch;
void push(int);
void main()
{

	printf("enter the expression");
	scanf("%s",suffix);
	while(suffix[i]!='\0')
	{
		ch=suffix[i];
		if(isalpha(ch))
		{
			printf("invalid");
			return;
		}
		else if(isdigit(ch))
		{
			push(ch-48);
		}
		else
		{
			op2=stack[top--];
			if(top<=-1)
			{
				printf("invalid expression");
				return ;
			}
			op1=stack[top--];
			switch(ch)
			{
				case '+':push(op1+op2);
								break;
				case '-':push(op1-op2);
							break;
				case '*':push(op1*op2);
								break;
				case '/':push(op1/op2);
									break;
				case '%':push(op1%op2);
									break;
				case '^':push(pow(op1,op2));
								break;
				default :printf("invalid expression");
        				exit(0);
			}
		}
   i++;
	}
	if(top==0)
	{
		printf("answer is %d",stack[top]);
	}
	else
	{
		printf("invalid exp");
	}
}
void push(int ch)
{
stack[++top]=ch;
}

