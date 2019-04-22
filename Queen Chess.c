#include<stdio.h>
#include<math.h>
 
int board[20],count;
void print(int n)
{
	int i,j;
	printf("\n\nSolution %d:\n\n",++count);
	
	for(i=1;i<=n;++i)
		printf("\t%d",i); 
	for(i=1;i<=n;++i)
	{
		printf("\n\n%d",i);
		for(j=1;j<=n;++j)
		{
			if(board[i]==j)
				printf("\tQ"); 
   			else
    			printf("\t-"); 
  		}
	}
}
int place(int x,int y)
{
	int i;
	for(i=1;i<x;++i)
	{
		if(board[i]==y || (board[i]-y)==(i-x) || (board[i]-y)==(x-i))
			return 0;
	}
	return 1; 
}
void queen(int row,int n)
{
	int column;
	for(column=1;column<=n;++column)
	{
		if(place(row,column))
  		{
   			board[row]=column; 
   			if(row==n) 
    			print(n);
   			else 
    			queen(row+1,n);
  		}
 	}
}
 
int main()
{
	int n,i,j;
	void queen(int row,int n);
 
	printf(" - N Queens Problem Using Backtracking -");
	printf("\nEnter number of Queens:");
	scanf("%d",&n);
	queen(1,n);
	return 0;
}

