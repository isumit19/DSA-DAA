#include<stdio.h>
void main()
{
	int size,swap=0,comp=0,i,j,x;
	printf("ENter the no. of elements : ");
	scanf("%d",&size);
	printf("Enter %d elements ",size);
	int a[100];
	for(i=0;i<size;i++)
		scanf("%d",a+i);
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			comp++;
			if(a[j]>a[j+1])
			{
				swap++;
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		printf("Array after %d pass : ",i+1);
		for(x=0;x<size;x++)
			printf("%d ",a[x]);
		printf("\n");

	}
	printf("\nArray after complete sort : ");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);
	printf("No. of comparisons %d\nNo. of swaps %d\n",comp,swap);
}
