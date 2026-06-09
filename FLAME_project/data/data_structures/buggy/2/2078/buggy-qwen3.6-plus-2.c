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
        if(s[i]==' '||i==len-1){continue;} // @@ The condition `i==len-1` causes the loop to skip processing the last character if it is a digit (part of the last number) or an operator, leading to incorrect parsing of the final operand before '='. Specifically, if the last char is '=', it skips it (which is fine), but if the expression ends with a digit before '=', the logic inside relies on hitting an operator to flush `key`. However, the main issue is that `=` is treated as a non-digit, non-operator in the `else if` chain if not handled, or simply skipped here. Actually, the problem states `=` ends input. The loop continues until `len`. If `s[len-1]` is `=`, this `if` skips it. But the number before `=` needs to be processed. The processing of numbers happens when an operator is encountered. If `=` is skipped, the last number `key` is never added to `ans` via the operator logic. It is only added at the end `ans+=fuhao[m-1]*key;`. However, there is a logical error in how `m` and `fuhao` are managed relative to the last number.
        else if(s[i]>='0'&&s[i]<='9'){//key是保存当前数的变量 
            key=key*10+(s[i]-'0');
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
    {   test1=1;
        if(s[i]=='+'||s[i]=='-')
        {   test3=1;
            if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ Logic error: `fuhao[m]` is uninitialized or irrelevant here. The check `m>0` is correct to see if there's a previous term. But `fuhao[m]` access is out of bounds or meaningless. It should just be `if(m>0)`. More importantly, this line adds the *previous* accumulated term to `ans`.
            if(s[i]=='+')
            {   
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ Duplicate/Incorrect logic. This block is inside `if(s[i]=='+')`. The previous `if` already handled adding the previous term. This structure is flawed. It seems intended to handle the sign storage.
                fuhao[m]=1;
                m++;
                key=0;
            }
            else if(s[i]=='-')
            {
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ Same duplicate/incorrect logic.
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
                key=key/key2;
                key2=0;
            }
            if(s[r]=='*'||s[r]=='/'||s[r]=='+'||s[r]=='-')
            {
                i=r-1;
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
    ans+=fuhao[m-1]*key; // @@ This line is outside the main function's scope due to the closing brace `}` above, causing a compilation error. Even if placed correctly, `fuhao[m-1]` might be invalid if `m` is 0.
    printf("%d",ans);
    return 0;
}