#include<stdio.h>
#include<string.h>
void fun(int x,int n);
int a[10],b[101],n;
int main()
{
	memset(b,0,101);
    scanf("%d",&n);
    fun(1,n);
    return 0;
}
void fun(int x,int n)
{
    int i;
    if(x==n+1)  
    {  
        for(i=1;i<=n;i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(!b[i]) 
        {
            a[x]=i;  
            b[i]=1;  
            fun(x+1,n);
            b[i]=0;  
        }
    }
    return;
}

