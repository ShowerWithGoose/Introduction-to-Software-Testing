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
                    ss[i]==ss[i-1]; // @@ 使用了比较运算符==，应改为赋值运算符=，否则无法正确更新运算符数组，导致后续加减法结果错误
                }
                else
                {
                    ss[i]=='+'; // @@ 使用了比较运算符==，应改为赋值运算符=，否则无法将当前运算符修改为'+'，导致后续加减法逻辑错误
                }
            }
            else if(ss[i]=='*')
            {
                numb[i+1]=numb[i]*numb[i+1];
                numb[i]=0;
                if(i!=0)
                {
                    ss[i]==ss[i-1]; // @@ 使用了比较运算符==，应改为赋值运算符=，错误同上
                }
                else
                {
                    ss[i]=='+'; // @@ 使用了比较运算符==，应改为赋值运算符=，错误同上
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