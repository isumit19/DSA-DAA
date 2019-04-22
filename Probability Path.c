#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100

float g[max][max];
int visit[max];
int parent[max];
int path[max];

int main()
{
	int V,E;
	printf("Enter number of vertex :");
	scanf("%d",&V);
	printf("Enter number of edges : ");
	scanf("%d",&E);
	int a,b,i,j;
	for(i=0;i<E;i++)
	{
		scanf("%d %d",&a,&b);
		scanf("%f",&g[a][b]);
	}
	for(i=0;i<V;i++)
		g[i][i]=1;
	int n=V;
	float dis[n];
	
	for(i=0;i<V;i++)
	{
	for(j=0;j<V;j++)
	printf("%f ",g[i][j]);
	printf("\n");}
	
	
	memset(parent,-1,sizeof(parent));
	int s;
	printf("Enter source : ");
	scanf("%d",&s);
	dis[s]=1;
	int u,v;
	for(i=0;i<n-1;i++)
		for(u=0;u<n;u++)
			for(v=0;v<n;v++)
				if(g[u][v]!=1 && dis[v]<dis[u]*g[u][v])
					dis[v]=dis[u]*g[u][v],parent[v]=u;
	int d;
	printf("Enter destination : ");	
	scanf("%d",&d);
	printf("Cost : %f\n",dis[d]);
	printf("\n");
	int x=0;
	do
	{
		path[x++]=d;
		d=parent[d];
	}while(d!=s);
	path[x++]=s;
	printf("Path : ");
	for(i=x-1;i>-1;i--)
		printf("%d ",path[i]);
}
