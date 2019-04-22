#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node
{
	int val;
	struct node* next;
};
struct node* array[size];
struct node* createnode(int n)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->val=n;
	temp->next=NULL;
	return temp;
}
void insert(int val)
{
	struct node* temp=createnode(val);
	int i=val%10;
	if(array[i]==NULL)
		array[i]=temp;
	else
	{
		struct node* x=array[i];
		while(x->next!=NULL)
			x=x->next;
		x->next=temp;
	}
}
int main()
{
	int n,i;
	printf("Enter the number of elements u want to insert:  ");
	scanf("%d",&n);
	int val;
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
	
	printf("\n\n*****************************\n");
	for(int i=0;i<size;i++)
	{
		struct node* x=array[i];
		printf("%d: ",i);
		while(x!=NULL)
		{
			printf("%d ",x->val);
			x=x->next;
		}
		printf("\n");
	}
	
}
