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
        out[1]='.'; // @@ The index should be j+1 (which is 1 initially), but later logic uses j incorrectly. More importantly, the trailing zero removal and printing logic is flawed.
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
        printf("e%d",cnt);
    }
}
int main()
{
    gets(in);
    if(strcmp(in,"87899.9999999999000999")==0) // @@ Hardcoding specific test case outputs is incorrect and causes failure when multiple conditions are met or output is duplicated. The structure if-if-if-else means if the first matches, it prints, then checks the second (fails), checks the third (fails), then goes to else? No, if the first if is true, it executes. Then it checks the second if. Then the third if. If the third if is false, it executes the else block. So for the hardcoded case, it prints the hardcoded string AND then executes oper(in), causing double output.
    {
        printf("8.78999999999999000999e4");
    }
    if(strcmp(in,"5123456789012345678909934958349058395854956984596456893495439.1")==0) // @@ Same issue: independent if statements lead to fall-through to the final else if none of the subsequent ifs match, or multiple executions if logic was different. Here, if input matches line 66, it prints. Then checks line 70 (false). Then checks line 74 (false). Then executes else block (oper). Result: Hardcoded + Calculated.
    {
        printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
    }
    if(strcmp(in,"9.99")==0) // @@ Same issue.
    {
        printf("9.99e0");
    }
    else // @@ This else is only attached to the last if (line 74). If the input matches line 66 or 70, this else block is STILL executed because those were separate if statements.
    {
        oper(in);
    }
    
    return 0;
}