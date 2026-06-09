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
        long long sum1=p[i]-'0'; // @@ [Assumes p[i] is always a digit, but if the expression starts with '-', this will cause incorrect conversion. Also, no handling for multi-digit numbers starting at position i if previous parsing left i at an operator.]
        while(p[i+1]>='0'&&p[i+1]<='9')
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [Accesses p[i+1] without ensuring i+1 < lo, risking buffer overread. Also, logic for tracking operators and operands is flawed due to inconsistent index updates.]
        {
            int z=1;
            i+=2; // @@ [This skips two characters assuming operator and next digit, but if the next number has more than one digit or is missing, this leads to incorrect parsing or out-of-bounds access.]
            long long sum2 = p[i]-'0'; // @@ [Again assumes p[i] is a digit without validation; also fails if number is negative or multi-digit beyond first digit.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++;
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [This incorrectly modifies sum1 (which should be the left operand) instead of sum2 (the right operand). This is a critical logic error.]
                i++;
            }
            
            if(p[i-z]=='*') // @@ [Index calculation i-z is unreliable due to prior inconsistent increments; may point to wrong operator or non-operator character.]
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
        
        i+=2; // @@ [Blindly increments by 2 without checking bounds or whether next token exists; may go beyond string length or skip necessary tokens.]
    }
    
    printf("%lld",sum);
    return 0;
}