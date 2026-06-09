#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 1024
char *qckg(char*,char*);
int main()
{
    char s[LEN],fz[LEN];u // @@ Invalid syntax: stray 'u' after semicolon causes compilation error.
    gets(s);
    qckg(s,fz);
    int i,j=0,k=0,l=0;
    char cs[100];//用于传输数字到num[] 
    char op[1000];
    int num[1000];
    for(i=0;fz[i]!='\0';i++)
    {
        if(fz[i]>='0'&&fz[i]<='9')
        {
            cs[j++]=fz[i];
        }
        else 
        {
            num[k++]=atoi(cs);
            memset(cs,0,sizeof(cs));//清空aq 
            op[l++]=fz[i]; // @@ Stores the '=' operator (the terminating symbol) as a regular operator, which should not be processed. This can cause incorrect indexing and unexpected behavior in later loops.
            j=0;
        }
    }
    num[k++]=atoi(cs);
    op[l++]='\0';
    memset(cs,0,sizeof(cs));
    for(i=0;op[i]!='\0';i++)
    {
        if(op[i]=='*')
        {
            num[i]*=num[i+1];
            for(j=i+1;num[j]!=0;j++) // @@ Incorrect condition: using `num[j]!=0` to decide shifting can stop early when a number is zero, causing incorrect array compaction and wrong computation.
            {
                num[j]=num[j+1];//数字递进 
            }
            for(j=i;op[j]!='\0';j++)
            {
                op[j]=op[j+1];//符号递进 
            }
            i--;
        }
        if(op[i]=='/')
        {
            for(j=i;op[j]!='\0';j++)
            {
                op[j]=op[j+1];//符号递进即去除所有的除号 
            }
            num[i]/=num[i+1];
            for(j=i+1;num[j]!=0;j++) // @@ Same incorrect condition as above: using `num[j]!=0` for shifting can skip zeros and misalign the number array.
            {
                num[j]=num[j+1];
            }
            i--;
        }
    }
    int outcome=num[0];
    for(i=0;op[i]!='\0';i++)
    {
        if(op[i]=='+')
        outcome+=num[i+1];
        if(op[i]=='-')
        outcome-=num[i+1];//进行加减运算 
    }
    printf("%d",outcome);
    return 0;
}
char *qckg(char *s,char *fz)
{
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            fz[j++]=s[i];
        }
    }
    fz[j]='\0';
    return fz;
}