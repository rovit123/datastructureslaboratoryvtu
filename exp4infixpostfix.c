/*program name :Infix to postfix
 program author: rlf
 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
char infix[10],postfix[10],stack[10],ch;
int i=0,j=0,top=-1;
void push(char);
int precedance(char);
void main()
{
	printf("Enter the infix expression \n");
	scanf("%s",infix);
	push('#');
	while((ch=infix[i])!='\0')
	{
		if(isalnum(ch))
            postfix[j++]=ch;

		else if(ch=='(')

				push(ch);

		else if(ch==')')
			{
				while(stack[top]!='(')
  			{
					postfix[j++]=stack[top--];
					if(stack[top]=='#')
					{
						printf("invalid expression");
						return;
					}
				}
                top--;
			}
		else
		{
		int pr=precedance(ch);
		if(ch=='^')
			pr++;
		while(precedance(stack[top])>=pr)
		{
			postfix[j++]=stack[top--];
		}
		push(ch);
		}
		i++;
  }

	while(stack[top]!='#')
	{
	postfix[j++]=stack[top--];
	}
	printf("%s \n",postfix);
}
void push(char c)
{
stack[++top]=c;
}
int precedance(char c)
{
switch(c)
{
case '#' :return 0;
case '(' :return 1;
case '+' :return 2;
case '-' :return 2;
case '*' :return 3;
case '/' :return 3;
case '%' :return 3;
case '^' :return 4;
default :printf("invalid expression  ..");
         exit(0);
}
}

