#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 100
int vertex[size],count=1,G[size][size];

int main()
{
	int v;
	scanf("%d",&v);
	FILE *f=fopen("input.txt","w");
	fprintf(f,"%d\n",v);
	fprintf(f,"%d\n",v-1);
	vertex[0]=0;
	int x=v*(v-1)/2;
	srand(time(0));
	x=rand()%x;
	int t=0;
	int l=0;
	while(t<v-1+x)
	{
		srand(time(0));
		int x=rand()%count;
		//printf("%d",x);
		if(G[x%v][count%v]==0)
			{G[x%v][count%v]=1;
			l++;
			printf("%d-%d\n",x%v,count%v);}
		//G[count][x]=1;
		//printf("%d-%d\n",x%v,count%v);
		fprintf(f,"%d %d\n",x%v,count%v);
		vertex[count%v]=count%v;
		count++;
		t++;
	}
	printf("Total edge : %d\nRequired %d",l,0);
	int i,j;
	printf("\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			printf("%d ",G[i][j]);
		printf("\n");}
}
