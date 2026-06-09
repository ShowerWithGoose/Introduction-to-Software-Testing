#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char s[1024]={'\0'},p[1024]={'\0'};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 and may cause compilation errors with modern compilers. Use `fgets` instead.]
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
    
    while(i<lo&&p[i+1]!='=') // @@ [If the expression starts with a single-digit number followed immediately by '=', this loop condition may skip processing the last number, leading to incorrect logic or infinite loop. Also, accessing p[i+1] when i == lo-1 causes out-of-bounds read.]
    {
        long long sum1=p[i]-'0'; // @@ [Assumes p[i] is always a digit, but if the expression starts with '-', this will produce garbage. Also fails for multi-digit numbers starting at position i.]
        while(p[i+1]>='0'&&p[i+1]<='9')
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [Accesses p[i+1] without ensuring i+1 < lo, risking buffer overread. Also, logic for handling operator precedence and operand parsing is flawed.]
        {
            int z=1;
            i+=2; // @@ [Skips two characters assuming operator and next digit, but if next token is multi-digit or absent, this leads to incorrect indexing or out-of-bounds access.]
            long long sum2 = p[i]-'0'; // @@ [Assumes p[i] is a digit after skipping, which may not be true (e.g., end of string or '=').]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++;
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [This modifies sum1 instead of sum2, corrupting the left operand. Should be sum2 = sum2*10 + ...]
                i++;
            }
            
            if(p[i-z]=='*') // @@ [Index i-z may not point to the correct operator due to incorrect tracking of positions during parsing.]
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
        
        i+=2; // @@ [Unconditionally increments by 2, which may jump past '=' or beyond the string length, causing undefined behavior.]
    }
    
    printf("%lld",sum); // @@ [Problem requires output as integer (%d), but uses %lld for long long. Also, logic errors above likely produce wrong result.]
    return 0;
}