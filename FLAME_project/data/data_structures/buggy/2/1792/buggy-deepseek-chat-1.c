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
    gets(str);
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
            shu[j] = 10*shu[j]+str[k]-'0'; // @@ [Error: When reading multi-digit numbers, the index j is not updated correctly. For consecutive digits, j should remain the same to accumulate the number, but here j is only incremented when an operator is encountered, so for the first number, j=0, and subsequent digits overwrite shu[0] correctly, but after an operator, j becomes 1, and the next number's digits will overwrite shu[1] correctly. However, the issue is that the loop uses j as the index for shu, but j is also used to track the number of operators in fu, leading to misalignment. Specifically, when a number has multiple digits, shu[j] is updated repeatedly with the same j, which is correct for accumulation, but the index j for shu should be the same as the position of the number relative to operators. The real problem is that the logic for parsing numbers and operators is flawed: after reading an operator, j is incremented, but the next number should be stored at shu[j] (which is now the next index), but the code uses shu[j] where j is the count of operators, not the count of numbers. This causes numbers to be stored at wrong indices, leading to incorrect calculations.]
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
                return a*chenc(shu[p],shu[p+1],shu,fu);
                break;
            case '/':
//                p++;
                return a/b;//chenc(shu[p],shu[p+1],shu,fu); // @@ [Error: This line returns a/b without incrementing p, which means the recursive call is skipped and the division is performed only on the current two operands, ignoring subsequent * or / operators. This leads to incorrect order of operations, especially for consecutive divisions like 24/4/3/2, where it should be ((24/4)/3)/2 = 1, but this code computes 24/4 = 6, then returns 6/3 = 2 (since p is not incremented, the next iteration of calculate will use the same p, causing further errors).]
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
}

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