#include<stdio.h>
#include<string.h>
#define N 100
char s[N],a[N],sgnstk[N];
int numstk[N];
int numt,sgnt;

int priority(char c)
{
    if(c=='*') return 1;
    if(c=='/') return 1;
    if(c=='+') return 0;
    if(c=='-') return 0;
}

void calculate()
{
    int a=numstk[numt--];
    int b=numstk[numt--];
    char c=sgnstk[sgnt--];
    int x;
    x=0;
    if(c=='+') x=a+b;
    else if(c=='-') x=b-a;
    else if(c=='*') x=a*b;
    else if(c=='/') x=b/a;
    numstk[++numt]=x;
}

int main()
{
    gets(s);
    int t=strlen(s);
    int j;
    j=0;
    for(int i=0;i<t;i++)
    {
        if(s[i]!=' '&&s[i]!='=') a[j++]=s[i];
    }
    //printf("%s",a);
    //puts("");
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            int x;
            x=0;
            while(i<len&&a[i]>='0'&&a[i]<='9')
            {
                x=x*10+a[i++]-'0';
            }
            numstk[++numt]=x;
            i--;
        }else
        {
            while(sgnt&&priority(a[i])<=priority(sgnstk[sgnt]))
            calculate();
            sgnstk[++sgnt]=a[i];
        }
    }
    while(sgnt) calculate();
    printf("%d",numstk[numt]);
    return 0;
}


