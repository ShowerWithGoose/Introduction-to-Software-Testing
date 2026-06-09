#include <stdio.h>
#include <stdlib.h>
#include<string.h>

char str[10000],b[10000];
int a[10000],sum=0;
int pre(char);
int func(char,int,int);
int main()
{
    gets(str);
    int i=-1,j=-1,len=strlen(str),k=0,m=0,num=1,sum=0;
    char *p=str;
    for(;*p!='\0';p++)
    {
        k=0,num=1,sum=0;
        if(*p>='0'&&*p<='9')
        {
            i++;
            while(*(p+k+1)>='0'&&*(p+k+1)<='9')
            {
                k++;
            }
            for(m=k;m>=0;m--)
            {
                sum+=(*(p+m)-'0')*num;
                num*=10;
            }
            a[i]=sum;
            p=p+k;
        }
        else if(*p==' ');
        else b[++j]=*p;
    }
    for(k=0,m=0;k<=j-1;k++)
    {
        if(b[k+1] == '=')
        {
            a[m+1]=func(b[k],a[m],a[m+1]);
            m++;
            break;
        }
        if(pre(b[k])>=pre(b[k+1]))
        {
            a[m+1]=func(b[k],a[m],a[m+1]);
            m++;
        }

        else if(pre(b[k])<pre(b[k+1]))
        {
            int flag1=k+1,flag2=k+1,flag3=m+1;
            while(pre(b[flag1+1])>pre(b[k])&& b[flag1+1]!='=')
            {
                flag1++;
            }
            for(;flag2<=flag1;flag2++)
            {
                a[flag3+1]=func(b[flag2],a[flag3],a[flag3+1]);
                flag3++;
            }
            a[flag3]=func(b[k],a[m],a[flag3]);
            k=flag1,m=flag3;
        }
    }
    printf("%d",a[m]);
    return 0;
}


int pre(char c)
{
    if(c=='*'||c=='/') return 1;
    else if(c=='-'||c=='+') return 0;
}

int func(char c,int i,int j)
{
    if(c=='*') return (i*j);
    else if(c=='/') return(i/j);
    else if(c=='+') return(i+j);
    else if(c=='-') return(i-j);
}



