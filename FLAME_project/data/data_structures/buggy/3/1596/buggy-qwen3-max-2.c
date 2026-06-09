#include<stdio.h>
#include <string.h>
char in[10000];
char out[10000];
void oper(char s[])
{
    int cnt=1,i=0,j=0;
    if(s[i]=='0')
    {
        i+=2;
        while(s[i]=='0')
        {
            cnt++;
            i++;
        }
        printf("%c",s[i]);
        if(s[i+1]!='\0')
        {
            printf(".");
            i++;
            while(s[i]!='\0')
            {
                printf("%c",s[i]);
                i++;
               }
        }
        printf("e-%d",cnt);
    }
    else
    {
        cnt=0;
        out[j]=s[i];
        out[1]='.'; @@ // The base must have only one digit before the decimal point, but this always adds a '.' even if there's only one digit and no fractional part. Also, 'j' is 0, so out[1] is set before out[0] is properly handled in all cases.
        i++;j+=2;
        while(s[i]!='.'&&s[i]!='\0')
        {
            cnt++;
            out[j]=s[i];
            i++;j++;
        }
        if(s[i]=='.')
        {
            i++;
        while(s[i]!='\0')
        {
            out[j]=s[i];
            i++;j++;
        }
        }
        j--;
        while(out[j]=='0')
        {
            out[j]='\0';
            j--;
        }
        j++;
        for(i=0;i<=j;i++)
        {
            printf("%c",out[i]);
        }
        printf("e%d",cnt); @@ // The exponent calculation is incorrect: 'cnt' counts digits after the first, but for numbers like "87899.99...", the exponent should be 4 (since 8.7899... × 10^4), but 'cnt' becomes 4 only if we count digits before the decimal excluding the first — however, the loop includes all digits before '.', so for "87899", it counts 4 digits after '8', which is correct, BUT the logic fails when there are trailing zeros that are removed — however, the bigger issue is that the main function bypasses this logic with hardcoded outputs, and the 'else' clause in main causes double output.
    }
}
int main()
{
    gets(in); @@ // Using gets() is unsafe and deprecated, but more critically, the logic below has a structural flaw: multiple 'if' statements without 'else if' cause multiple prints for matching inputs.
    if(strcmp(in,"87899.9999999999000999")==0)
    {
        printf("8.78999999999999000999e4");
    }
    if(strcmp(in,"5123456789012345678909934958349058395854956984596456893495439.1")==0) @@ // Because this is a separate 'if' (not 'else if'), after printing the correct output for the first test case, the program continues and falls into the 'else' block below if the input doesn't match this second string — but wait, the real bug is: the last condition is 'if(...) ... else { oper(in); }', so if the input matches the first string, it prints the correct answer, then checks the second 'if' (which fails), then since the third 'if' ("9.99") also fails, it executes the 'else' block and calls oper(in), causing duplicate output.
    {
        printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
    }
    if(strcmp(in,"9.99")==0) @@ // This 'if' is independent. If input is "9.99", it prints "9.99e0", but then since there's no 'else if', and this is the last conditional, there is no 'else' attached to this 'if'. However, the 'else' on the next line is attached ONLY to this last 'if'. So for input "87899...", it matches the first 'if', prints once, then skips second and third 'if's, and then because the third 'if' was false, it executes the 'else' block — calling oper(in) again, leading to double output.
    {
        printf("9.99e0");
    }
    else
    {
        oper(in); @@ // This 'else' corresponds only to the immediately preceding 'if'. Thus, any input that does NOT equal "9.99" will trigger oper(in), even if it matched an earlier 'if'. This causes the program to print the hardcoded answer AND the result of oper(in), resulting in concatenated wrong output like "8.7899...e48.7899...e4".
    }
    
    return 0;
}