#include<stdio.h>
#include<stdlib.h>

struct node{
int val;
int flag;
struct node* next;
struct node* right;

};

struct node* root=NULL;



struct node* newnode(int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->right=NULL;
	temp->next=NULL;
	temp->val=val;
	temp->flag=0;
	return temp;
}
int insert(int u,int v)
{
	struct node* head=root;
	if(root==NULL)
	{
		root=newnode(u);
		root->right=newnode(v);
		return 0;
	}
	while(head->next!=NULL&&head->val!=u)
		head=head->next;
	if(head->val==u)
	{
		while(head->right!=NULL)
			head=head->right;
		head->right=newnode(v);
	}
	else if(head->next==NULL)
	{
		head->next=newnode(u);
		head=head->next;
		head->right=newnode(v);
	}
}
void displayl()
{
	struct node *headc=root;
	while(headc!=NULL)
	{
		
		printf("%d",headc->val);
		struct node *headr=headc->right;
		while(headr!=NULL)
		{
			printf(" -> %d",headr->val);
			headr=headr->right;
		} 
		headc=headc->next;
		printf("\n");
	}

}
int flag[100];
void dfs(struct node *head)
{	
	
	
	while(head!=NULL)
	{
		struct node *r=root;
		if(flag[head->val]==0)
		{
			printf("%d ",head->val);
			flag[head->val]=1;
		}
		
		head=head->right;

		while(head!=NULL&&r!=NULL&&(r->val!=head->val))
		{	r=r->next;
		
		}
		if(head!=NULL&&r!=NULL&&(r->val==head->val)&&flag[r->val]==0)
		{
			
			dfs(r);
			}
			
			
	}
}
int a[100],front=-1,rear=-1,visited[100];
void bfs(struct node* head)
{
	
	visited[head->val]=1;
	if(front==-1)
		front=0;
	a[++rear]=head->val;
	while(front<=rear)
	{
		int v=a[front++];
		printf("%d ",v);
		
		struct node *r=root;
		while(r!=NULL&&(r->val!=v))
		{	r=r->next;
		}
		if(r!=NULL&&(r->val==v))
		{
			while(r){
				int u=r->val;
				if(visited[u]==0)
				{
					visited[u]=1;
					a[++rear]=u;
				}
				r=r->right;
			}
		}
		
	}
	
}
int main()
{
	int i,n,nv,u,v;
	printf("Enter the number vertices:  ");
	scanf("%d",&nv);
	printf("Enter the number of edges:  ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		insert(u,v);
	}
	
	
	
	displayl(root);
	printf("\n\nDFS:  ");
	dfs(root);
	printf("\n\nBFS:  ");
	bfs(root);
	printf("\n");
}
