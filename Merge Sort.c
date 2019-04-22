#include<stdio.h>
static int n;
void merge(int a[],int l1,int h1,int l2,int h2)
{
    int temp[100];   
    int i=l1,j=l2,k=0,d=0;   
    
    while(i<=h1 && j<=h2)   
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    
    while(i<=h1)  
        temp[k++]=a[i++];
        
    while(j<=h2)    
        temp[k++]=a[j++];
        
   
    for(i=l1,j=0;i<=h2;i++,j++)
        a[i]=temp[j];
    for(d=l1;d<=h2;d++)
    	printf("%d ",a[d]);
    printf("\n");
        
}
void MergeSort(int a[],int low,int high)
{
	if(low<high)
		{int mid=(low+high)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		merge(a,low,mid,mid+1,high);
		int j;
		static int k=1;
		//printf("\nArray after iteration %d :",k++);
		//for(j=0;j<n;j++)
		//	printf("%d ",a[j]);
		}
	
}
int main()
{
	int a[100],i,j;
	printf("Enter the elements you want to insert (n<100) : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	MergeSort(a,0,n-1);
	printf("\nArray after complete sort ");
		for(j=0;j<n;j++)
			printf("%d ",a[j]);
	
}
