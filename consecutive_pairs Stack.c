#include<stdio.h>
#define size 100
int stack[size];
int top1=-1;
void push(int value,int a[],int *top)
{
	if(*top!=size-1)
		a[++*top]=value;
}
void pop(int *top)
{
	if(*top!=-1)
		--*top;
}
int pairwise()
{
	int a[size];
	int top2=-1;
	while(top1!=-1)
		{
			push(stack[top1],a,&top2);
			pop(&top1);
		}
	while(top2!=-1)
	{

	int x=a[top2];
	pop(&top2);
	if(top2==-1)
		return 1;
	int y=a[top2];
	pop(&top2);
	int d=x-y;
	if(d<0)
		d*=-1;
		
	if(d!=1)	
		return 0;
	}

	return 1;
}
int main()
{
	int n,val,i;
	printf("How many elements you want to push : ");
	scanf("%d",&n);
	i=n;
	printf("Enter elemnents : ");
	while(n--)
	{
		scanf("%d",&val);
		push(val,stack,&top1);
	}
	int x=pairwise();
	if(x&&i%2==1)
		printf("Yes, Elements in all pairs are consecutive numbers, the last elements cannot be paired");
	else if(x&&i%2==0)
		printf("Yes, Elements in all pairs are consecutive numbers");
	else printf("No, Elements in pairs are not consecutive");
	
	
}
