#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node* next;
};
struct node* create_node(int x)
{
	struct node* n;
	n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL)
		printf("Size not available, Try Later");
	n->value=x;
	n->next=NULL;
	return n;
}
struct node *head;
struct node* CreateList(int n)
{

	struct node* head,*temp;
	int i,x;
	head=NULL;
	printf("Enter elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		temp=create_node(x);
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
		temp->next=head;
		head=temp;
		
		}
	}
	return head;
}
void display(struct node* top)
{
	struct node* ptr=top;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}
	printf("\n");
}


int main()
{
	int n,n1;
	printf("Enter the number of elements u want to insert in the List : ");
	scanf("%d",&n);
	head=CreateList(n);
	printf("\n****List Created****\n\n");
	display(head);
	struct node *ptr,*tmp;
	ptr=tmp=head;
	while(tmp->next!=NULL&&tmp->next->next!=NULL)
	{
		ptr=ptr->next;
		tmp=tmp->next->next;
	}
	printf("\nMiddle element : "); 
	if(tmp->next!=NULL)
	{
		printf("%d , %d\n",ptr->value,ptr->next->value);
	}
	else
		printf("%d\n",ptr->value);
	
}



