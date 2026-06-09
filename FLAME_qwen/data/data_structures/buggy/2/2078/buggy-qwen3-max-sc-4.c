#include<stdio.h>
#include<string.h>
char s[1001];
int fuhao[1001]={0};
int main()
{   gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the immediate error is that the program does not handle the '=' terminator correctly, leading to incorrect parsing. Also, the logic for handling operators and numbers is flawed.]
    int len=strlen(s);
    int ans=0,i=1,key=0,test1=0,m=0,test2=0,test3=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' '||i==len-1){continue;} // @@ [Skipping the last character (which is '=') without processing the final number leads to loss of the last operand. The condition `i==len-1` causes the loop to skip processing the last number before '='.]
        else if(s[i]>='0'&&s[i]<='9'){//key是保存当前数的变量 
            key=key*10+(s[i]-'0');
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
    {   test1=1;
        if(s[i]=='+'||s[i]=='-')
        {   test3=1;
            if(s[i]=='+')
            {   
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [The logic for accumulating `ans` is incorrect. It uses `fuhao[m-1]` before `m` is properly set for the current operator, and the condition `fuhao[m]==-1` accesses uninitialized memory since `fuhao` is zero-initialized.]
                fuhao[m]=1;
                m++;
                key=0;
            }
            else if(s[i]=='-')
            {
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Same issue as above: accessing `fuhao[m]` when `m` hasn't been incremented yet, and `fuhao` is zero-initialized so `fuhao[m]==-1` is always false. This leads to incorrect accumulation.]
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
    ans+=fuhao[m-1]*key; // @@ [After the loop, this line tries to add the last term, but if the expression ends with '=', and the last number was skipped due to `i==len-1` continue, then `key` may be 0 or incomplete. Also, if there are no '+'/'-' operators (`m==0`), then `fuhao[m-1]` accesses `fuhao[-1]`, which is out-of-bounds and undefined behavior.]
    printf("%d",ans);
    return 0;
}