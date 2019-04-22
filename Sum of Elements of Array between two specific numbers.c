#include<stdio.h>

int findindex(int array[],int size,int num)
{
	int pos,i;
	for(i=0;i<size;i++)
	{
		if(array[i]==num)
		{
			pos=i;
			return pos;
		}
	}
	return -1;

}

int main()
{
	int size,a,b,index_a,index_b,sum_total=0,sum_ex=0,i;
	printf("Enter size :");
	scanf("%d",&size);
	int array[size];
	printf("Enter elements : ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("\nif repetition, first occurence of the element will be considered\n");
	printf("Enter the value of 'a' :");   
	scanf("%d",&a);
	printf("Enter the value of 'b' :");
	scanf("%d",&b);
	index_a=findindex(array,size,a);
	index_b=findindex(array,size,b);
	
	if(index_a==-1||index_b==-1)
		{
			printf("Elements not available, try again\n");
			return 0;
		}
	for(i=0;i<size;i++)
	{
		sum_total+=array[i];
	}
	if(index_a>index_b)
	{
		printf("hi");
		for(i=index_b+1;i<index_a;i++)
		{
			sum_ex+=array[i];
		}
	}
	else
	{
		for(i=index_a+1;i<index_b;i++)
		{
			sum_ex+=array[i];
		}
		
	}
	printf("Sum of array elements excluding numbers lying b/w a and b are %d\n",sum_total-sum_ex);	
	
}
