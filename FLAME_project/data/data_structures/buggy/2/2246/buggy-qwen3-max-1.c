#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char s[1024]={'\0'},p[1024]={'\0'};
    gets(s);
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
    
    while(i<lo&&p[i+1]!='=') // @@ [The loop condition skips processing the last term before '=', leading to incorrect parsing when expression ends with '='. Also, it assumes at least two characters remain, which fails for single-number expressions.]
    {
        long long sum1=p[i]-'0'; // @@ [Assumes current character is always a digit; fails if expression starts with '-' or if i points to an operator after previous term.]
        while(p[i+1]>='0'&&p[i+1]<='9') // @@ [Only checks next character; misses multi-digit numbers starting at current i if i itself is part of a longer number. Also, doesn't handle case where number is single-digit correctly in all contexts.]
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [This inner loop tries to process * and / but uses incorrect indexing (i+1) and variable 'z' to backtrack, which leads to wrong operand extraction and operator association. It also modifies i in a way that breaks outer loop synchronization.]
        {
            int z=1;
            i+=2; // @@ [Skips two characters assuming operator and next digit, but may go out of bounds or skip digits incorrectly.]
            long long sum2 = p[i]-'0'; // @@ [Assumes p[i] is a digit after skipping, but may be operator or '='. Also, doesn't parse full number if multi-digit.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++; // @@ [Misuse of 'z': it counts extra digits but is used later as offset to find operator, which is logically flawed.]
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [Wrongly appends digits to sum1 (which should be left operand) instead of sum2 (right operand). This corrupts the left operand.]
                i++;
            }
            
            if(p[i-z]=='*') // @@ [Uses 'z' to index back to operator, but due to incorrect increment logic, this often points to wrong location or non-operator character.]
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
        
        i+=2; // @@ [Blindly increments by 2 assuming operator and next digit exist, which may skip characters or go beyond string length, especially near end or with multi-digit numbers.]
    }
    
    printf("%lld",sum);
    return 0;
}