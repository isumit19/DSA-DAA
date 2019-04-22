#include<stdio.h>
#define size 10
int min(int a,int b)
{
	return a>b?b:a;
}
void DFS(int);
void findAP();
int G[size][size],GT[size][size],visited[size],n,time=0,disc[size],low[size],parent[size],ap[size],flag;
int main()
{
    int i,j,e,a,b;
//    printf("Enter number of vertices:");
//	scanf("%d",&n);
//	printf("Enter number of edges : ");
//	scanf("%d",&e);
//	printf("Enter edges : \n");
//	for(i=0;i<e;i++)
//	{
//		scanf("%d%d",&a,&b);
//		G[a][b]=1;
//	}
	FILE *f=fopen("input1.txt","r");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&e);
	for(i=0;i<e;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
    findAP();
}
void DFS(int i)
{
    int ch=0,j;
    visited[i]=1;
    disc[i]=low[i]=++time;
    
    
    
	for(j=0;j<n;j++)
    {
	   if(!visited[j]&&G[i][j]==1)
            {
            	ch++;
            	parent[j]=i;
            	DFS(j);
            	low[i]=min(low[i],low[j]);
            	if(parent[i]!=-1&&low[j]>=disc[i])
            		ap[i]=1;
            	if(parent[i]==-1&&ch>1)
            		ap[i]=1;
			}
		else if(j!=parent[i]&&G[i][j]==1)
			low[i]=min(low[i],disc[j]);
	}
}
void findAP()
{
	int i;
	for(i=0;i<n;i++)
		parent[i]=-1;
	for(i=0;i<n;i++)
		if(visited[i]==0)
			DFS(i);
	printf("Articulation Points : ");
	for(i=0;i<n;i++)
		if(ap[i])
		{
			printf("%d ",i);
			flag=1;
		}
	if(!flag)
		printf("NO ARTICULATION POINT ");
}

