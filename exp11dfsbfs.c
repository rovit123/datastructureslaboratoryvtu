/*program name :bfs/dfs
 program author: rlf
 */
#include<stdio.h>
#include<stdlib.h>
int q[10],visited[10],a[10][10],reach[10];
int r=-1,f=0,u,n;
void bfs(int v)
{
 int i;
 q[++r]=v;
	visited[v]=1;
	while(f<=r)
	{
		u=q[f++];
		for(i=1;i<=n;i++)
		{
			if(a[u][i]==1&&visited[i]!=1)
			{
				q[++r]=i;
				printf("->%d",i);
				visited[i]=1;
			}
		}
	}
}
void dfs(int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
	{
		if(a[v][i]&&!reach[i])
		{
			printf("->%d",i);
			dfs(i);
		}
	}

}
void main()
{
	int j,i,v,b;
	printf("enter the value of n");
	scanf("%d",&n);
	printf("enter adjacency matrix:");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter initial vertex");
	scanf("%d",&b);
	v=b;
	if(v<1||v>n)
	{
	printf("\n invalid");
	exit(0);
	}
	printf("bfs traversal is :%d",v);
	bfs(v);
	printf("\ndfs traversal is :%d",v);
	dfs(v);



}

