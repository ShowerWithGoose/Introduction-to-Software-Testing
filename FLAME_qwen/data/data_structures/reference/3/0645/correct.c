#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

#define N 30000
char* find(char *p,char *q);
char* find_(char *p,char *q);
int main()
{
    char s[N];
    gets(s);
    int len=strlen(s);
    char *p, *q;
    p=find(s,s+len-1);
    q=find_(s,s+len-1);
    if(q==s)
    {
        int i=p-q-1;
        if(i==0) printf("%se0",s);
        else
        {
            *p='\0';
            printf("%c.%s%se%d",*q,q+1,p+1,i);
        }
    }
    else
    {
        int i=q-p;
        if(q==s+len-1) printf("%ce-%d",*q,i);
        else 
        {
            printf("%c.%se-%d",*q,q+1,i);
        }
    }
}

char* find(char *p,char *q)
{
    char *r;
    for(r=p;r<=q;r++)
    {
        if(*r=='.') return r;
    }
}

char* find_(char *p,char *q)
{
    char *r;
    for(r=p;r<=q;r++)
    {
        if((*r>='1')&&(*r<='9')) return r;
    }
}
