#include<stdio.h>
int numb[1000]={0}; 
char ss[1000]={};
int main()
{
    char s[1000];
    gets(s);
    int a=0,j=0,k=0,i,ans;
    for(i=0;s[i]!='=';i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            a=a*10+(s[i]-'0'); 
        }
        else if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))
        {
            numb[j++]=a;
            a=0; 
            ss[k++]=s[i]; 
        }
    }
    numb[j]=a;
    j++;
    if(k==0)
        printf("%d",a);
    else
    {
        for(i=0;i<k;i++)
        {
            if(ss[i]=='/')
            {
                numb[i+1]=numb[i]/numb[i+1];
                numb[i]=0;
                if(i!=0)
                {
                    ss[i]=ss[i-1];  // @@ [Error: The original code used '==' (comparison) instead of '=' (assignment). This line intends to mark the current operator position as processed by inheriting the previous operator's status or simply neutralizing it, but syntactically it did nothing. More importantly, the logic of inheriting ss[i-1] is flawed for standard precedence handling where we usually just want to ignore the consumed operator in the second pass. However, the critical syntax error is == vs =.]
                }
                else
                {
                    ss[i]='+'; // @@ [Error: The original code used '==' (comparison) instead of '=' (assignment). This line attempts to set the operator to '+' if it's the first element, but failed to assign due to syntax error.]
                }
            }
            else if(ss[i]=='*')
            {
                numb[i+1]=numb[i]*numb[i+1];
                numb[i]=0;
                if(i!=0)
                {
                    ss[i]=ss[i-1]; // @@ [Error: The original code used '==' (comparison) instead of '=' (assignment). Similar to the division case, this fails to update the operator array correctly.]
                }
                else
                {
                    ss[i]='+'; // @@ [Error: The original code used '==' (comparison) instead of '=' (assignment). Fails to assign '+' to the first operator slot.]
                }
            }
        }
        ans=numb[0];
        for(i=0;i<k;i++)
        {
            if(ss[i]=='-')
            {
                ans=ans-numb[i+1];
            }
            else
            {
                ans=ans+numb[i+1];
            }
        }
        printf("%d",ans);
    }
    return 0;
}