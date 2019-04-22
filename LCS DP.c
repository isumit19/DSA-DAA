#include "head.h"
void LCS(char x[],char y[],int k,int l){
	int i,j,m;
	for(i=1;i<=k;i++){
		for(j=1;j<=l;j++){
			if(x[i-1]==y[j-1])
			{
				c_table[i][j]=c_table[i-1][j-1]+1;
				b_table[i][j]=3;
			}	
			else if(c_table[i-1][j]>=c_table[i][j-1])
			{
				c_table[i][j]=c_table[i-1][j];
				b_table[i][j]=1;
			}
			else
			{
				c_table[i][j]=c_table[i][j-1];
				b_table[i][j]=2;
			}
						
			
		}
	}
}
void print_lcs(char X[],int i,int j)
{
	if (i==0||j==0)
		return;
	if(b_table[i][j]==3)
	{
		
		print_lcs(X,i-1,j-1);
		printf("%c",X[i-1]);
		
	}
	else if(b_table[i][j]==1)
	{
		print_lcs(X,i-1,j);
	}
	else
		print_lcs(X,i,j-1);
}
void print_table(int i,int j)
{
	int m,n;
	printf("\n");
	for(m=0;m<=i;m++)
	{
		for(n=0;n<=j;n++)
			printf("%d ",c_table[m][n]);
		printf("\n");
	}
		printf("\n\n");
		
	for(m=0;m<=i;m++)
	{
		for(n=0;n<=j;n++)
			printf("%d ",b_table[m][n]);
		printf("\n");
	}
}
