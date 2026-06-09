#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[100],str[100];
    gets(str);
    int i=0,j=0,k;
    int a[100];
    int sum;
    char c[100];
    while(i<strlen(str))
    {
        if(str[i]!=' ')
        {
            s[j++]=str[i];
        }
        i++;
    }
    s[j]='\0';
    i=0;j=0;
    while(i<strlen(s))
    {
        sum=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            sum=sum*10+s[i]-'0';
            i++;
        }
        a[j]=sum;
        c[j]=s[i];
        j++;i++;
    }
    k=j;
    j=0;
    while(j<k)
    {
        if(c[j]=='*')
        {
            a[j+1]=a[j]*a[j+1];
            a[j]=0;
            c[j]='+';
            if(c[j-1]=='-'&&j>=1)
            {
                c[j]='-';
            }
        }
        else if(c[j]=='/')
        {
            a[j+1]=a[j]/a[j+1];
            a[j]=0;
            c[j]='+';
            if(c[j-1]=='-'&&j>=1)
            {
                c[j]='-';
            }
        }
        j++;
    }
    j=0;
    sum=a[0];
    while(j<k)
    {
        if(c[j]=='+')
        {
            sum+=a[j+1];
        }
        else if(c[j]=='-')
        {
            sum-=a[j+1];
        }
        j++;
    }
    printf("%d",sum);
    return 0;
}

//scanf记得加&，printf没有&，输出特殊字符要"/"
//memset(a,0,sizeof(a));数组置零（任意数值均可）
//strcpy(a,b);将b拷贝到a(数组或地址拷贝，单个元素不行）

