#include<stdio.h>
#include<string.h>
char s[1001];
int fuhao[1001]={0};
int main()
{   gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the primary issue here is logic errors in expression parsing and operator precedence handling.]
    int len=strlen(s);
    int ans=0,i=1,key=0,test1=0,m=0,test2=0,test3=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' '||i==len-1){continue;} // @@ [Skipping the last character (which is '=') without processing the final number leads to missing the last operand.]
        else if(s[i]>='0'&&s[i]<='9'){//key是保存当前数的变量 
            key=key*10+(s[i]-'0');
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
    {   test1=1;
        if(s[i]=='+'||s[i]=='-')
        {   test3=1;
            if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Incorrect accumulation logic: `fuhao[m]` is uninitialized when `m==0`, and indexing `fuhao[m-1]` when `m==0` causes undefined behavior.]
            fuhao[m]=1;
            m++;
            key=0;
        }
        else if(s[i]=='-')
        {
            if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Same as above: accessing `fuhao[m-1]` when `m` could be 0 is invalid. Also, condition `fuhao[m]==-1` checks an uninitialized value.]
            fuhao[m]=-1;
            m++;
            key=0;
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
    ans+=fuhao[m-1]*key; // @@ [If there are no '+' or '-' operators (`m == 0`), then `fuhao[m-1]` accesses `fuhao[-1]`, which is out-of-bounds and undefined behavior.]
    printf("%d",ans);
    return 0;
}