/*program name :bst operations
 program author: rlf
 */
#include<stdio.h>
#include<stdlib.h>
struct bst
{
	int data;
	struct bst *left;
  struct bst *right;
};
typedef struct bst *node;
int i=0;
node createtree(int data)
{
	node temp=(node)malloc(sizeof(struct bst));
			temp->data=data;
			temp->left=NULL;
			temp->right=NULL;
			return temp;
}
void insertbst(node root,node newnode)
{
	if(root->data==newnode->data)
	{
		printf("value already exits \n");
		i--;
		return ;
		}
	if(newnode->data<root->data)
		{
				if(root->left==NULL)
					root->left=newnode;
				else
					insertbst(root->left,newnode);
		}
	else if(newnode->data>root->data)
		{
				if(root->right==NULL)
					root->right=newnode;
				else
					insertbst(root->right,newnode);
		}
}
void inorder(node root)
{
	if(root!=NULL)
{
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

}
void preorder(node root)
{
if(root!=NULL)
{

	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}


}
void postorder(node root)
{
 if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}

}
void search(node root,int item)
{

	if(root==NULL)
	{
	printf("element not found\n");
	return;
	}
	if(root->data==item)
		printf("search successfull element found \n");
	else if(item<root->data)
	{
	search(root->left,item);
	}
	else
	{
		search(root->right,item);
	}
}
/*node temp=root;
while(temp!=NULL)
{
if(item==temp->data)
	{
	printf("search succesfull ");
	return;
	}
if(temp->data>item)
temp=temp->left;
else
temp=temp->right;
}
 printf("element not found");
}  */
void main()
{
node root=NULL,newnode;

	int choice,n,data,item;
	while(1)
	{
		printf("MENU:\n 1.create \t2.inorder\t 3.preorder \t4.postorder\t 5.search \t 6.exit \t \n enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
							printf("enter the number of items\n");
						scanf("%d",&n);
						for(i=0;i<n;i++)
						{
							printf("enter the values: \t");
							scanf("%d",&data);
             newnode=createtree(data);
						if(root==NULL)
							root=newnode;
						else
								insertbst(root,newnode);
						}
							break;
			case 2:printf("inorder traversal is \n");
							inorder(root);
							break;
			case 3:printf("preorder traversal is \n ");
							preorder(root);
							break;
			case 4:printf("postorder traversal is \n");
							postorder(root);
							break;
			case 5:printf("enter the element to be searched \n");
							scanf("%d",&item);
							search(root,item);
							break;
			case 6:exit(0);

			default:printf("invalid choice \n");
		}
	}
}

