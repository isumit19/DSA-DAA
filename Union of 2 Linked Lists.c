#include<stdio.h>
#include<stdlib.h>                            
struct node{
	int value;
	struct node * prev;
	struct node * next;
};
struct node * head=NULL;
struct node * tail=NULL;
struct node *createNode(int value)                             
{
	struct node * temp = (struct node *)malloc(sizeof(struct node));
	temp->value=value;
	temp->next=NULL;
	temp->prev=NULL; return temp;
}
void insert(int value)                               
{
	struct node * temp = createNode(value);
	if(head==NULL)
    {head=temp;tail=temp;return;}
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
struct node * createList(int n)                                 
{                                                    
	struct node * head;
	int i,fe;
	scanf("%d",&fe);
	head=createNode(fe);
	for(i=0; i<n-1; i++)
	{
		int ele;
		scanf("%d",&ele);
		struct node * temp = createNode(ele);
		struct node * temp2=head;
		if(head->value>ele)                           
		{
			temp->prev=head->prev;
			temp->next=head;
			head->prev=temp;
			head=temp;
			continue;
		}
		while(temp2->next!=NULL)
		{
			if(temp2->value>=ele)
			break;
			temp2=temp2->next;
		}
		if(temp2->value==ele)
			continue;
		else if(temp2->value>ele)
		{
		    temp->prev=temp2->prev;
		    temp2->prev=temp;
		    temp->prev->next=temp;
		    temp->next=temp2;
		}else
		{
		temp2->next=temp;
		temp->prev=temp2;}
	}
	return head;
}
void disply(struct node * head)                                                       
{
	struct node * temp=head;
    while(temp!=NULL)
    {
    	printf("%d ",temp->value);
    	temp=temp->next;
    }
    printf("\n");
   
}
void union1(struct node * h1,struct node * h2)                                                
{
	struct node * temp1=h1;
	struct node * temp2=h2;
	while(temp1!=NULL&&temp2!=NULL)
	{
		if(temp1->value==temp2->value)
		{
			insert(temp1->value);
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->value>temp2->value)
		{
			insert(temp2->value);
			temp2=temp2->next;
		}
		else
		{
			insert(temp1->value);
			temp1=temp1->next;
		}
	}
    while(temp1!=NULL)
    {
    	insert(temp1->value);
    	temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
    	insert(temp2->value);
    	temp2=temp2->next;
    }
    printf("\n*** Union ( Sorted order ) ***\n");
    disply(head);
}
int main()
{
	int n,i,val;
	
	printf("Number of elements in first list (n>0) : ");
	scanf("%d",&n);
	
	if(n<1)
	{
		printf("Invalid Input");
		return 0;
	}
	
	printf("Elements :  ");
	struct node * head1 = createList(n);
	printf("Number of elements in second list (n>0) : ");
	scanf("%d",&n);
	
	if(n<1)
	{
		printf("Invalid Input");
		return 0;
	}
	
	printf("Elements : ");
	struct node * head2 = createList(n);
    
    union1(head1,head2);
    
}

