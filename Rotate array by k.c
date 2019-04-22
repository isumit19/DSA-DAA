#include<stdio.h>
void main()
{
	int size,i,rot;
	printf("Enter size :");
	scanf("%d",&size);
	int array[size];
	printf("Enter elements : ");
	for(i=0;i<size;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("Enter the no. by which you want to rotate : ");
	scanf("%d",&rot);
	
	while(rot--)
	{
		int i, x=array[0];
		
		for(i=0;i<size-1;i++)
		{
			array[i]=array[i+1];
		}
		array[size-1]=x;
		
	}
	printf("After rotating the array, array will become : ");
	
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
	
	
}
