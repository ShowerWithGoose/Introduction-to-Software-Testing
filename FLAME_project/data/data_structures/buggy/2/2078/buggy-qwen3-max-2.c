#include<stdio.h>
#include<string.h>
char s[1001];
int fuhao[1001]={0};
int main()
{   gets(s);
    int len=strlen(s);
    int ans=0,i=1,key=0,test1=0,m=0,test2=0,test3=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' '||i==len-1){continue;}
        else if(s[i]>='0'&&s[i]<='9'){//key是保存当前数的变量 
            key=key*10+(s[i]-'0');
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
    {   test1=1;
        if(s[i]=='+'||s[i]=='-')
        {   test3=1;
            if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [This condition is flawed: when m==0 and fuhao[0] is uninitialized (0), it skips adding the first term correctly. Also, fuhao[m] is checked before being set.]
                fuhao[m]=1;
                m++;
                key=0;
            }
            else if(s[i]=='-')
            {
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Same issue as above: incorrect handling of the first term before any operator is processed.]
                fuhao[m]=-1;
                m++;
                key=0;
            }
        }
        if(s[i]=='*'||s[i]=='/')
        {   test2=1;
            int key2=0,j=i,r=i;
            for(i=r+1;i<len;i++)
            {
                if(s[i]>='0'&&s[i]<='9'){key2=10*key2+(s[i]-'0');}//把后一个数读完 
                else if(s[i]==' '){continue;}
                else 
                {   r=i;
                    break;
                }
            }
            if(s[j]=='*')
            {
                key=key*key2;
                key2=0;
            }
            else if(s[j]=='/')
            {
                key=key/key2; // @@ [Integer division is correct per problem, but key2 might be 0 if parsing fails, though input is valid so this may not trigger. However, more critically, after processing * or /, the loop index 'i' is manipulated in a way that may skip characters or cause misalignment.]
                key2=0;
            }
            if(s[r]=='*'||s[r]=='/'||s[r]=='+'||s[r]=='-')
            {
                i=r-1; // @@ [This adjustment of loop variable 'i' inside the for-loop causes the outer loop to skip the next operator or digit, leading to incorrect parsing. For example, after processing "20*30", it may skip the '-' that follows.]
            }
        }
    }
    if(test1==0)
    {
        ans=key;//第一个数字 
    }
    if(test3==0)//纯乘除 
    {
        ans=key;
        key=0;
    }
}
    ans+=fuhao[m-1]*key; // @@ [If there are no '+' or '-' operators (test3==0), fuhao array is never filled, so fuhao[m-1] accesses uninitialized memory (likely 0), causing ans to be set to 0 + 0*key = 0, which is wrong. But in this test case, test3 is 1, so the real issue is earlier accumulation.]
    printf("%d",ans);
    return 0;
}