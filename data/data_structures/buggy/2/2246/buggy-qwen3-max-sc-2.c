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
    
    while(i<lo&&p[i+1]!='=') // @@ [If the expression starts with a single-digit number followed immediately by '=', this loop condition may skip processing the last number correctly. Also, accessing p[i+1] when i == lo-1 leads to out-of-bounds read.]
    {
        long long sum1=p[i]-'0'; // @@ [Assumes p[i] is always a digit, but if the expression starts with '-', this will produce incorrect results or negative ASCII conversion.]
        while(p[i+1]>='0'&&p[i+1]<='9')
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [Accesses p[i+1] without ensuring i+1 < lo, risking buffer overread. Also, logic for handling operator precedence and operand association is flawed.]
        {
            int z=1;
            i+=2; // @@ [Skips two characters assuming operator and next digit, but if there's no digit after operator (invalid per problem, but still unsafe), this goes out of bounds.]
            long long sum2 = p[i]-'0'; // @@ [Same issue: assumes p[i] is a digit without validation. Also, sum2 should be built from multi-digit numbers, but only takes one digit here.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++;
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [This incorrectly appends digits to sum1 instead of sum2, corrupting the left operand.]
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
        
        i+=2; // @@ [May increment beyond string length, especially near the end before '='. Also doesn't handle case where expression ends right after a term.]
    }
    
    printf("%lld",sum); // @@ [Problem requires output as integer (`%d`), but uses `%lld` for long long. While not always a compilation error, mismatched format specifier can cause undefined behavior. However, primary compilation error is due to `gets`.]
    return 0;
}