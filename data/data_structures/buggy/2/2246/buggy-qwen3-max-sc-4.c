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
        long long sum1=p[i]-'0'; // @@ [Assumes p[i] is always a digit, but if the expression starts with '-', this will produce incorrect results or negative ASCII values. Also fails for multi-digit numbers starting at position 0.]
        while(p[i+1]>='0'&&p[i+1]<='9')
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [Accesses p[i+1] without checking bounds; if i+1 >= lo, this reads beyond the string. Also logic for handling operator precedence and parsing is flawed.]
        {
            int z=1;
            i+=2;
            long long sum2 = p[i]-'0'; // @@ [Assumes p[i] is a digit after skipping operator, but doesn't handle multi-digit numbers properly. Also, if i is beyond string length, this causes undefined behavior.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++;
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [This incorrectly modifies sum1 instead of sum2 while parsing the second operand. Should be sum2 = sum2*10 + ...]
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
        
        i+=2; // @@ [May increment i beyond the string length, leading to out-of-bounds access in next iteration. Also doesn't account for end of expression properly.]
    }
    
    printf("%lld",sum); // @@ [The problem requires outputting an int, but %lld expects long long. While not always a compilation error, mismatched format specifiers can cause issues. However, primary issue is logic errors above.]
    return 0;
}