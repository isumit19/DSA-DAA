#include<stdio.h>
#include<stdlib.h>
#define size 10000
int queue[size];
int front=-1,rear=-1;
void push(int val)
{
	if(front==-1)
		front=0;
	queue[++rear]=val;

}
void pop()
{
	
	if(front==-1)
		printf("Stack empty\n\n");
	else if(front<=rear)
		{
		int x=rear-front,i;
		for(i=0;i<x;i++)
		{
			push(queue[front++]);
		}
		printf("Popped value : %d",queue[front++]);
		}
	else
		printf("Stack empty\n\n");
}
void display()
{
	int i;
	
	if(front==-1)
		printf("Stack empty\n\n");
	else if(front<=rear)
		for(i=front;i<=rear;i++)
			printf("%d ",queue[i]);
	else
		printf("Stack empty\n\n");
}
void push1()
{
	int n,val;
	printf("How many elements you want to push : ");
	scanf("%d",&n);
	printf("Enter elemnents : ");
	while(n--)
	{
		scanf("%d",&val);
		push(val);
	}
	
		
	
}
int main()
{
	int choice;
	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Quit\n\nChoice : ");
		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push1();
					system("cls");
					printf("Elements pushed up successfully");
					break;
			case 2: system("cls");
					pop();
					break;
			case 3: system("cls");
					display();
					break;
			case 4: return 0;
			default: printf("Wrong choice");
		}
	}while(choice!=4);
}
