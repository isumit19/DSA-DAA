#include<stdio.h>

void main()
{
	
	int size,i,x;
	printf("If the occurences of the numbers are equal then minimum no. will be printed \n\n");
	printf("Enter size :");
	scanf("%d",&size);
	int array[size];
	printf("Enter elements : ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	int num[100]={0};
	for(i=0;i<size;i++)
	{
		int x=array[i];
		int count=0,j;
		for(j=0;j<size;j++)
		{
			if(x==array[j])
				count++;
		}
		num[x]=count;
		
	}
	
	
	for(i=0;i<100;i++)
	{
		if(num[i]>0)
		{
			printf(" no. of occurences of number %d is : %d\n",i,num[i]);
		}
	
	}
	int flag;
	for(i=0;i<100;i++)
	{
		if(num[i]>0)
		{
			flag=i;
			break;
		}
	}
	
	int max,max_occur;
	max_occur=num[flag];
	for(i=0;i<100;i++)
	{
		if(num[i]>0)
		{
		
		
		if(num[i]>max_occur)
			{max=i;
			max_occur=num[i];}
		}
		
	}
	if(max==0)
	{
		max=flag;
	}
	printf(" The element with most occurences is : %d\n",max);
}
