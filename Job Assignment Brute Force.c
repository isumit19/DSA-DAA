#include<stdio.h>

#define mx 100
#define mxValue 10000

int n,cmin = mxValue;
int mat[mx][mx];
int mark[mx];
int assigned[mx];

int min(int a, int b)
{
	if(a<b)
	return a;
	return b;
}

int calculate_Min(int i)
{     
	int j,sum = 0,k;
	for(k=0; k<n; k++)
	{
		if(!mark[k])
		{
			int tmin = mxValue;
            for(j=i+1; j<n; j++)
    		{
	 		    tmin = min(mat[j][k], tmin);
	    	}
			sum+=tmin;
		}
	}
	return sum;
}

int getMin(int a[], int given[])
{
	int i,retValue = cmin,retIndex = -1;
	for(i=0; i<n; i++)
	{
	    if(retValue > a[i] && !mark[i] && !given[i])
	    retValue = a[i],retIndex = i;
	}
	return retIndex;
}

void call(int i, int csum)
{
	if(i==n)
	{
		int j;
		if(csum<cmin)
		{
			cmin = csum;
			for(j=0; j<n; j++)
			assigned[j] = mark[j];
		}
		return;
	}
	int arrMin[mx],j;
	for(j=0; j<n; j++)
	arrMin[j] = mxValue;
	for(j=0; j<n; j++)
	{
		if(!mark[j])
		{
			mark[j] = i+1;
			arrMin[j] = csum + calculate_Min(i) + mat[i][j];
			mark[j] = 0;
		}else
		{
			arrMin[j] = mxValue;
		}
		cmin = min(cmin,mxValue);
	}
//	printf("Game Call %d\n",i);
	int given[mx];
	for(j=0; j<n; j++)
	given[j]=0;
	while(1)
	{
		int l = getMin(arrMin, given);
//		printf("%d ",l);
		if(l==-1)
		return;
		given[l] = 1;
		mark[l] = i+1;
//		cout<<i<<" fun\n";
		call(i+1,csum+mat[i][l]);
		mark[l] = 0;
	}
}    

int main()
{
	int i,j;
	printf("Enter number of jobs : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Job %d Workers Cost : ",i+1);
		for(j=0; j<n; j++)
			scanf("%d",&mat[i][j]);
	}
	call(0,0);
	printf("%d\n",cmin);
	for(i=0; i<n; i++)
	printf("Worker %d\n",assigned[i]);
}
