#include <stdio.h>
#include <string.h>
char s[10005];
int a[10000];
char b[10000];
int c[20000];
char d[20000];
int main()
{
    int len,i,j,k,t,m,n,p,num=0,ans=1,res=0;
    gets(s);
    len=strlen(s);
    b[0]='?';
    for(i=0,j=0;i<len;)
    {
        if(s[i]!=' ')
        s[j++]=s[i++];    
        else
        i++;    
    }
    s[j]='\0';
    len=strlen(s);
    num=s[0]-'0';
    for(k=0,t=1;k<len;)
    {
        if(s[k+1]>='0'&&s[k+1]<='9')
        {
            num=num*10+s[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=s[k+1];
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';)
    {
        if(b[m]=='+'||b[m]=='-'||b[m]=='=')
        {
            c[n]=a[m];
            d[n]=b[m];
            n++;
            m++;
        }
        else if(b[m]=='*')
        {
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~')
            ans=a[m]*a[m+1]; // @@ [Logic Error: The variable 'ans' is not correctly initialized or reset when starting a new multiplication chain after an addition/subtraction. It should be initialized to a[m] before multiplying by a[m+1]. Also, the result 'ans' is stored in a[m+1], but subsequent operations might rely on incorrect state if not handled properly. Specifically, if this is the start of a term (preceded by + or -), ans should be a[m] * a[m+1]. If it's a continuation, ans *= a[m+1]. However, the critical bug is that 'ans' retains its value from previous calculations if not reset, and the logic for updating a[m+1] with the cumulative product is flawed because it doesn't account for the left operand correctly in all cases. More importantly, the result of the multiplication/division chain is stored in a[m+1], but the code fails to update the 'ans' variable correctly for the next step in the chain if there are multiple * or / operators. For example, in 24/4/3, after 24/4=6, ans=6. Then 6/3=2. But the code checks b[m-1]. If b[m-1] was '/', it goes to else ans/=a[m+1]. This part seems okay for chaining, BUT the initial value of ans is 1. If the first operation is *, ans becomes 1*a[2] if b[1] is *, which is wrong if a[1] was the first number. Wait, let's trace.
            // Trace: 24 / 4 / 3 ...
            // Parsing: a[1]=24, b[1]='/', a[2]=4, b[2]='/', a[3]=3...
            // Loop m=1: b[1]='/'. b[0]='?'. Condition b[m-1]=='+'... is false. Goes to else ans/=a[m+1]. ans was initialized to 1. ans = 1/4 = 0. This is the error. 'ans' should be initialized to a[m] (the left operand) when starting a new multiplicative term.
            else
            ans/=a[m+1];
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-'||b[m-1]=='~')
            ans=a[m]/a[m+1]; // @@ [Logic Error: Similar to above. When starting a new division chain (preceded by + or -), 'ans' is correctly set to a[m]/a[m+1]. However, if it continues, it uses the previous 'ans'. The main issue is the initialization of 'ans' to 1 at the start of main. For the very first operator, if it is * or /, the left operand a[m] is ignored in the 'else' branch because ans starts at 1. For example, 24/4. m=1. b[1]='/'. b[0] is '?'. Else branch: ans /= a[2] => ans = 1/4 = 0. Correct logic should be ans = a[m] / a[m+1] if it's the start of the term.]
            else
            ans/=a[m+1];
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='=')
        {
            d[n]='=';
            break;
        }
    }
    res=c[1];
    for(p=1;d[p]!='=';p++)
    {
        if(d[p]=='+')
        res+=c[p+1];
        else if(d[p]=='-')
        res-=c[p+1];    
    }
    printf("%d",res);    
    return 0;
}