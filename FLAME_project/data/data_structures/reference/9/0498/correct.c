#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{

    int a[100],b[100],c[100],d[100],x1,y1,num;
    int f[100];
    int t;
    scanf("%d",&t);
    int i=0,j,k,max;
    while(i<t)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
        i++;
    }
    i=0;
    j=0;
    while(j<t)
    {
        i=0;
        while(i<t-1)
        {
            if(a[i]>a[i+1])
            {
                num=a[i];
                a[i]=a[i+1];
                a[i+1]=num;
                num=b[i];
                b[i]=b[i+1];
                b[i+1]=num;
                num=c[i];
                c[i]=c[i+1];
                c[i+1]=num;
                num=d[i];
                d[i]=d[i+1];
                d[i+1]=num;
            }
            i++;
        }
        j++;
    }
    i=0;
    while(i<t)
    {
        f[i]=1;
        j=i+1;
        k=i;
        while(j<t)
        {
            if(c[k]==a[j]&&d[k]==b[j])
            {
                f[i]++;
                k=j;
            }
            j++;
        }
        i++;
    }
    x1=a[0];
    y1=b[0];
    max=f[0];
    i=1;j=0;
    while(i<t)
    {
        if(f[j]<f[i])
        {
            j=i;
            max=f[i];
            x1=a[i];y1=b[i];
        }
        i++;
    }
    printf("%d %d %d",max,x1,y1);
    return 0;
}


//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）


