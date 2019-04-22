
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define max 100 
int g[max][max];
int queue[100],front=-1,rear=-1,visited[100];
int V;
int parent[max];
int min(int a,int b)
{
	return (a>b)?b:a;
}
void insert_queue(int n)
{
	if(rear==99)
		printf("Queue Overflow");
	else
	{
		if(front==-1)
			front=0;
		rear=rear+1;
		queue[rear]=n;
	}
}

int delete_queue()
{
	int x;
	if(front==-1||front>rear)
	{
		printf("Queue Underflow");
		exit(1);
	}
	x=queue[front];
	front=front+1;
	return x;
}

int isEmpty_queue()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
 


int bfs(int rg[V][V],int s, int t) 
{ 
	int visited[V]; 
	memset(visited, 0, sizeof(visited)); 

	insert_queue(s);
	visited[s] = 1; 
	parent[s] = -1; 

	while (!isEmpty_queue()) 
	{ 
		int u = delete_queue();

		for (int v=0; v<V; v++) 
		{ 
			if (visited[v]==0 && rg[u][v] > 0) 
			{ 
				insert_queue(v);
				parent[v] = u; 
				visited[v] = 1; 
			} 
		} 
	} 
	return (visited[t] == 1); 
} 





int ford( int s, int t) 
{ 
	int u, v; 

	int rg[V][V]; 
	for (u = 0; u < V; u++) 
		for (v = 0; v < V; v++) 
			rg[u][v] = g[u][v]; 
	int max_flow = 0; 


	while (bfs(rg, s, t)) 
	{ 
		int flow = INT_MAX; 
		for (v=t; v!=s; v=parent[v]) 
		{ 
			u = parent[v]; 
			flow = min(flow, rg[u][v]); 
		} 
 		
		for (v=t; v != s; v=parent[v]) 
		{ 
			u = parent[v]; 
			rg[u][v] -= flow; 
			rg[v][u] += flow; 
		}
		printf("Augmented Flow : %d\n",flow);
		printf("Augmented Path :" );
		int x=0;
		int d=t;
		int path[V];
		do
		{
			path[x++]=d;
			d=parent[d];
		}while(d!=s);
		path[x++]=s;
		int i;
		for(i=x-1;i>-1;i--)
			printf("%d ",path[i]);
		
		max_flow += flow; 
		printf("\nPath flow till now : %d \n",max_flow);
		int j;
		printf("Residual Graph :\n");
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
				printf("%d ",rg[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	
	

	return max_flow; 
} 
int main() 
{ 
	FILE *f=fopen("input.txt","r");
	fscanf(f,"%d",&V);
	
	int i,j;

	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			fscanf(f,"%d",&g[i][j]);
	
	int s,d;
	printf("Enter source : ");
	scanf("%d",&s);
	printf("Enter destination : ");
	scanf("%d",&d);
	printf( "The maximum possible flow is %d\n",  ford( s,d)); 

	return 0; 
} 

