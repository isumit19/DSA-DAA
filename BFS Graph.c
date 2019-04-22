#include<stdio.h>
#include<stdlib.h>
#define nodes struct node
struct node{
	int t;
	nodes* next;
};
nodes* new_node(int n)
{
	nodes* temp=(nodes*)malloc(sizeof(nodes));
	temp->t=n;
	temp->next=NULL;
	return temp;
}
void insert_edge(nodes* v[],int a,int b)
{
	//no* top=v[a];
	//while(top->next)
	
	nodes* top=v[a];
	while(top->next!=NULL)
		top=top->next;
	top->next=new_node(b);

	
}
void print_graph(nodes* v[],int n)
{
	int i;
	printf("Adjacency List : \n");
	for(i=0;i<n;i++)
	{
		nodes* temp=v[i];
		while(temp!=NULL)
		{
			printf("%d -> ",temp->t);
			temp=temp->next;
		}
		printf("\n");
	}
}
int queue[100],front=-1,rear=-1,visited[100];


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
 

void bfs(nodes* v[],int n,int s)
{
	insert_queue(s);
	visited[s]=1;

	while(!isEmpty_queue())
	{
		int x=delete_queue();
		printf("%d ",x);
		visited[x]=1;
		
		nodes* top=v[x];
		top=top->next;
		while(top)
		{
			if(!visited[top->t])
			{
				visited[top->t]=1;
				insert_queue(top->t);
			}
			top=top->next;
		}
		
	}
	
}


int main()
{
	int n,e,i,a,b;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	nodes** v=(nodes**)malloc(n*sizeof(nodes*));
	
	for(i=0;i<n;i++)
		v[i]=new_node(i);
	printf("Enter the number of edges : ");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d",&a,&b);
		insert_edge(v,a,b);
	}
	print_graph(v,n);
	
	printf("BFS Traversal: ");
	bfs(v,n,0);
}
