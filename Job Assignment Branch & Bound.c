#include<stdio.h>
#define mx 100
#define mxValue 1000000

int n,ans = mxValue,i,j;
int mat[mx][mx];
int mark[mx];
int assigned[mx];

int min(int a, int b)
{
	if(a<=b)
	
	return a;
	return b;
}

void call(int i, int sum)
{
	if(i==n)
	{
		int k = 0;
		if(sum<ans)
		{
			for(k=0; k<n; k++)
			assigned[k] = mark[k];
			ans = sum;
		}
		return;
	}
	
	int j = 0;
	for(j=0; j<n; j++)
	{
		if(!mark[j])
		{
			mark[j] = i+1;
			call(i+1,sum+mat[i][j]);
			mark[j] = 0;
		}
	}
	
}

int main()
{
	int i,j;
	printf("Enter numbers of jobs ");
    scanf("%d",&n);
	printf("Enter matrix: \n");
	for(i=0; i<n; i++)
	{
		printf("Job %d Workers Cost : ",i+1);
		for(j=0; j<n; j++)
			scanf("%d",&mat[i][j]);
	}
	
    call(0,0);
	printf("%d\n",ans);
	for(i=0; i<n; i++)
	printf("Worker %d\n",assigned[i]);
}
