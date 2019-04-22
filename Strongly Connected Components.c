#include<stdio.h>
#define size 10
void DFS(int);
void DFS1(int);
void printSCC();
int G[size][size],GT[size][size],visited[size],n,arr[size],top=0,arrival[size],departure[size],time=0;
int main()
{
    int i,j,e,a,b;
//    printf("Enter number of vertices:");
//	scanf("%d",&n);
//	printf("Enter number of edges : ");
//	scanf("%d",&e);
//	
//	printf("Enter edges : \n");
//	for(i=0;i<e;i++)
//	{
//		scanf("%d%d",&a,&b);
//		G[a][b]=1;
//		GT[b][a]=1;
//	}
//	printf("\nEnter adjecency matrix of the graph:");
//	for(i=0;i<n;i++)
//       for(j=0;j<n;j++)
//		{
//			scanf("%d",&G[i][j]);
//			GT[j][i]=G[i][j];
//		}

	FILE *f=fopen("input1.txt","r");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&e);
	for(i=0;i<e;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		G[a][b]=1;
		GT[b][a]=1;
	}
	printf("Transpose GT : \n");
//	{
//		for(int i=0;i<n;i++)
//		{
//			for(int j=0;j<n;j++)
//				printf("%d ",GT[i][j]);
//			printf("\n");
//		}
//	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(GT[i][j])
				printf("%d->%d\n",i,j);
    printSCC();
    	
}
void printTime()
{
	int i;
	printf("\nV   AT    DT\n");
	for(i=0;i<n;i++)
		printf("%d%5d%5d\n",i,arrival[i],departure[i]);
		
}
void printSCC()
{
	int i;
	for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
    	if(visited[i]==0)
    		DFS(i);
    printTime();
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nStrongly Connected Components :\n");
    while(top!=-1)
    {
    	int x=arr[top--];
    	if(visited[x]==0)
    	{
    		
    		DFS1(x);
			printf("\n");	
		}
	}
    
}
void DFS1(int i)
{
    int j;
    visited[i]=1;
    printf("%d ",i);
	for(j=0;j<n;j++)
    {
	   if(!visited[j]&&GT[i][j]==1)
            DFS1(j);
	}
}
void DFS(int i)
{
    int j;
    visited[i]=1;
    arrival[i]=++time;
	for(j=0;j<n;j++)
    {
	   if(!visited[j]&&G[i][j]==1)
            DFS(j);
	}
	departure[i]=++time;
	arr[top++]=i;
}

