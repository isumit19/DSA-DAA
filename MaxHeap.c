#include<stdio.h>
#include<math.h>
void heap(int a[],int n)
{
	int i,j,d;
	for(i=1;i<n;i++)
	{
		d=i;
		j=(i-1)/2;
		while(a[j]<a[d])
		{
			int temp=a[j];
			a[j]=a[d];
			a[d]=temp;
			d=j;
			j=(j-1)/2;
		}
	}
}
int main()
{
	int n,i,j;
	printf("Enter the elements You want to insert : ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	heap(a,n);
	
	for(i=1,j=1;i<n+1;j++)
	{
		while(i<pow(2,j) && i<n+1)
		{
			printf("%d ",a[i-1]);
			i++;
		}
		
		printf("\n");
	}
}
