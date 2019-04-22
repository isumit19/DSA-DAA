#include<stdio.h>
#include<string.h>
int lcs(char X[], char Y[], int m, int n);
int max(int a,int b)
{
	return a>b?a:b;
}
int LCS(char a[],char b[],int i,int j);
char a[100],y=100;
int main()
{
	char one[100],two[100];
	printf("Enter first string : ");
	scanf("%s",one);
	printf("Enter second string : ");
	scanf("%s",two);
	
	int x=lcs(one,two,strlen(one),strlen(two));
	printf("%d\n",x);
	printf("%d",y);
	for(int i=y;i<100;i++)
		printf("%c",a[i]);
}

int lcs(char X[], char Y[], int m, int n) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
  
    if (X[m - 1] == Y[n - 1]) 
    	{a[--y]=X[m-1];
        return 1 + lcs(X, Y, m - 1, n - 1); }
    else
        return max(lcs(X, Y, m, n - 1),lcs(X, Y, m - 1, n)); 
}

