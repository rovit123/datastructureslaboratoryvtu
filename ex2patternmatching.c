/*program name :pattern matching
 program author: rlf
 */
#include<stdio.h>
char str[100],pat[100],rep[100],ans[100];
int i,j,k,l,p;
int flag;
void read();
void match();
void main()
{
	read();
	match();
	if(flag==0)
	{
		printf("Pattern not found \n");
	}
	else
	{
		printf("Resultant string is \n");
		printf("%s",ans);
	}
}
void read()
{
	printf("Enter the main string \n");
	scanf("%[^\n]",str);
	printf("enter the pattern \n");
	scanf("%*c%[^\n]",pat);
	printf("enter the replace string\n");
	scanf("%*c%[^\n]",rep);
}
void match()
{
	while(str[i]!='\0')
	{
		if(str[j]==pat[p])
		{
			j++;
			p++;
			if(pat[p]=='\0')
			{
				flag=1;
				for(k=0;rep[k]!='\0';k++)
				{
					ans[l]=rep[k];
					l++;
				}
				p=0;
				i=j;
			}
		}
		else
		{
			ans[l]=str[i];
			l++;
			i++;
			j=i;
			p=0;
		}
	}
}
