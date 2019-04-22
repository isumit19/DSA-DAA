#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 10000

#define max 100
int g[max][max];
int visit[max];



void generate(int n)
{
	srand(0);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i>=j)
				g[i][j]=g[j][i];
			else
				g[i][j]=rand()%max;
		}
	}
}

int ex_min(int dis[],int n)
{
	int s=INT_MAX,i,index;
	for(i=0;i<n;i++)
	{
		if(dis[i]<s && visit[i]==0)
			s=dis[i],index=i;
	}
	return index;
}


int main()
{
	int n,i,j,v;
	scanf("%d",&n);
		
//  int g[3][3] = {{0, 4, 0,}, 
//                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
//                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
//                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
//                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
//                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
//                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
//                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
//                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
//                     }; 

	
	generate(n);


			
	printf("Generated Graph : \n");
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
				printf("%d ",g[i][j]);
			printf("\n");
	}
				
	int dis[n];
	int parent[n];
	for(i=0;i<n;i++)
		dis[i]=INT_MAX,parent[i]=-1;
	
	int s;
	printf("Enter source : ");
	scanf("%d",&s);
	dis[s]=0;

	for(i=0;i<n-1;i++)
	{
		int u = ex_min(dis,n);
		visit[u]=1;
		for(v=0;v<n;v++)
		{
			if(!visit[v] && g[u][v]!=0 && dis[v]>dis[u]+g[u][v])
				dis[v]=dis[u]+g[u][v];
		}
	}
	
	printf("Distance from Source\n");
	
	for(i=0; i<n;i++)
	{
		printf("%d ",dis[i]);
	}
	
}
