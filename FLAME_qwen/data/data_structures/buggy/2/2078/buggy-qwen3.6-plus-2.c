#include<stdio.h>
#include<string.h>
char s[1001];
int fuhao[1001]={0};
int main()
{   gets(s); // @@ `gets` is deprecated/removed in modern C standards, causing compilation errors; use `fgets(s, sizeof(s), stdin)` instead.
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
            if(s[i]=='+')
            {   
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ Logical error: condition `fuhao[m]==-1` is meaningless, and accessing `fuhao[m-1]` when `m=0` causes out-of-bounds access. Should be `if(m>0)`.
                fuhao[m]=1;
                m++;
                key=0;
            }
            else if(s[i]=='-')
            {
                if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ Logical error: same as above, flawed condition and risks out-of-bounds access when `m=0`.
                fuhao[m]=-1;
                m++;
                key=0;
            }
        }
        if(s[i]=='*'||s[i]=='/')
        {   test2=1;
            int key2=0,j=i,r=i;
            for(i=r+1;i<len;i++) // @@ Semantic error: modifying the outer loop variable `i` inside this nested loop disrupts the outer loop's iteration control, leading to skipped characters or infinite loops.
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
        if(test1==0) // @@ Logical error: misplaced inside the `for` loop, causing `ans` to be incorrectly overwritten or evaluated repeatedly on each iteration.
        {
            ans=key;//第一个数字 
        }
        if(test3==0)//纯乘除  // @@ Logical error: same as above, misplaced inside the loop leads to incorrect state updates during parsing.
        {
            ans=key;
            key=0;
        }
    }
        ans+=fuhao[m-1]*key; // @@ Runtime error: if `m=0` (expression has no operators), accessing `fuhao[-1]` causes out-of-bounds memory access and undefined behavior.
        printf("%d",ans);
        return 0;
    }