#include<stdio.h>
#include<string.h>
void com_lps(char *pat,int lps[])
{
	int len = 0, i;
	lps[0] = 0;
	i = 1;
	while(i < strlen(pat))
	{
		if(pat[i] == pat[len])
		{
			len++;
			
			lps[i] = len;
			i++;
		}
		else
   		{
   			if( len != 0 )
     			len = lps[len-1];
   			else
   			{
     			lps[i] = 0;
     			i++;
   			}
   		}
	}
}
void kmp(char *txt,char *pat)
{
	int j=0,i=0;
	int len_pat = strlen(pat),len_txt=strlen(txt);
	int lps[len_pat];
	com_lps(pat,lps);
	while(i < len_txt)
	{
		if(pat[j] == txt[i])
		{
			j++;
			i++;
  		}
	
		if (j == len_pat)
		{
			printf("Found pattern at 's' %d \n", i-j);
			j = lps[j-1];
		}
		else if(pat[j] != txt[i])
		{
			if(j != 0)
				j = lps[j-1];
    		else
				i = i+1;
		}
	}
}
int main()
{
	char txt[100],pat[100];
	printf("Text : ");
	scanf("%s",txt);
	printf("Pattern : ");
	scanf("%s",pat);
	kmp(txt,pat);
}
