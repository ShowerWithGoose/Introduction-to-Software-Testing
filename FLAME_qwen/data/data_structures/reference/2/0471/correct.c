#include <stdio.h>
char a[100];
int num[100]={0},k=0;
void deletespace(char *x)
{
    char *p=a;
    int i=0,j=0;
    while(*(x+i)!='\0')
    {
        if(*(x+i)!=' ')
            a[j++]=*(x+i);
        i++;
    }
}
void getnum(char *x)
{
    int i=0;
    while(*(x+i)!='=')
    {
        if(*(x+i)>='0'&&*(x+i)<='9')
        {
            num[k]*=10;
            num[k]+=*(x+i)-'0';
        }
        else
        {
            k++;
        }
        i++;
    }
}
void calcul(char *x)
{
    int i=0,j=0,l=0,m=0;
    while(*(x+i)!='=')
    {
        if(*(x+i)=='-'||*(x+i)=='+'||*(x+i)=='*'||*(x+i)=='/')
        {
            j++;//j表示运算符数量（不算乘除）
            if(*(x+i)=='*'||*(x+i)=='/')
            {
                l=0;
                if(*(x+i)=='*')
                {
                    num[j-1]*=num[j];
                    while(l+j<k)
                    {
                        num[l+j]=num[l+j+1];
                        l++;
                    }
                    k--;
                }
                else
                {
                    num[j-1]/=num[j];
                    while(l+j<k)
                    {
                        num[l+j]=num[l+j+1];
                        l++;
                    }
                    k--;
                }
                j--;
            }
        }
        i++;
    }
    i=0;
    while(m<j)
    {
        if(*(x+i)=='+'||*(x+i)=='-')
        {
            m++;
            l=1;
            if(*(x+i)=='+')
            {
                num[0]+=num[1];
                while(l<k)
                {
                    num[l]=num[l+1];
                    l++;
                }
            }
            else
            {
                num[0]-=num[1];
                while(l<k)
                {
                    num[l]=num[l+1];
                    l++;
                }
            }
        }
        i++;
    }
}
int main()
{
    char s[100],*p1=s,*p2=a;
    gets(s);
    deletespace(p1);
    getnum(p2);
    calcul(p2);
    printf("%d",num[0]);
    return 0;
}



