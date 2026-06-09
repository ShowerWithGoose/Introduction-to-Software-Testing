#include<stdio.h>
char s[1000],s1[1000],c[1000];
int number[1000];
int main()
{
    int i,k,flag=0,ans=0;
    gets(s);
    for(i=0,k=0;s[i]!='\0';i++)//挤空格
    {
        if(s[i]!=' ')
        {
            s1[k]=s[i];
            k++;
        }
    }
    for(i=0,k=0;s1[i]!='\0';i++)//将数字和运算符分别存储到两个数组里
    {
        if(s1[i]>='0'&&s1[i]<='9')
        {
            number[flag]=number[flag]*10+s1[i]-'0';//解决关于数字不是一位数的问题※※
        }
        else
        {
            c[k]=s1[i];//存运算符-500+3-2*3
            flag++;
            k++;
        }
    }
    for(i=0;c[i]!='=';i++)
    {
        if(c[i]=='-')
        number[i+1]=-1*number[i+1];
        else if(c[i]=='*')
        {
            number[i+1]=number[i]*number[i+1];
            number[i]=0;
        }
        else if(c[i]=='/')
        {
            number[i+1]=number[i]/number[i+1];
            number[i]=0;
        }
    }
    for(i=0;i<flag;i++)
    {
        ans=ans+number[i];
    }
    printf("%d",ans);
    return 0;
}


