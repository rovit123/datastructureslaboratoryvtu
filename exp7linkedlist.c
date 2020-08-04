/*program name :linked list operations
 program author: rlf
*/
#include<stdio.h>
#include<stdlib.h>
struct student
{
	char usn[20];
	char name[20];
	char branch[20];
	int sem;
	long int pno;
	struct student *link;
};
typedef struct student *node;
node first=NULL;
void front_insert();
node createnode();
void display();
void insend();
void delend();
void delfro();
void display_del(node);
int count=0;
void main()
{

	int choice,n;
	while(1)
	{
		printf("MENU \n 1.create \t 2.display \t 3.insertend \t4.deleteend \t5.insertfront \t6.deletefront\t7.exit \n enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
							printf("enter number of students list");
						scanf("%d",&n);
						for(int i=0;i<n;i++)
             front_insert();
							break;
			case 2:display();
							break;
			case 3:insend();
							break;
			case 4:delend();
							break;
			case 5:front_insert();
							break;
			case 6:delfro();
							break;
			case 7:exit(0);
			default:printf("invalid choice");
		}
	}
}
node createnode()
{
	node temp1;
	temp1=(node)malloc(sizeof(struct student));
	printf("enter the usn ");
	scanf("%s",temp1->usn);
	printf("\nenter the name:");
	scanf("%s",temp1->name);
	printf("\nenter the branch");
	scanf("%s",temp1->branch);
	printf("\nenter the sem ");
	scanf("%d",&temp1->sem);
	printf("\nenter the pno:");
	scanf("%ld",&temp1->pno);
	temp1->link=NULL;
	count++;
	return temp1;
}
void front_insert()
{
	node temp2;
	temp2=createnode();
	temp2->link=first;
	first=temp2;
}

void delfro()
{
	node temp,cur;
	if(first==NULL)
	{
		printf("list is empty");
		return;
	}
	else
	{
		temp=first->link;
		cur=first;
		first=temp;
		display_del(cur);
		free(cur);
		cur=NULL;
	}
}
void insend()
{
node temp,cur;
temp=createnode();
 if(first==NULL)
		first=temp;
	else
	{
	cur=first;
		while(cur->link!=NULL)
		{
			cur=cur->link;
		}
		cur->link=temp;
	}
}
void delend()
{
	if(first==NULL)
		printf("list is empty");
	else if(first->link==NULL)
	{
		display_del(first);
		first=NULL;
     return;
	}
	else
	{
   node prev;
   node cur=first;
		while(cur->link!=NULL)
		{
			prev=cur;
			cur=cur->link;
		//	display_del(cur);
		}
		prev->link=NULL;
		display_del(cur);
		free(cur);
		cur=NULL;
	}

}
void display()
{
node cur;
	cur=first;
   printf("....................................................................................\n");
	while(cur->link!=NULL)
	{

		printf("|%s|%s|%s|%d|%ld|->",cur->usn,cur->name,cur->branch,cur->sem,cur->pno);

		cur=cur->link;
	}
  printf("|%s|%s|%s|%d|%ld|\n",cur->usn,cur->name,cur->branch,cur->sem,cur->pno);
  printf("..........................................................................................");
}
void display_del(node j)
{
printf("%s \t%s \t%s \t%d \t%ld \n",j->usn,j->name,j->branch,j->sem,j->pno);
count--;
}



