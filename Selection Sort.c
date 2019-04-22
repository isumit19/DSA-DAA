#include<stdio.h>
int main()
{
	int a[100],n,i,j;
	printf("Enter the elements you want to insert (n<100) : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	{
		int small=a[i];
		int pos=i;
		for(j=i+1;j<n;j++)
			{
				if(a[j]<small)
					{
						small=a[j];
						pos=j;
					}
			}
		int temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
		printf("\nArray after iteration %d :",i+1);
		for(j=0;j<n;j++)
			printf("%d ",a[j]);
	}
}

