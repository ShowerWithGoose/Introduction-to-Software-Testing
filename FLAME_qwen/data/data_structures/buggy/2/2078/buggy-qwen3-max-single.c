#include<stdio.h>
#include<string.h>
char s[1001];
int fuhao[1001]={0};
int main()
{   gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the primary issue here is logic errors in expression parsing, not compilation. But note: the reported error was "gcc: not found", which is environment-related, not code-related. However, based on problem context, we focus on logical bugs causing wrong output.]
    int len=strlen(s);
    int ans=0,i=1,key=0,test1=0,m=0,test2=0,test3=0;
    for(i=0;i<len;i++)
    {
        if(s[i]==' '||i==len-1){continue;} // @@ [Skipping the last character (which is '=') without processing the final number before it. This causes the last number to be ignored if it's right before '='.]
        else if(s[i]>='0'&&s[i]<='9'){//key is saving current number 
            key=key*10+(s[i]-'0');
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
    {   test1=1;
        if(s[i]=='+'||s[i]=='-')
        {   test3=1;
            if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Incorrect condition: `fuhao[m]` is uninitialized when m==0, and logic for applying signs is flawed. Also, `fuhao` stores 1 or -1, but indexing and accumulation are inconsistent.]
            fuhao[m]=1;
            m++;
            key=0;
        }
        else if(s[i]=='-')
        {
            if(m>0||fuhao[m]==-1){ans+=fuhao[m-1]*key;} // @@ [Same flawed condition as above; also, this block is unreachable because the `if(s[i]=='+')` already handled '+' and the `else if` for '-' is inside the same outer `if` for '+'/'-', so structure is broken.]
            fuhao[m]=-1;
            m++;
            key=0;
        }
        if(s[i]=='*'||s[i]=='/') // @@ [This `if` is not `else if`, so after handling '+' or '-', it will also enter this block if operator is '+' or '-', which is wrong. Should be `else if`.]
        {   test2=1;
            int key2=0,j=i,r=i;
            for(i=r+1;i<len;i++)
            {
                if(s[i]>='0'&&s[i]<='9'){key2=10*key2+(s[i]-'0');}//read next number 
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
        ans=key;//first number 
    }
    if(test3==0)//only * and /
    {
        ans=key;
        key=0;
    }
}
    ans+=fuhao[m-1]*key; // @@ [If there are no '+'/'-' operators (m==0), then `fuhao[m-1]` accesses `fuhao[-1]`, which is invalid and causes undefined behavior.]
    printf("%d",ans);
    return 0;
}