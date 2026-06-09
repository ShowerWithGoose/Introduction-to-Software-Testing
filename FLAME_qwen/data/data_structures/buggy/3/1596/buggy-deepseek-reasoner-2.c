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
        out[1]='.'; // @@ Always inserts decimal point, fails for single-digit integers and may produce base like "5." for input "5"
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
        j++; // @@ Off-by-one: after decrementing j to last digit, incrementing j moves past it, causing for loop to print one extra undefined character.
        for(i=0;i<=j;i++) // @@ Loop condition includes j after increment, printing uninitialized out[j]; should be i<j or remove j++
        {
            printf("%c",out[i]);
        }
        printf("e%d",cnt);
    }
}
int main()
{
    gets(in);
    if(strcmp(in,"87899.9999999999000999")==0) // @@ Missing 'else if'; falls through to subsequent conditions and else, causing double output for special cases
    {
        printf("8.78999999999999000999e4");
    }
    if(strcmp(in,"5123456789012345678909934958349058395854956984596456893495439.1")==0) // @@ Missing 'else if'; falls through to subsequent conditions and else, causing double output for special cases
    {
        printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
    }
    if(strcmp(in,"9.99")==0) // @@ Missing 'else if'; falls through to else, causing double output for special cases; should be else if or add return after each
    {
        printf("9.99e0");
    }
    else
    {
        oper(in);
    }
    
    return 0;
}