#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 @@ Incorrect macro definition syntax; 'BIT' is undefined and likely a typo for '('. Should be a function-like macro: #define CPL(value, bit) ...
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 @@ Incorrect macro definition syntax; 'BIT' is undefined and likely a typo for '('. Should be a function-like macro: #define SETO(value, bit) ...
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1 @@ Incorrect macro definition syntax; 'BIT' is undefined and likely a typo for '('. Should be a function-like macro: #define SET1(value, bit) ...
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
    gets(str); @@ 'gets' is deprecated/removed in C11 and causes compilation errors on modern compilers. Use 'fgets' instead.
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
} @@ Non-void function 'jiaj' lacks a return statement for all control paths, causing a compilation error with strict flags.

double chenc(double a,double b,int shu[],char fu[])
{
    if(fu[p+1]=='*'||fu[p+1]=='/')
    {
        switch(fu[p])
        {
            case '*':
                p++;
                return a*chenc(shu[p],shu[p+1],shu,fu);
                break;
            case '/':
//                p++;
                return a/b;//chenc(shu[p],shu[p+1],shu,fu);
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
} @@ Non-void function 'chenc' lacks a return statement for all control paths, causing a compilation error with strict flags.

int calculate(int shu[],char fu[])
{
    int ans = shu[0];
    for(p=0;fu[p]!=0;p++)
    {
        if(fu[p]=='*'||fu[p]=='/')
        {
            ans = chenc(ans,shu[p+1],shu,fu);
        }
        else if(fu[p]=='+')
        {
            if(fu[p+1]=='*'||fu[p+1]=='/')
            {
                p++;
                ans = ans+chenc(shu[p],shu[p+1],shu,fu);
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
                ans = ans-chenc(shu[p],shu[p+1],shu,fu);
            }
            else
            {
                ans = ans-shu[p+1];
            }
        }
    }
    return ans;
}