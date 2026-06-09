#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

void squeez(char*,char);
int calculate(int*,char*);
int jiaj(int,int,char);
double chenc(double,double,int*,char*);
int p = 0;

int main()
{
    char str[2000] = {0};
    char fu[500] = {0};
    int shu[500] = {0};
    gets(str); // @@ [Using `gets` is unsafe and may cause buffer overflow; more critically, it reads the whole line including the '=', but the parsing logic assumes '=' is handled separately. However, the main issue is in parsing numbers: multi-digit numbers are parsed correctly only if no operators intervene, but the real bug is in `calculate` and `chenc`.]
    squeez(str,' ');
//    puts(str);
    for(int i=0,j=0,k=0;str[k]!='\0';k++)
    {
        if(str[k]=='+'||str[k]=='-'||str[k]=='*'||str[k]=='/')
        {
            fu[i] = str[k];
            i++;
            j++;
        }
        else if(str[k]!='=')
        {
            shu[j] = 10*shu[j]+str[k]-'0'; // @@ [This correctly accumulates multi-digit numbers, but note that `j` is only incremented when an operator is found. This works because numbers are contiguous digits. However, the critical bugs are in the evaluation functions below.]
        }
        else
        {
            if(fu[0]==0)
            {
                printf("%d",shu[0]);
            }
        }
    }
    if(fu[0]!=0)
    {
        printf("%d",calculate(shu,fu)); // @@ [The `calculate` function has multiple logical errors in handling operator precedence and associativity, especially for consecutive same-precedence operators like division.]
    }
    
    return 0;
}

void squeez(char s[],char c)
{
    int i,j;
    for(i=j=0;s[i]!='\0';i++)
    {
        if(s[i]!=c)
        {
            s[j++]=s[i];
        }
    }
    s[j]='\0';
}



int jiaj(int a,int b,char c)
{
    switch(c)
    {
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
    }
}

double chenc(double a,double b,int shu[],char fu[])
{
    if(fu[p+1]=='*'||fu[p+1]=='/')
    {
        switch(fu[p])
        {
            case '*':
                p++;
                return a*chenc(shu[p],shu[p+1],shu,fu); // @@ [Recursive call uses `shu[p]` and `shu[p+1]` after incrementing `p`, but this skips the current `b` and breaks associativity. Also, using `double` causes precision issues and violates integer division requirement.]
                break;
            case '/':
//                p++;
                return a/b;//chenc(shu[p],shu[p+1],shu,fu); // @@ [This returns `a/b` without consuming the next operator, breaking the chain for expressions like `24/4/3/2`. Also, uses floating-point division instead of integer division.]
                break;
        }
    }
    else
    {
        switch(fu[p])
        {
            case '*':
                return a*b;
                break;
            case '/':
                return a/b; // @@ [Uses floating-point division; should use integer division (e.g., `(int)a/(int)b`). Also, doesn't handle truncation toward zero as required for integer division in C with positive numbers, but the type mismatch is critical.]
                break;
        }
    }
}

int calculate(int shu[],char fu[])
{
    int ans = shu[0];
    for(p=0;fu[p]!=0;p++)
    {
        if(fu[p]=='*'||fu[p]=='/')
        {
            ans = chenc(ans,shu[p+1],shu,fu); // @@ [Passes `ans` (an int) and `shu[p+1]` (an int) to `chenc` which expects `double`, causing implicit conversion. More importantly, `chenc` does not properly handle left-associative operations like `24/4/3/2` due to incorrect recursion and missing state updates.]
        }
        else if(fu[p]=='+')
        {
            if(fu[p+1]=='*'||fu[p+1]=='/')
            {
                p++;
                ans = ans+chenc(shu[p],shu[p+1],shu,fu); // @@ [Skips the next number by incrementing `p` then using `shu[p]` and `shu[p+1]`, but this disrupts the loop's indexing and fails to account for longer chains of * or /. Also, `chenc` returns double which is truncated to int, but the logic is flawed.]
            }
            else
            {
                ans = ans+shu[p+1];
            }
        }
        else if(fu[p]=='-')
        {
            if(fu[p+1]=='*'||fu[p+1]=='/')
            {
                p++;
                ans = ans-chenc(shu[p],shu[p+1],shu,fu); // @@ [Same issue as above: incorrect indexing and flawed evaluation of multiplicative subexpressions.]
            }
            else
            {
                ans = ans-shu[p+1];
            }
        }
    }
    return ans;
}