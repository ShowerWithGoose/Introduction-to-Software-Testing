#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int f();
int a[15];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        a[i]=i;
        printf("%d ",i);
    }
    printf("\n");
    while(f())
    {
        for(int i=1;i<n;++i)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n]);
    }
    return 0;
}
int f()
{
    for(int i=n;i>1;--i)
    {
        if(a[i-1]<a[i])
        {
            int min=i;
            for(int j=i+1;j<=n;++j)
            {
                if(a[j]>a[i-1])
                {
                    min=j;
                }
                else
                {
                    break;
                }
            }
            int t=a[min];
            a[min]=a[i-1];
            a[i-1]=t;
            for(int j=i,k=n;j<k;++j,--k)
            {
                t=a[j];
                a[j]=a[k];
                a[k]=t;
            }
            return 1;
        }
    }
    return 0;
}
//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）

