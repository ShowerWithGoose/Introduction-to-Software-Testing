#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#include<stddef.h>

#define N 30000
int f(char *p,char *r);
int g(char *p,char *q);
char* find(char *p,char *q);
char* find_(char *p,char *q);
int number(char *p,char *q);
int main()
{
    char s[N];
    gets(s);
    int i,j;
    for(i=0,j=0;i<strlen(s)-1;i++)
    {
        if(s[i]!=' ') s[j++]=s[i];
    }
    s[j]='\0';
    printf("%d",f(s,s+j-1));
}

int f(char *p,char *q)//计算答案
{
    char *r;
    r=find_(p,q);
    if(r!=p) 
    {
        if(*r=='+') return f(p,r-1)+g(r+1,q);
        else return f(p,r-1)-g(r+1,q);
    }
    else {return g(p,q);}
}

int g(char *p,char *q)//计算连续乘法除法
{
    char *r;
    r=find(p,q);
    if(r==p)
    {
        return number(p,q);
    }
    else
    {
        if(*r=='*') return g(p,r-1)*number(r+1,q);
        else return g(p,r-1)/number(r+1,q);
    }
}

char* find(char *p,char *q)
{
    char *r;
    int i=0;
    for(r=q;r>=p;r--)
    {
        if ((*r=='*')||(*r=='/')) {i=1;return r;}
    }
    if(i==0) return p;
}

int number(char *p,char *q)
{
    int s=0;
    char *k;
    for(k=p;k<=q;k++)
    {
        s=10*s+(*k)-'0';
    }
    return s;
}

char* find_(char *p,char *q)
{
    char *r;
    int i=0;
    for(r=q;r>=p;r--)
    {
        if ((*r=='+')||(*r=='-')) {i=1;return r;}
    }
    if(i==0) return p;
}
