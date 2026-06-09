#include<stdio.h>
#include<string.h>
char s[1001];
int fuhao[1001]={0};
int main()
{   gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the immediate error is that the program does not handle the '=' terminator correctly—it treats it as part of the expression or ignores it improperly, leading to incorrect parsing. Also, the logic fails when the expression ends with '=', because the final number after the last operator may not be processed correctly.]
    int len=strlen(s);
    int ans=0,i=1,key=0,test1=0,m=0,test2=0,test3=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' '||i==len-1){continue;} // @@ [This skips the last character unconditionally if it's at `len-1`, but the last character is '=', which should signal end-of-expression. However, by skipping it, the final number (if any) before '=' might not be processed properly—especially if there's no space before '='. Also, if the last token is a number ending at `len-2` and `s[len-1]` is '=', this skips processing that number.]
        else if(s[i]>='0'&&s[i]<='9'){//key是保存当前数的变量 
            key=key*10+(s[i]-'0');
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
    {   test1=1;
        if(s[i]=='+'||s[i]=='-')
        {   test3=1;
            if(s[i]=='+')
            {   
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [The condition `fuhao[m]==-1` is invalid because `fuhao[m]` was just initialized to 0 and hasn't been set yet at index `m`. This leads to undefined behavior or incorrect accumulation. Also, the logic for handling signs and accumulating results is flawed—it mixes sign storage with immediate evaluation incorrectly.]
                fuhao[m]=1;
                m++;
                key=0;
            }
            else if(s[i]=='-')
            {
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Same issue as above: accessing `fuhao[m]` before it's assigned in this branch is logically wrong. Also, the accumulation logic doesn't correctly handle operator precedence in all cases.]
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
    ans+=fuhao[m-1]*key; // @@ [If there are no '+' or '-' operators (i.e., `m == 0`), then `fuhao[m-1]` accesses `fuhao[-1]`, which is out-of-bounds and causes undefined behavior. This happens in expressions like "6 * 2 =".]
    printf("%d",ans);
    return 0;
}