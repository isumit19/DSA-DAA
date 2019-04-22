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
		temp->next=head;
		head=temp;
		}
	}
	return head;
}
void display()
{
	struct node* ptr=head;
	if(head==NULL)
	{
		printf("List Empty");
	}
	else
	{
	while(ptr!=NULL)
	{
		printf("%d ",ptr->value);
		ptr=ptr->next;
	}}
	printf("\n");
}
void update_head(int n)
{
	struct node* temp;
	int i,x;
	printf("Enter elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		temp=create_node(x);
		if(head==NULL)
		{
		}
		else
			temp->next=head;
		head=temp;
	}
	printf("\nList after updating becomes : ");
	display();
}
void update_tail(int n)
{
	struct node* temp;
	int i,x;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		temp=create_node(x);
		tail->next=temp;
		tail=temp;
	}
	printf("\nList after updating becomes : ");
	display();
}

void deletion_head()
{
	if(head==NULL)
	{
		printf("List is empty!! Can't delete anything\n");
	}
	else
	{
		struct node* ptr=head;
		head=head->next;
		free(ptr);
		printf("\nList after deletion becomes : ");
		display();
	}
}
void deletion_tail()
{
	if(tail==NULL)
	{
		printf("List is empty!! Can't delete anything\n");
	}
	else
	{
		struct node* ptr=head;
		while(ptr->next!=tail)
			ptr=ptr->next;
		ptr->next=NULL;
		free(tail);
		tail=ptr;
		printf("\nList after deletion becomes : ");
		display();
	}
}
void update_middle()
{
	printf("Enter the position u want to insert : ");
	int i=0,pos,val;
	scanf("%d",&pos);
	struct node* ptr=head,*temp;
	
	if(pos==1)
		update_head(pos);
	else
	{
		printf("Enter the value u want to insert : ");
	scanf("%d",&val);
		for(i=1;i<pos-1;i++)
			ptr=ptr->next;
		temp=create_node(val);
		temp->next=ptr->next;
		ptr->next=temp;
		printf("\nList after updating becomes : ");
		display();
	}
}
void deletion_middle()
{
	printf("Enter the position u want to delete : ");
	int i=0,pos;
	scanf("%d",&pos);
	if(pos==1)
	{
		deletion_head();
	}
	else{struct node* ptr=head,*temp;
	for(i=1;i<pos-1;i++)
		ptr=ptr->next;
	temp=ptr->next;
	ptr->next=ptr->next->next;
	free(temp);
	printf("\nList after deletion becomes : ");
	display();}
}
void search()
{
	struct node *ptr=head;
	int i,ele;
	printf("Enter the value to be searched : ");
	scanf("%d",&ele);
	for(i=1;ptr!=NULL;i++)
		{
			if(ptr->value==ele)
				{
					printf("\nElement found at position : %d\n",i);
				}
			ptr=ptr->next;
		}
}
void Insertion()
{
	int choice,n;
	printf("Enter choice : \n1. At head\n2. At tail\n3. At middle\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	printf("Enter the number of elements you want to insert at head : ");
				scanf("%d",&n);
				update_head(n);
				break;
				
		case 2: printf("Enter the number of elements you want to insert at tail : ");
				scanf("%d",&n);
				update_tail(n);
				break;
				
		case 3:	update_middle();
				break;
				
		default: printf("\nInvalid choice\n");
	}
}
void Delete()
{
	int choice;
	printf("Enter choice : \n1. At head\n2. At tail\n3. At middle\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: deletion_head();
				break;
		case 2: deletion_tail();
				break;
		case 3: deletion_middle();
				break;
				
		default: printf("\nInvalid choice\n");		
	}
}
int main()
{
	int n;
	int choice=1;
	printf("Enter the number of elements u want to insert in the List : ");
	scanf("%d",&n);
	head=CreateList(n);
	printf("\n****List Created****\n\n");
	display();
	printf("\n");
	do
	{
		printf("Enter choice : \n1.Insertion\n2.Deletion\n3.Searching\n4.Display\n5.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	Insertion();
					break;
			case 2: Delete();
					break;
			case 3: search();
					break;
			case 4: display();
					break;
			case 5: break;
			default: {printf("Wrong choice\n");
					continue;}
			
		}
	}while(choice!=5);
}
