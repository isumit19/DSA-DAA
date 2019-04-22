#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	printf("Enter string : ");
	scanf("%s",s);
	char x,y;
	printf("Enter x : ");
	scanf(" %c",&x);
	printf("Enter y : ");
	scanf(" %c",&y);
	int i,cx=0,ct=0;
	for(i=0;i<strlen(s);i++)
	{
		char a=s[i];
		if (a==x)
			cx++;
		else if (a==y)
			ct+=cx;
	}
	printf("Total substrings that starts with %c and ends with %c are : %d\n",x,y,ct);
	
}
