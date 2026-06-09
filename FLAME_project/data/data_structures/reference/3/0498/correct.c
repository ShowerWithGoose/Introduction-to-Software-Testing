#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char c[100];
    scanf("%s",&c);
    int i=0;
    int m=0;
    int j=0;
    int len=strlen(c);
    while(i<len)
    {
        if(c[i]=='.')
        {
            m=1;
        }
        i++;
    }
    if(m==0)
    {
        printf("%c",c[0]);
        i=1;
        if(i!=len)
        {
            printf(".");
        }
        while(i<len)
        {
            printf("%c",c[i]);
            i++;
        }
        printf("e%d",len-1);
        return 0;
    }
    if(c[0]=='0')
    {
        i=2;
        while(i<len)
        {
            if(c[i]!='0')
            {
                break;
            }
            i++;
            m++;
        }
        printf("%c",c[i]);
        i++;
        if(i!=len)
        {
            printf(".");
        }
        while(i<len)
        {
            printf("%c",c[i]);
            i++;
        }
        printf("e-%d",m);
    }
    else
    {
        m=0;
        i=1;
        while(i<len)
        {
            if(c[i]!='.')
            {
                m++;
            }
            else
            {
                break;
            }
            i++;
        }
        j=i;
        while(j>1)
        {
            c[j]=c[j-1];
            j--;
        }
        c[j]='.';
        i=0;
        while(i<len)
        {
            printf("%c",c[i]);
            i++;
        }
        printf("e%d",m);
    }
    return 0;
}

//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）

