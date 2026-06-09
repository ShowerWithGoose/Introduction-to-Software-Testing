#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char s[1024]={'\0'},p[1024]={'\0'};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use `fgets` instead.]
    int l=strlen(s);
    int i=0,j=0;
    for(i=0;i<l&&s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            p[j]=s[i];
            j++;
        }
    }
    p[j]='\0';
                    
    int lo=strlen(p),fig=1;
    long long sum=0;
    i=0;
    
    while(i<lo&&p[i+1]!='=') // @@ [If the expression starts with a single-digit number followed immediately by '=', this loop condition may skip processing the last number, leading to incorrect logic flow. Also, accessing p[i+1] when i == lo-1 leads to out-of-bounds read.]
    {
        long long sum1=p[i]-'0';
        while(p[i+1]>='0'&&p[i+1]<='9')
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [Accessing p[i+1] without ensuring i+1 < lo can cause buffer overread. Also, logic for handling operator precedence and operand parsing is flawed—e.g., it assumes operators always follow numbers directly without considering current position correctly.]
        {
            int z=1;
            i+=2;
            long long sum2 = p[i]-'0'; // @@ [If i is beyond string length or points to non-digit (like '='), this causes undefined behavior or wrong value.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++;
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [This line incorrectly modifies sum1 instead of sum2 while reading the second operand.]
                i++;
            }
            
            if(p[i-z]=='*')
            {
                sum1 = sum1*sum2;
            }
            else if(p[i-z]=='/')
            {
                sum1 = sum1/sum2;
            }
        }
        sum += sum1*fig;
        
        if(p[i+1]=='+')
        fig=1;
        else if(p[i+1]=='-')
        fig=-1;
        
        i+=2; // @@ [Incrementing i by 2 without checking bounds may lead to skipping characters or going out of bounds, especially near the end of the expression before '='.]
    }
    
    printf("%lld",sum);
    return 0;
}