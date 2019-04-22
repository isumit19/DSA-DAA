#include<stdio.h>
int size;
void printarray(int a[])
{
	
	int i;
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
}
void insertion(int a[])
{	
	printf("Enter the no. of elements to be inserted");
	int n,pos,i,j;
	scanf("%d",&n);
	printf("Enter the index at which element to be inserted ");
	scanf("%d",&pos); 
	int x=pos;
	int b[n];
	printf("Enter elements : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=size-1;j>=pos;j--)
		{
			a[j+1]=a[j];
		}
		size++;
		pos++;
	
	}
	
	for(i=x;i<n+x;i++)
	{
		
		a[i]=b[i-x];
	}
	printarray(a);

	
}
void delete(int a[],int pos)
{
	int i;
	for(i=pos;i<size-1;i++)
	{
		a[i]=a[i+1];
	}
}
void deletion(int a[])
{
	int x,i;
	printf("Enter the element to be deleted ");
	scanf("%d",&x);
	for(i=0;i<size;i++)
	{
		if(a[i]==x)
		{
			delete(a,i);
			size--;
		}
	}
	printarray(a);
}
void searching(int a[])
{
	int ele,i,flag=0;
	printf("Enter the element to be searched : ");
	scanf("%d",&ele);
	for(i=0;i<size;i++)
	{
		if(a[i]==ele)
		{
			flag=1;
			printf("Element found at index %d \n",i);
		}
	}
	if(flag==0)
		printf("Element not found");
}
int main()
{
	int i;
	printf("ENter the no. of elements : ");
	scanf("%d",&size);
	printf("Enter %d elements ",size);
	int a[100];
	for(i=0;i<size;i++)
		scanf("%d",a+i);
	int choice;
	do{
		printf("\nEnter choice : \n0.Quit\n1.Insertion\n2.Deletion\n3.Searching\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:insertion(a);
				break;
			case 2:deletion(a);
				break;
			case 3:searching(a);
				break;
			case 0:return 0;
		}
	}while(choice!=0);
}
