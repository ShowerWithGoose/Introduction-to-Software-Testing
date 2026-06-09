#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define GET_BIT(value, bit) (((value) >> bit) & 1)  //读取指定位 
#define CPL BIT(value, bit) ((value) ^= (1 << (bit)))  //取反指定位 @@ [macro definition syntax error: BIT is not defined; should be CPL_BIT or similar, and macro body uses undefined BIT]
#define SETO BIT(value, bit) ((value) &= ~(1 << (bit)))  //把某位置0 @@ [macro definition syntax error: BIT is not defined; should be SET0_BIT or similar]
#define SET1 BIT(value, bit) ((value) |= (1 << (bit)))  //把某位置1 @@ [macro definition syntax error: BIT is not defined; should be SET1_BIT or similar]
#define ARRAY_LEN(x) (sizeof(x)/sizeof(x[0]))
#define eps 1e-8 

void squeez(char*,char);
int calculate(int*,char*);
int jiaj(int,int,char);
double chenc(double,double,int*,char*); @@ [function returns double but integer division is required per problem; also recursive logic flawed]
int p = 0;

int main()
{
    char str[2000] = {0};
    char fu[500] = {0};
    int shu[500] = {0};
    gets(str); @@ [uses unsafe gets(); though may compile, it's deprecated and often causes compilation errors in modern environments]
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
} @@ [missing default return; undefined behavior if c is not '+' or '-']

double chenc(double a,double b,int shu[],char fu[])
{
    if(fu[p+1]=='*'||fu[p+1]=='/')
    {
        switch(fu[p])
        {
            case '*':
                p++;
                return a*chenc(shu[p],shu[p+1],shu,fu); @@ [recursive call passes int as double; also modifies global p inconsistently]
                break;
            case '/':
//                p++;
                return a/b;//chenc(shu[p],shu[p+1],shu,fu); @@ [uses floating-point division instead of integer division]
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
                return a/b; @@ [uses floating-point division instead of integer division]
                break;
        }
    }
} @@ [function returns double but should return int; also logic doesn't handle operator precedence correctly due to flawed recursion]

int calculate(int shu[],char fu[])
{
    int ans = shu[0];
    for(p=0;fu[p]!=0;p++)
    {
        if(fu[p]=='*'||fu[p]=='/')
        {
            ans = chenc(ans,shu[p+1],shu,fu); @@ [assigns double result to int without cast; also chenc uses floating point]
        }
        else if(fu[p]=='+')
        {
            if(fu[p+1]=='*'||fu[p+1]=='/')
            {
                p++;
                ans = ans+chenc(shu[p],shu[p+1],shu,fu); @@ [same floating-point and recursion issues]
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
                ans = ans-chenc(shu[p],shu[p+1],shu,fu); @@ [same floating-point and recursion issues]
            }
            else
            {
                ans = ans-shu[p+1];
            }
        }
    }
    return ans;
}