/*program name:solving tower of hanoi
author :rlf
date:16 sep 2019*/
#include<stdio.h>
int n;
void tower(int n,char beg,char aux,char  end)
{
	if(n==1)
	{
		printf("move disk 1 from %c to %c \n",beg,end);
		return;
	}
	tower(n-1,beg,end,aux);
	printf("move disk %d from %c to %c \n",n,beg,end);
	tower(n-1,aux,beg,end);
}
void main()
{
	printf("enter the number of discs : \n");
	scanf("%d",&n);
	tower(n,'B','A','E');
}
