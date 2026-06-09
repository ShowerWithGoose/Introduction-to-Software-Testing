#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s;
int a[100];
int A[100];

int b[100];
int B[100];

int c[1000],C[1000];
int main()
{
    int i;
    int j,k;
    int tru=1;
    int maxa,maxb,max,len;
    int num;
    char c1[100],c2[100];
    gets(c1);
    len=strlen(c1);
    i=0;
    j=0;
    while(i<len)
    {
        if(c1[i]>='0'&&c1[i]<='9')
        {
            num=0;
            while(c1[i]>='0'&&c1[i]<='9')
            {
                num*=10;
                num+=c1[i]-'0';
                i++;
            }
            if(tru==1)
            {
                a[j]=num;
                tru++;
            }
            else if(tru==2)
            {
                A[j]=num;
                j++;
                tru--;
            }
        }
        i++;
    }
    maxa=j;
    gets(c2);
    len=strlen(c2);
    i=0;
    j=0;
    while(i<len)
    {
        if(c2[i]>='0'&&c2[i]<='9')
        {
            num=0;
            while(c2[i]>='0'&&c2[i]<='9')
            {
                num*=10;
                num+=c2[i]-'0';
                i++;
            }
            if(tru==1)
            {
                b[j]=num;
                tru++;
            }
            else if(tru==2)
            {
                B[j]=num;
                j++;
                tru--;
            }
        }
        i++;
    }
    maxb=j;
    i=0;
    k=0;
    while(i<maxa)
    {
        j=0;
        while(j<maxb)
        {
            c[k]=a[i]*b[j];
            C[k]=A[i]+B[j];
            k++;
            j++;
        }
        i++;
    }
    max=k;
    i=0;
    while(i<max-1)
    {
        j=0;
        while(j<max-1)
        {
            if(C[j]<C[j+1])
            {
                num=C[j];
                C[j]=C[j+1];
                C[j+1]=num;
                num=c[j];
                c[j]=c[j+1];
                c[j+1]=num;
            }
            j++;
        }
        i++;
    }
    i=0;
    while(i<max)
    {
        num=c[i];
        if(C[i+1]==C[i])
        {
            while(C[i+1]==C[i])
            {
                num+=c[i+1];
                i++;
            }
        }
        printf("%d %d ",num,C[i]);
        i++;
    }
    return 0;
}


//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）


