#include<stdio.h>
#define N 3
int b[N][2],a[N][N];

//int Iteration;
void Sorting()
{
   int i,j;
   for(i=0;i<N;i++)
   {
     for(j=0;j<N-1;j++)
     {
         if(b[j][0]>=b[j+1][0])
         {
             int x,y;
             x=b[j][0];
             y=b[j][1];
             b[j][0]=b[j+1][0];
             b[j][1]=b[j+1][1];
             b[j+1][0]=x;
             b[j+1][1]=y;
         }
     }
   }
}


void duplicate(int i )
{   int j;
    for(j=0;j<N;j++)
    {
        b[j][0]=a[j][i];
        b[j][1]=j;
    }
}

void Print(int k)
{   int i,j;
	printf("\nAfter converting column %d into zeros :\n",k+1);
     for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%1d ",a[i][j]);
        }
        printf("\n");
    }
}

int Power(int p)
{
    int i,s=1;
    for(i=0;i<p;i++)
    {
       s=s*2;
    }
    return s;
}

void Minus(int i)
{       int l,x;
        x= a[0][i];
       for(l=0;l<N;l++)
        {
            a[l][i]=a[l][i]-x;
        }  
      //  Iteration+=x;
}

int factor(int  p)
{
    int k=0;
    while(p!=1)
    {
        p=p/2;
        k++;
    }
    return k;
}

void mul_2(int j,int p)
{
    int  i;
    for(i=0;i<N;i++)
        a[j][i]=a[j][i]*Power(p);
   // Iteration+=p;
}

void sub_1(int m,int i)
{   int j=0;
    for(j=0;j<N;j++)
    {
        b[j][0]=(b[j][0])- m;
        a[j][i]=a[j][i]-m;

    }
   // Iteration+=m;
}


void change(int i)
{  
    int y,z,m,w,p,j;
    
    int c;

    for(c=0;c<N-1;c++)
    {
        
       while(b[c][0]!=b[c+1][0])
        {  
            m=b[c][0]-1;   
           for(j=0;j<N;j++)
            {
                b[j][0]=b[j][0]-m;
                a[j][i]=a[j][i]-m;
            }
           // Iteration+=m;
         
            p = factor(b[c+1][0]); 

           for(w=0;w<=c;w++)
                   {
                        z=b[w][1];
                        b[w][0]=(b[w][0])*Power(p);
                        mul_2(z,p);            
                   }
           
        }

    }
}
int main()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
   
    for(i=0;i<N;i++)
    {
        duplicate(i);
        Sorting();
        change(i);
        Minus(i);
        Print(i);
    }
   // printf("%d \n",Iteration);
    
    
}


