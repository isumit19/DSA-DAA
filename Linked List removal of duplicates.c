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
		//temp->next=head;
		tail->next=temp;
		temp->prev=tail;
		//head->prev=temp;
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
int main()
{
	int n;
	printf("Enter the number of elements u want to insert in the List (n>0) : ");
	scanf("%d",&n);
	if(n<=0)
	{	printf("Invalid Input");
		return 0;}
	head=CreateList(n);
	printf("\n****List Created****\n\n");
	display();
	struct node *ptr=head,*temp,*temp1;
	while (ptr != NULL && ptr->next != NULL)
    {
        temp = ptr;
        while (temp->next != NULL)
        {
            if (ptr->value == temp->next->value)
            {
				temp1=temp->next;
                temp->next = temp->next->next;
                free(temp1);
            }
            else
                temp = temp->next;
        }
        ptr = ptr->next;
    }
	printf("\n****List After removing Duplicates****\n\n");
	display();
	
}
