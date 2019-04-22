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
	for(i=1;i<size;i++)
	{
		j=i-1;
		int temp=a[i];
		while(j>=0&&a[j]>temp)
		{	swap++;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	printf("Array after %d pass : ",i);
		for(x=0;x<size;x++)
			printf("%d ",a[x]);
		printf("\n");

	}
	printf("\nArray after complete sort : ");
	for(i=0;i<size;i++)
		printf("%d ",a[i]);

	
}
