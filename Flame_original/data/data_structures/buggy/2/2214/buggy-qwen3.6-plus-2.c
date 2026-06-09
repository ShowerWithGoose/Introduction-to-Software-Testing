#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 1024
char *qckg(char*,char*);
int main()
{
    char s[LEN],fz[LEN];
    gets(s); // @@ gets is removed in the C11 standard and will cause a compilation error in modern compilers; use fgets(s, LEN, stdin) instead.
    qckg(s,fz);
    int i,j=0,k=0,l=0;
    char cs[100];//用于传输数字到num[] 
    char op[1000];
    int num[1000]; // @@ The array is uninitialized, so checking num[j]!=0 in loops later will access garbage values, causing undefined behavior.
    for(i=0;fz[i]!='\0';i++)
    {
        if(fz[i]>='0'&&fz[i]<='9')
        {
            cs[j++]=fz[i];
        }
        else 
        {
            num[k++]=atoi(cs); // @@ cs is not null-terminated before calling atoi, leading to undefined behavior as atoi reads past the buffer.
            memset(cs,0,sizeof(cs));//清空aq 
            op[l++]=fz[i];
            j=0;
        }
    }
    num[k++]=atoi(cs); // @@ cs is still not null-terminated here, causing the same undefined behavior.
    op[l++]='\0';
    memset(cs,0,sizeof(cs));
    for(i=0;op[i]!='\0';i++)
    {
        if(op[i]=='*')
        {
            num[i]*=num[i+1];
            for(j=i+1;num[j]!=0;j++) // @@ Loop condition relies on uninitialized/garbage values in num, which may cause infinite loops or out-of-bounds access.
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
            for(j=i+1;num[j]!=0;j++) // @@ Same issue: relies on uninitialized num values for loop termination.
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