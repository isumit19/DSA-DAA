#include<stdio.h>
#define size 10
void DFS(int);
void push(int);
void print_sort();
void printTime();
int G[size][size],GT[size],visited[size],arrival[size],departure[size],time=0,n;
int main()
{
    	int e,i,a,b;
    	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the number of edges : ");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		G[a][b]=1;
	}
	for(i=0;i<n;i++)
    		if(visited[i]==0)
    			DFS(i);
    printTime(n);
    
    print_sort();
    	
}

int stack[100],top=-1;

void push(int n)
{
	stack[++top]=n;
}

void print_sort()
{
	int i=0;
	for(int i=top;i>=0;i--)
		printf("%d ",stack[i]);
}

void printTime()
{
	int i;
	printf("\nV   AT    DT\n");
	for(i=0;i<n;i++)
		printf("%d%5d%5d\n",i,arrival[i],departure[i]);
		
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
	push(i);
}

