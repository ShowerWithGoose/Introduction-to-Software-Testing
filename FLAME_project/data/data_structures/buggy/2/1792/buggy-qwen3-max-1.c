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
    gets(str); // @@ [Using `gets` is unsafe and may cause buffer overflow; more critically, it reads the whole line including the '=', but the parsing logic assumes '=' is handled separately. Also, `gets` is deprecated.]
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
            shu[j] = 10*shu[j]+str[k]-'0'; // @@ [This accumulates multi-digit numbers correctly only if digits are contiguous. However, after removing spaces via `squeez`, this works. But note: if the expression ends with '=', this skips it, which is okay. However, the main issue is that the parsing does not reset `shu[j]` before starting a new number, so if multiple numbers exist, they overwrite or accumulate incorrectly because `shu` is zero-initialized but reused without resetting per number. Actually, since `shu` is zero-initialized and each number starts at a new `j`, and we do `shu[j] = 10*shu[j] + ...`, it works as long as each number is parsed in one go. So this line is likely correct.]
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
        printf("%d",calculate(shu,fu));
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
                return a*chenc(shu[p],shu[p+1],shu,fu); // @@ [Recursive call uses `shu[p]` and `shu[p+1]` but `p` was just incremented, so this accesses the next number correctly? However, the function signature expects `double a, double b`, but here `shu[p]` is int passed as double – acceptable. But the bigger issue: integer division is required, but this uses `double` and returns `double`, leading to floating point inaccuracies and wrong integer truncation behavior. For example, 5/3 should be 1, but if done in double then cast later, it might work, but the recursive structure is flawed. Also, in the '/' case below, it does `a/b` without advancing `p` properly.]
                break;
            case '/':
//                p++;
                return a/b;//chenc(shu[p],shu[p+1],shu,fu); // @@ [This does not increment `p`, so the next operator won't be skipped. Also, using floating-point division instead of integer division violates requirement #3. Should use integer division. Moreover, the function returns double but the final result is cast to int in printf, which truncates toward zero – but for negative numbers this differs from C integer division. However, test case has positive numbers. Still, 24/4/3/2 = (24/4)=6, 6/3=2, 2/2=1 – but if done left-to-right in double, it's same, but the problem is the algorithm doesn't handle left associativity correctly due to recursion direction.]
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
                return a/b; // @@ [Again, uses floating-point division instead of integer division. Should be `(int)a / (int)b` or better, operate entirely in integers.]
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
            ans = chenc(ans,shu[p+1],shu,fu); // @@ [Passes `ans` (int) and `shu[p+1]` (int) as doubles to `chenc`, which does floating-point arithmetic. This causes two problems: (1) division is not integer division as required, (2) the recursive logic in `chenc` does not correctly handle left-associative evaluation of same-precedence operators like `24/4/3/2`. The current approach tries to look ahead but fails to consume all consecutive * and / operators properly. For example, in "24/4/3/2", it will compute 24/4=6, then in next iteration p=1, sees '/', calls chenc(6,3,...), which sees next '/' and recursively computes 6/(3/2)=6/1=6, which is wrong. Correct is ((24/4)/3)/2 = 1. So associativity is right-to-left in this code, but should be left-to-right.]
        }
        else if(fu[p]=='+')
        {
            if(fu[p+1]=='*'||fu[p+1]=='/')
            {
                p++;
                ans = ans+chenc(shu[p],shu[p+1],shu,fu); // @@ [Same issues: uses floating-point, incorrect associativity, and also increments `p` here, but the for-loop will increment `p` again, potentially skipping an operator. For example, if input is "+ *", then p is incremented in the if-block, then the for-loop does p++, so next operator is skipped. This leads to incorrect parsing.]
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
                ans = ans-chenc(shu[p],shu[p+1],shu,fu); // @@ [Same as above: double arithmetic, wrong associativity, and double increment of `p` causing skipped operators.]
            }
            else
            {
                ans = ans-shu[p+1];
            }
        }
    }
    return ans;
}