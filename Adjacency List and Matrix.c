#include<stdio.h>
#include<stdlib.h>

struct node{
int val;
struct node* next;
struct node* right;
};

struct node* root=NULL;

int array[100][100];

struct node* newnode(int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->right=NULL;
	temp->next=NULL;
	temp->val=val;
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
void displaym(int nv)
{
	int i,j;
	for(i=0;i<=nv;i++)
	{
		for(j=0;j<=nv;j++)
		{
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int i,n,nv,u,v;
	printf("Enter the number vertices:  ");
	scanf("%d",&nv);
	printf("Enter the number of edges:  ");
	scanf("%d",&n);
	int max=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		if(u>max)
			max=u;
		if(v>max)
			max=v;
		array[u][v]=1;
		insert(u,v);
	}
		
	displayl(root);
	displaym(max);
}
