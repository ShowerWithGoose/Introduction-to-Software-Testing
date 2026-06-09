#include<stdio.h>  

#define x 10
int biaoji[x]={0};
int a[100]={0};
void rank(int ,int);
int N;
int main()
{  scanf("%d",&N);
    rank(0,N);
    return 0;  
}
void rank(int m,int n)
{  int i;
    if(n==0)
	   {for(i=0;i<N;i++)
	   {
	   	printf("%d ",a[i]);
	   }
	    printf("\n");
	    return ;
        }
        for(i=1;i<=N;i++)
	{
		if(biaoji[i]==0)//i未使用 
		{biaoji[i]=1;//使用i 
		a[m]=i;//将i放在m位 
		rank(m+1,n-1);//继续m+1位放置 
		biaoji[i]=0;//让i再次可以使用 
		}
	}	
}

