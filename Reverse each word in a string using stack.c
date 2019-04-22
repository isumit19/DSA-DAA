#include<stdio.h>
#include<string.h>
#define size 10000
char stack[size];
int top=-1;
void push(char val)
{
	if(top==size-1)
		printf("Stack is full\n");
	else
		stack[++top]=val;
}
void pop()
{
	if(top!=-1)
	{
		printf("%c",stack[top--]);
	}
}
int isempty()
{
	if(top==-1)
		return 1;
	else return 0;
}
int main()
{
	char a[size];
	printf("Enter a stirng : ");
	gets(a);
	int n=strlen(a),i;
	
	for(i=0;i<n;i++)
	{
		if(a[i]!=' ')
		{
			push(a[i]);
		}
		else
		{
			while(!isempty())
				pop();
			printf(" ");
		}
		if(i==n-1)
			while(!isempty())
				pop();
	}
}
