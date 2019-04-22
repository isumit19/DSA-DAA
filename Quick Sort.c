#include<stdio.h>
int n;
void QuickSort(int a[],int first,int last){
   int i, j, p, temp,flag=0;

   if(first<last){
      p=last;
      i=first;
      j=last;
      while(i<j){
         while(a[i]<=a[p]&&i<last)
            i++;
         while(a[j]>a[p])
            j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            flag=1;
         }
      }
 int k;
      for(k=0;k<n;k++)
      {
      if(k!=p)
      	printf("%d ",a[k]);
      else
      	printf("%d* ",a[k]);
      }
      temp=a[p];
      a[p]=a[j];
      a[j]=temp;
    
      printf("\n");
      QuickSort(a,first,j-1);
      QuickSort(a,j+1,last);
     
      

   }
}

int main()
{
	int a[100],i,j;
	printf("Enter the elements you want to insert (n<100) : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nArray ");
	for(j=0;j<n;j++)
	{
		if(j!=n-1)
      		printf("%d ",a[j]);
     		 else
      		printf("%d* ",a[j]);
     	 
	}
	printf("\n");
	QuickSort(a,0,n-1);
	
			
	
}
