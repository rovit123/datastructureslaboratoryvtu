/*program name :array operations
 program author: rlf
 date:29jul2019*/
#include<stdio.h>
#include<stdlib.h>
int a[20],i,n,pos;
void create();
void display();
void insert();
void delete();
void main()
{
	int choice;
	while(1)
	{
		printf("MENU\n	1.create \n	2.display   \n	3.insert  \n	4.delete   \n	5.exit \n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create();
				   break;
			case 2:display();
                   break;
			case 3:insert();
                   break;
			case 4:delete();
				   break;
			case 5:exit(0);

            default:printf("invalid choice\n");
		}
	}
}
void create()
{
	printf("enter the array size\n");
	scanf("%d",&n);
	printf("enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array created\n");
}
void display()
{
	printf("the array elements are:\n");
    for(i=0;i<n;i++)
	{
		printf("%d	",a[i]);
	}
	printf("\n");
}
void insert()
{
	int ele;
	printf("enter the position \n");
    scanf("%d",&pos);
    pos--;
	if(pos>=0&&pos<=n)
    {
		printf("enter the element\n");
		scanf("%d",&ele);
		for(i=n-1;i>=pos;i--)
		{
			a[i+1]=a[i];
		}
		a[pos]=ele;
    n=n+1;
	}
	else
	{
		printf("invalid position\n");
	}
}
void delete()
{
	int ele;
	printf("enter the position to be deleted\n");
	scanf("%d",&pos);
	pos--;
	if(pos>=0&&pos<n)
	{
		ele=a[pos];
		for(i=pos;i<=n-1;i++)
		{
			a[i]=a[i+1];
		}
        n=n-1;
		printf("deleted element is %d\n",ele);
	}
else
{
		printf("invalid position\n");
	}
}




































