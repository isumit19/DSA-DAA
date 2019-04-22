#include<stdio.h>
#include<string.h>
#define size 100
char a[size];
int top=-1;
void push(char c)
{	a[++top]=c;}
char pop()
{	if(top!=-1)
		return a[top--];
}
int isoperator(char c)
{
	if(c=='+'||c=='-'||c=='/'||c=='('||c=='*'||c==')')
		return 1;
	else return 0;
}
int isempty()
{
	if(top==-1)
		return 1;
	return 0;
}
int isp[]={0,2,4,5};
int icp[]={100,1,3,6};
int get(char c)
{
	if(c=='(')
		return 0;
	else if(c=='+'||c=='-')
		return 1;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='^')
		return 3;
}
char out[size];
int k=0;
void main()
{
	char s[size];
	printf("Enter the infix expression :  ");
	scanf("%s",s);
	int l=strlen(s),i;
	for(i=0;i<l;i++)
	{
		if(s[i]=='(')
			s[i]=')';
		else if(s[i]==')')
			s[i]='(';
	}
	for(i=l-1;i>=0;i--)
	{
		char c=s[i];
		if(isoperator(c))
		{
			if(c==')')
			{
				while(a[top]!='('&&!isempty())
					out[k++]=pop();
				pop();
				continue;
			}
			else if(!isempty())
			{
				
				while(isp[get(a[top])]>icp[get(c)])
				{
					out[k++]=pop();
					if(isempty())
						break;
				}
	
			}
			push(c);		
		}
		else 
			out[k++]=c;
	}
	while(!isempty())
		out[k++]=pop();
	for(i=k-1;i>=0;i--)
		printf("%c",out[i]);
	printf("\n");

	
}
