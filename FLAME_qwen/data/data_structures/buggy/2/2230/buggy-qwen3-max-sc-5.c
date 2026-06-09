#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000000];
char op[1000000];
char aq[1000000];
int num[1000000];
void fun(char *str)
{
    int i=0;
    char *p=str; 
    while(*p)
    {
        if(*p!=' ')
        str[i++]=*p;
        p++;
    }
    str[i]='\0';
}
int main()
{
    int res=0;
    int k,j=0,a=0,b=0;
    gets(s); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets()` is not available, leading to a compilation error.]
    fun(s);
    for(k=0;s[k]!='\0';k++)
    {
        if(s[k]>='0'&&s[k]<='9')
        aq[j++]=s[k];
        else
        {
            num[b++]=atoi(aq);
            memset(aq,0,sizeof(aq));
            op[a++]=s[k];
            j=0;
        }
    }
    num[b++]=atoi(aq);
    op[a]='\0';
    int n,m;
    for(n=0;op[n]!='\0';n++)
    {
        if(op[n]=='*')
        {
            for(m=n;op[m]!='\0';m++)
            {
                op[m]=op[m+1];
            }
            num[n]=num[n]*num[n+1];
            for(m=n+1;num[m]!=-1;m++) // @@ [The condition `num[m]!=-1` is incorrect because the array `num` is never initialized with -1 as a sentinel. This leads to undefined behavior when accessing beyond valid data, possibly causing infinite loops or segmentation faults.]
            {
                num[m]=num[m+1];
            }
            n--;
        }
        else if(op[n]=='/')
        {
            for(m=n;op[m]!='\0';m++)
            {
                op[m]=op[m+1];
            }
            num[n]=num[n]/num[n+1];
            for(m=n+1;num[m]!=-1;m++) // @@ [Same error as above: using `num[m]!=-1` as loop condition is invalid since `num` isn't terminated with -1.]
            {
                num[m]=num[m+1];
            }
            n--;
        }
    }
        res=num[0];
        int t;
        for(t=0;op[t]!='\0';t++)
        {
            if(op[t]=='+')
            res=res+num[t+1] ;
            else if(op[t]=='-')
            res=res-num[t+1];
        }
    printf("%d",res);
    return 0;
}