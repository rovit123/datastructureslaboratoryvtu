/*
Program name:hashing table
program author:rlf
date:18-11-19
*/
#include<stdio.h>
#include<stdlib.h>
int n,i,m,*ht,elem=0;
void createht()
{
	ht=(int*)malloc(m*sizeof(int));
	if(ht==NULL)
	{
		printf("insufficient memory");
		exit(0);
	}
	for(i=0;i<m;i++)
		ht[i]=-1;
}
void insertht(int key)
{
	int hi,flag=0;
	hi=key%m;
	while(ht[hi]!=-1)
	{
		hi=(hi+1)%m;
		flag=1;
	}
	if(flag==1)
	{
		printf("collision encountered and resolved using linear probing\n");
	}
	ht[hi]=key;
	elem++;
}
void displayht()
{
	if(elem==0)
	{
		printf("hash table is empty\n");
		return;
	}
	else
	{
		for(i=0;i<m;i++)
		{
			printf("|0%d|->%d\n",i,ht[i]);
		}


	}
}
void main()
{
	int key;
	printf("Enter no of employee record to be stored\n");
	scanf("%d",&n);
	printf("Size of hash table:\n");
	scanf("%d",&m);
	createht();
	for(i=0;i<n;i++)
	{
		printf("Enter key(4digit)");
		scanf("%d",&key);
	if(elem==m)
	{
		printf("Hash table full\n");
		break;
	}
		insertht(key);
	}
	displayht();
}
