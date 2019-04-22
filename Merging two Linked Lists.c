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
struct node *head,*head1;
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
void insert(struct node *head,int val,int pos)
{
	int i=0;
	struct node* ptr=head,*temp;
		for(i=1;i<pos-1;i++)
			ptr=ptr->next;
		temp=create_node(val);
		temp->next=ptr->next;
		ptr->next=temp;
	
}
int main()
{
	int n,n1;
	printf("Enter the number of elements u want to insert in the first List : ");
	scanf("%d",&n);
	head=CreateList(n);
	printf("\n****List Created****\n\n");
	display(head);
	printf("\n\nEnter the number of elements u want to insert in the second List : ");
	scanf("%d",&n1);
	head1=CreateList(n1);
	display(head1);
	printf("\n****List Created****\n\n");
	struct node *ptr=head,*ptr1=head1;
	int i=0;
	while(ptr!=NULL&&ptr1!=NULL)
	{
		i++;
		if(i%2==1)
		{
			insert(head,ptr1->value,i+1);
			
			ptr1=ptr1->next;
			
		
		}
		ptr=ptr->next;
	}
	printf("List 1 : ");
	display(head);
	printf("\nList 2 : "); 
	if(ptr1!=NULL)
	{
		while(ptr1!=NULL)
		{
			printf("%d",ptr1->value);
			ptr1=ptr1->next;
		}
	}
	else 
		printf(" List Empty ");
	printf("\n");



	
}
