#include<stdio.h>
int max(int a,int b)
{
	return (a>b)?a:b;
}
int main()
{
	int n,i,start=0,end=0,start_index=0,maxi=0,maxs;
	printf("Enter the number of elements ");
	scanf("%d",&n);
	int a[n];
	printf("Enter Elements : ");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	maxs=a[0];
	
	int c=0,sum=0;
	
	for(i=0;i<n;i++)
	{
		if (a[i]<0)
			maxs=max(c,maxs);
		c+=a[i];
		if(c<0)
			c=0;
	}
	maxs=max(c,maxs);
	for(i=0;i<n;i++)
	{
		if (maxi>0)
			maxi=maxi+a[i];
		else
			maxi=a[i],start_index=i;
		if (maxi==maxs)
				printf("start - %d, end - %d\n", start_index, i);
	}
}
