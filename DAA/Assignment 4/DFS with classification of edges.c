#include<stdio.h>
#define size 10
void DFS(int);
int dfs1(int);
void printTime();
int G[size][size],visited[size],arrival[size],departure[size],rec[size],n,k=0,time=0,cycle=0,color[size],dfs_tree[size];
int main()
{
    int i,j,a,b,e;
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
	}
   for(i=0;i<n;i++)
        visited[i]=0;

    int flag=dfs1(0);
    
    printf("\nDFS : ");
    for(int i=0;i<k;i++)
    	printf("%d ",dfs_tree[i]);
    printTime();
    if(flag)
    	printf("Contains Cycle");
    else
    	printf("No Cycle");
    	
}
void printTime()
{
	int i;
	printf("\nV   AT    DT\n");
	for(i=0;i<n;i++)
		printf("%d%5d%5d\n",i,arrival[i],departure[i]);
		
}
//void DFS(int i)
//{
//    int j;
//	printf("\n%d",i);
//	arrival[i]=++time;
//    visited[i]=1;
//    color[i]=1;
//	
//	for(j=0;j<n;j++)
//    {
//	   if(!visited[j]&&G[i][j]==1)
//    	{
//    		if(color[j]==2)
//    			if(arrival[i]<arrival[j])
//    				printf("%d->%d Forward Edge\n",u,v);
//    			else
//    				printf("%d->%d Cross Edge\n",u,v);
//    		if(color[j]==1)
//    			printf("%d->%d Back Edge\n",u,v);
//    		if(color[j]==0)
//    			printf("%d->%d Tree Edge\n",u,v);
//            DFS(j);
//		}
//	}
//	departure[i]=++time;
//}

int dfs1(int i)
{
	if(!visited[i])
	{
		int j;
		visited[i]=1;
		color[i]=1;			//1 for gray; 2 for black ;  0 for white
		dfs_tree[k++]=i;
		arrival[i]=++time;
		rec[i]=1;
		for(j=0;j<n;j++)
		{
			if(G[i][j]==1)
			{
				
				if(color[j]==2)
    				if(arrival[i]<arrival[j])
    					printf("%d->%d Forward Edge\n",i,j);
    				else
    					printf("%d->%d Cross Edge\n",i,j);
    			if(color[j]==1)
    				printf("%d->%d Back Edge\n",i,j);
    			if(color[j]==0)
    				printf("%d->%d Tree Edge\n",i,j);
    			if(!visited[j]&&dfs1(j))
					cycle= 1;
				else if(rec[j])
					cycle= 1;
			}

		}
		departure[i]=++time;
	}
	if(!cycle)
		rec[i]=0;
	return cycle;
}
