#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 @@ [Macro definition syntax error: BIT is not defined and macro name conflicts with function-like usage]
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 @@ [Macro definition syntax error: BIT is not defined]
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1 @@ [Macro definition syntax error: BIT is not defined]
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

void squeez(char*,char);
int calculate(int*,char*);
int jiaj(int,int,char);
double chenc(double,double,int*,char*); @@ [Function declaration mismatch: implementation uses 4 parameters but called with 4 in code, however return type double vs int usage causes logic error]
int p = 0;

int main()
{
    char str[2000] = {0};
    char fu[500] = {0};
    int shu[500] = {0};
    gets(str); @@ [Use of unsafe function 'gets' which may cause buffer overflow; also deprecated in C11]
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
            shu[j] = 10*shu[j]+str[k]-'0';
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
} @@ [Missing default return value; undefined behavior if c is not '+' or '-']

double chenc(double a,double b,int shu[],char fu[])
{
    if(fu[p+1]=='*'||fu[p+1]=='/')
    {
        switch(fu[p])
        {
            case '*':
                p++;
                return a*chenc(shu[p],shu[p+1],shu,fu); @@ [Incorrect recursive call: passing integers where doubles expected, and logic skips operators incorrectly]
                break;
            case '/':
//                p++;
                return a/b;//chenc(shu[p],shu[p+1],shu,fu); @@ [Incomplete logic: does not handle chained multiplication/division correctly]
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
                return a/b;
                break;
        }
    }
} @@ [Missing default return value; undefined behavior if fu[p] is not '*' or '/']

int calculate(int shu[],char fu[])
{
    int ans = shu[0];
    for(p=0;fu[p]!=0;p++)
    {
        if(fu[p]=='*'||fu[p]=='/')
        {
            ans = chenc(ans,shu[p+1],shu,fu); @@ [Type mismatch: chenc returns double but assigned to int; also modifies global p leading to index errors]
        }
        else if(fu[p]=='+')
        {
            if(fu[p+1]=='*'||fu[p+1]=='/')
            {
                p++;
                ans = ans+chenc(shu[p],shu[p+1],shu,fu); @@ [Same type and indexing issues as above; global p causes skipping or reprocessing operators]
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
                ans = ans-chenc(shu[p],shu[p+1],shu,fu); @@ [Same issues: type mismatch and incorrect operator precedence handling due to global p mutation]
            }
            else
            {
                ans = ans-shu[p+1];
            }
        }
    }
    return ans;
}