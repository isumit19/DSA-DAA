#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* left;
	struct node* right;
	int val;
	int left_thread;
	int right_thread;
};
struct node* root;
struct node* createnode(int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	temp->left_thread=1;
	temp->right_thread=1;
	return temp;
}
struct node* insert(struct node* root,int n)
{
	struct node* ptr=root;
	struct node* par=NULL;
	while(ptr!=NULL)
	{
		if(n==ptr->val)
		{
			printf("Value duplicate");
			return root;
		}
		par=ptr;
		if(n<ptr->val)
		{
			if(ptr->left_thread==0)
				ptr=ptr->left;
			else
				break;
		}
		else
		{
			if(ptr->right_thread==0)
				ptr=ptr->right;
			else
				break;
		}
	}
	
	struct node* temp=createnode(n);
	if(par==NULL)
	{
		root=temp;
		temp->left=NULL;
		temp->right=NULL;
	}
	else if(n<par->val)
	{
		temp->left=par->left;
		temp->right=par;
		par->left_thread=0;
		par->left=temp;
	}
	else
	{
		temp->left=par;
		temp->right=par->right;
		par->right_thread=0;
		par->right=temp;
	}
	return root;
}
struct node* inorder(struct node* ptr)
{
	if(ptr->right_thread==1)
		return ptr->right;
	ptr=ptr->right;
	while(ptr->left_thread==0)
		ptr=ptr->left;
	return ptr;
}
void display(struct node* root)
{
	struct node* ptr=root;
	while(ptr->left_thread==0)
		ptr=ptr->left;
		
	while(ptr!=NULL)
	{
		printf("%d ",ptr->val);
		ptr=inorder(ptr);
		
	}
}
int main()
{
	int n,val,i;
	printf("Enter the number of values you want to u insert:  ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		root=insert(root,val);
	}
	display(root);
}

