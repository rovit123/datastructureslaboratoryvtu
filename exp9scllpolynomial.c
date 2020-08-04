/*program name :Polynomial operations using scll
 program author: rlf
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct polynomial
{
	int coef,expx,expy,expz;
	struct polynomial *link;
};
typedef struct polynomial *node;
node createheadernode()
{
	node temp;
	temp=(node)malloc(sizeof(struct polynomial));
	temp->coef=0;
	temp->expx=-1;
	temp->expy=-1;
	temp->expz=-1;
	temp->link=temp;
	return temp;
}
node createnode(int coef,int expx,int expy,int expz)
{
	node temp;
	temp=(node)malloc(sizeof(struct polynomial));
	temp->coef=coef;
	temp->expx=expx;
	temp->expy=expy;
	temp->expz=expz;
	temp->link=NULL;
	return temp;
}
node insertrear(int coef,int expx,int expy,int expz,node head)
{
	node temp;
	node cur;
	temp=createnode(coef,expx,expy,expz);
	if(head->link==head)
	{
		head->link=temp;
	}
	else
	{
		cur=head;
		while(cur->link!=head)
		{
			cur=cur->link;
		}
		cur->link=temp;
	}
	 temp->link=head;

	head->coef=(head->coef)+1;
	return head;
}
node createpoly(node poly)
{
	int n,i,c,x,y,z;
	printf("enter the value of n \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the coefficient \n");
		scanf("%d",&c);
		printf("Enter the exponent (x,y,z) \n");
		scanf("%d%d%d",&x,&y,&z);
		poly=insertrear(c,x,y,z,poly);
	}
	return poly;
}


void display(node head)
{
	node cur;
	if(head->link==head)
	{
		printf("list is empty\n");
		return;
	}
	else
	{
		cur=head->link;
		while(cur!=head)
		{
			if(cur->coef<0)
			{
					printf("%dx^%dy^%dz^%d",cur->coef,cur->expx,cur->expy,cur->expz);
			}
			else
			{
				printf("+%dx^%dy^%dz^%d",cur->coef,cur->expx,cur->expy,cur->expz);
			}
			cur=cur->link;
		}
	}
	printf("\nnumber of nodes s=%d \n",head->coef);
}
double evaluate(int x,int y,int z,node head)
{
	double result=0;
	node cur;
	if(head->link==head)
	{
		printf("list is empty\n");
		return 0;
	}
	else
	{
		cur=head->link;
		while(cur!=head)
		{
			result=result+(cur->coef*pow(x,cur->expx)*pow(y,cur->expy)*pow(z,cur->expz));
			cur=cur->link;
		}
		return result;
	}
}
node polyadd(node a,node b)
{
	node c,starta,startb;
	int sum;
	c=createheadernode();
	starta=a;
	startb=b;
	a=a->link;
	b=b->link;
		while((a!=starta)&&(b!=startb))
		{
			if((a->expx==b->expx)&&(a->expy==b->expy)&&(a->expz==b->expz))
			{
				sum=a->coef+b->coef;
				c=insertrear(sum,a->expx,a->expy,a->expz,c);
				a=a->link;
				b=b->link;
			}
			else if(a->expx>b->expx)
			{
				c=insertrear(a->coef,a->expx,a->expy,a->expz,c);
				a=a->link;
			}
			else if((a->expx==b->expx)&&(a->expy>b->expy))
			{
				c=insertrear(a->coef,a->expx,a->expy,a->expz,c);
				a=a->link;
			}
			else if((a->expx==b->expx)&&(a->expy==b->expy)&&(a->expz>b->expz))
			{
				c=insertrear(a->coef,a->expx,a->expy,a->expz,c);
				a=a->link;
			}
			else
			{
				c=insertrear(b->coef,b->expx,b->expy,b->expz,c);
				b=b->link;
			}
		}
		while(a!=starta)
		{
			c=insertrear(a->coef,a->expx,a->expy,a->expz,c);
				a=a->link;
		}
		while(b!=startb)
		{
			c=insertrear(b->coef,b->expx,b->expy,b->expz,c);
				b=b->link;
		}
	return c;
}
void main()
{
	int x,y,z;
	double eval;
	node poly1;
	node poly2;
	node polysum;
	poly1=createheadernode();
	createpoly(poly1);
	display(poly1);
	printf("Enter the values of x,y,z\n");
	scanf("%d%d%d",&x,&y,&z);
	eval=evaluate(x,y,z,poly1);
	printf("polynomail evaluation=%0.2f\n",eval);
	printf("addition of polynomial\n");
	poly1=NULL;
	poly1=createheadernode();
	createpoly(poly1);
	poly2=createheadernode();
	createpoly(poly2);
	printf("polynomail 1 is:\n");
	display(poly1);
	printf("polynomail 2 is:\n");
	display(poly2);
	polysum=polyadd(poly1,poly2);
	printf("polynomail sum is:\n");
	display(polysum);
}






