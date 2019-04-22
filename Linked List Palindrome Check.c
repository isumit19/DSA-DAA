#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node* next;
	struct node* prev;
};
struct node* create_node(int x)
{
	struct node* n;
	n=(struct node*)malloc(sizeof(struct node));
	if(n==NULL)
		printf("Size not available, Try Later");
	n->value=x;
	n->next=NULL;
	n->prev=NULL;
	return n;
}
struct node* head;
struct node* tail;
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
			head=tail=temp;
		}
		else
		{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		}
	}
	return head;
}
void display()
{
	struct node* ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}
	printf("\n");
}
void display_last()
{
	struct node* ptr=tail;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->value);
		ptr=ptr->prev;
	}
	printf("\n");
}
void deletion(struct node *temp)
{
	temp->next=temp->next->next;
	
}
int checkP()
{
	struct node *temp=head,*ptr=head;
	int flag=0;
	while(temp->next!=NULL&&temp->next->next!=NULL)
	{
		ptr=ptr->next;
		temp=temp->next->next;
	}
	
	if(temp->next==NULL)
		flag=1;
	else if(temp->next->next==NULL)
		flag=0;
	if(flag==0)
	{
		temp=ptr->next;
		
		while(ptr!=NULL&&temp!=NULL)
		{
			if(ptr->value!=temp->value)
				return 0;
			ptr=ptr->prev;
			temp=temp->next;
		}
		return 1;
	}
	else
	{
		temp=ptr->next;
		ptr=ptr->prev;
			while(ptr!=NULL&&temp!=NULL)
		{
			if(ptr->value!=temp->value)
				return 0;
			ptr=ptr->prev;
			temp=temp->next;
		}
		return 1;
	}
}
int main()
{
	int n;
	printf("Enter the number of elements u want to insert in the List (n>0) : ");
	scanf("%d",&n);
	if(n<=0)
	{
		printf("Invalid Input");
		return 0;
	}
	head=CreateList(n);
	printf("\n****List Created****\n\n");
	display();
	int flag=checkP();
	if(flag==1)
		printf("\nPalindrome");
	else printf("\nNot a palindrome");
	
}
