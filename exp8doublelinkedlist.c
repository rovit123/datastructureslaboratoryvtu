/*program name :double linked list
 program author: rlf
*/
#include<stdio.h>
#include<stdlib.h>
struct employees
{
	char ssn[10];
	char name[10];
	char dept[10];
	char desig[10];
	int sal;
	char pno[10];
  struct employees *rlink;
  struct employees *llink;

};
typedef struct employees *node;
node first=NULL;
void insend();
void front_insert();
node createnode();
void display();
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
             insend();
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
	temp1=(node)malloc(sizeof(struct employees));
	printf("enter the ssn ");
	scanf("%s",temp1->ssn);
	printf("\nenter the name:");
	scanf("%s",temp1->name);
	printf("\nenter the department");
	scanf("%s",temp1->dept);
	printf("\nenter the design ");
	scanf("%s",temp1->desig);
	printf("\nenter the sal");
	scanf("%d",&temp1->sal);
   printf("\nenter the phno ");
	scanf("%s",temp1->pno);
	temp1->rlink=NULL;
  temp1->llink=NULL;
	count++;
	return temp1;
}
void front_insert()
{
	node temp2;
	temp2=createnode();
	temp2->rlink=first;
	first->llink=temp2;
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
	else if(first->rlink==NULL){
   display_del(first);
		first=NULL;
     return;
	}
	 else
	{
		temp=first;
		first=first->rlink;
		first->llink=NULL;
		display_del(temp);
		free(temp);
		temp=NULL;
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
		while(cur->rlink!=NULL)
		{
			cur=cur->rlink;
		}
		cur->rlink=temp;
		temp->llink=cur;
	}
}
void delend()
{
	if(first==NULL)
		printf("list is empty");
	else if(first->rlink==NULL)
	{
		display_del(first);
		first=NULL;
     return;
	}
	else
	{
   node cur=first;
		while(cur->rlink!=NULL)
		{
			cur=cur->rlink;
		}
		(cur->llink)->rlink=NULL;
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
	while(cur->rlink!=NULL)
	{

		printf("|%s|%s|%s|%s|%d|%s->",cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->pno);

		cur=cur->rlink;
	}
  printf("|%s|%s|%s|%s|%d|%s\n",cur->ssn,cur->name,cur->dept,cur->desig,cur->sal,cur->pno);
  printf("..........................................................................................");
}
void display_del(node j)
{
printf("%s \t%s \t%s \t%s \t%d \t %s\n",j->ssn,j->name,j->dept,j->desig,j->sal,j->pno);
count--;
}


















