#include<stdio.h>
#include<string.h>
#include<ctype.h>

int arithmetic(char ch,int a,int b);
int res;

int main()
{
    char s0[100],s1[100],ch[100],ch1[100];
    int num[100],num1[100];
    gets(s0);
    int len=strlen(s0);
    int i,j=0,k=0,m=0,ans,sum;
    for(i=0;i<len;i++)
    {
        if(s0[i]!=' ')
        {
            s1[j]=s0[i];
            j++;
        }
    }
    s1[j]='\0';
    //printf("%s",s1);
    j=0;
    int len1=strlen(s1);
    for(i=0;i<len1;i++)
    {
        if(isdigit(s1[i])!=0)
        {
            ans=s1[i]-'0';
            i++;
            while(isdigit(s1[i])!=0)
            {
                ans=ans*10+s1[i]-'0';
                i++;
            }
            num[j]=ans;
            j++;

       }
    }
    /*for(i=0;i<j;i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");*/

    for(i=0;i<len1;i++)
    {
        if(isdigit(s1[i])==0)
        {
            ch[k]=s1[i];
            k++;
        }
    }

    /*for(i=0;i<k;i++)
    {
        printf("%c ",ch[i]);
    }
    printf("\n");*/

    //printf("%d %d",j,k);
    k=0;
    for(i=0;i<j;i++)
    {
        if(ch[i]=='+'||ch[i]=='-'||ch[i]=='=')
        {
            num1[k]=num[i];
            k++;
        }else {
            num1[k]=arithmetic(ch[i],num[i],num[i+1]);
            i++;
            while(ch[i]=='*'||ch[i]=='/')
            {
                num1[k]=arithmetic(ch[i],num1[k],num[i+1]);
                i++;
            }
            k++;
        }

    }

    for(i=0;i<j-1;i++)
    {
        if(ch[i]=='+'||ch[i]=='-')
        {
            ch1[m]=ch[i];
            m++;
        }
    }


    sum=num1[0];
    for(i=0;i<m;i++)
    {
        sum=arithmetic(ch1[i],sum,num1[i+1]);
    }

    printf("%d",sum);

    return 0;
}

int arithmetic(char ch,int a,int b)
{
    if(ch=='*')
    {
        res=a*b;
    }else if(ch=='/')
    {
        res=a/b;
    }else if(ch=='+')
    {
        res=a+b;
    }else if(ch=='-')
    {
        res=a-b;
    }
    return res;

}







