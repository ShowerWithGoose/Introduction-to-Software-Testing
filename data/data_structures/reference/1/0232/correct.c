//全排列
#include<stdio.h>

int print(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return ;
}
void perm(int n,int *a,int *b,int index)
{
    if(index==n)
    {
        print(a,n);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(!b[i])
        {
            a[index]=i+1;//哈哈！是index!!!以及区分序号和大小（加一）！！
            b[i]=1;
            perm(n,a,b,index+1);
            b[i]=0;
        }
    }
}

int main()
{
    int n,a[10],b[10]={0};
    scanf("%d",&n);
    perm(n,a,b,0);
    return 0;
}






