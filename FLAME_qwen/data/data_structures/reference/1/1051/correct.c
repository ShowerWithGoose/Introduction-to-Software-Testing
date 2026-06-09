#include<stdio.h>

int i,n;
int num[50];
int mark[50];

void print(int a[])
{
    for(i=0;i<n-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d",num[n-1]);
    printf("\n");
}


void dfs(int i,int a[])
{
	if(i==n)
    {
        print(a);
		return ;
	} 
	int m;
	for(m=0;m<n;m++)
    {
		if(mark[m])
        {
			a[i]=m+1;
			mark[m]=0; 
			dfs(i+1,a);
	  		mark[m]=1;
		} 		
	}
}


int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        mark[i]=1;
        num[i]=0;
    }
    dfs(0,num);
    return 0;
}



