#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 1000
struct node{
	int ele;
	struct node* right;
	struct node* left;
};
struct node* createNode(int val){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->right=NULL;
	temp->left=NULL;
	temp->ele=val;
	return temp;
}
struct node* array[size];
int front=-1,rear=-1;
struct node* insert(struct node* root,int data)
{
	struct node* temp=createNode(data);
	if(!root)
		root=temp;
	else
	{
		struct node* f=array[front];
		if(!f->left)
			f->left=temp;
		else if(!f->right)
			f->right=temp;
		if(f->right&&f->left)
			front++;
	}
	if(front==-1)
		front=0;
	array[++rear]=temp;
	
	return root;
}

void display(struct node* ptr)
{
	if(ptr!=NULL)
	{
	display(ptr->left);
	printf("%d ",ptr->ele);
	display(ptr->right);}
}
int search(struct node* *root,int val)
{
	struct node* ar[size];
	int f=0,r=0;
	ar[0]=*root;
	int c=1;
	while(f<=r)
	{
		
		struct node* n=ar[f];
		if(n->ele==val)
		{
			int i;
			for(i=0;;i++)
			{
				if(pow(2,i)>c)
					break;
			}
			printf("Element found at height : %d",i);
			return 1;}
		f++;
		
		if(n->left!=NULL)
			ar[++r]=n->left;
		if(n->right!=NULL)
			ar[++r]=n->right;
		c++;
	}
	return 0;
	
}
int main()
{
	int n,i,x,ele;
	struct node* root=NULL;
	printf("Enter the no. of elements : ");
	scanf("%d",&n);
	printf("Enter values : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		root=insert(root,x);
	}
	printf("Inorder : ");
	display(root);
	printf("\nEnter the element to be searched  :");
	scanf("%d",&ele);
	if(!search(&root,ele))
		printf("Element not found");
}
