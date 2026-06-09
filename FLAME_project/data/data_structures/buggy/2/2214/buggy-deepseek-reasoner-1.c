#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 1024
char *qckg(char*,char*);
int main()
{
    char s[LEN],fz[LEN];
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
            op[l++]=fz[i]; // @@ [将表达式末尾的'='当作运算符存入，导致运算符数组长度错误，并影响后续数字解析]
            j=0;
        }
    }
    num[k++]=atoi(cs); // @@ [在'='被处理后cs已清空，此处多存储一个0，破坏数字数组结构]
    op[l++]='\0';
    memset(cs,0,sizeof(cs));
    for(i=0;op[i]!='\0';i++)
    {
        if(op[i]=='*')
        {
            num[i]*=num[i+1];
            for(j=i+1;num[j]!=0;j++) // @@ [循环条件使用num[j]!=0，当num[i+1]为0时无法移动后续数字，导致乘除运算后数字顺序错误]
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
            for(j=i+1;num[j]!=0;j++) // @@ [除法中同样错误，条件导致数字移动不完整]
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