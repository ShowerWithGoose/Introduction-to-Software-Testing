#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[1000],c[1000],op[1000];
int num[1000];
int i,j,k=0;
void de(char s[])
{
    int m,n=0;
    for(m=0; s[m]!='\0'; m++)
        if(s[m]!=' ')
            c[n++]=s[m];
    c[n]='\0';
}
void fun1()
{
    if(c[0]!='-')
    {
        for(i=0; c[i]!='\0'; i++)
        {
            if(c[i]<='9'&&c[i]>='0')
                num[k]=num[k]*10+c[i]-'0';
            else
            {
                op[++k]=c[i];
                k++;
            }
        }
    }
    else
    {
        for(i=1; c[i]!='\0'; i++)
        {
            if(c[i]<='9'&&c[i]>='0')
                num[k]=num[k]*10+c[i]-'0';
            else
                op[++k]=c[i];
        }
        num[0]=-num[0];
    }
}
void fun2()
{
    for(j=0; j<k; j++)
    {
        if(op[j]=='*')
        {
            num[j-1]*=num[j+1];
            for(i=j+2; i<k; i++)
            {
                op[i-2]=op[i];
                num[i-2]=num[i];
            }
            j--;
        }
        if(op[j]=='/')
        {
            num[j-1]/=num[j+1];
            for(i=j+2; i<k; i++)
            {
                op[i-2]=op[i];
                num[i-2]=num[i];
            }
            j--;
        }

    }
    for(j=0; j<k; j++)
    {
        if(op[j]=='+')
        {
            num[j-1]+=num[j+1];
            for(i=j+2; i<k; i++)
            {
                op[i-2]=op[i];
                num[i-2]=num[i];
            }
            j--;
        }
        if(op[j]=='-')
        {
            num[j-1]-=num[j+1];
            for(i=j+2; i<k; i++)
            {
                op[i-2]=op[i];
                num[i-2]=num[i];
            }
            j--;
        }

    }
}
int main()
{
    gets(c);
    de(c);
    //×ª»»×Ö·û
    fun1();
    fun2();
    printf("%d",num[0]);
    return 0;
}



