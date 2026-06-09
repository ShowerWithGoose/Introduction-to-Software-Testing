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
    if(strcmp(in,"87899.9999999999000999")==0) // @@ Hardcoding specific test case outputs is incorrect logic; the program should handle all inputs algorithmically. This causes duplicate output because the 'else' block is not mutually exclusive with the previous 'if's properly or the logic falls through.
    {
        printf("8.78999999999999000999e4");
    }
    if(strcmp(in,"5123456789012345678909934958349058395854956984596456893495439.1")==0) // @@ Hardcoding specific test case outputs is incorrect logic.
    {
        printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
    }
    if(strcmp(in,"9.99")==0) // @@ Hardcoding specific test case outputs is incorrect logic. Also, using separate 'if' statements instead of 'else if' means if one matches, it prints, but then the final 'else' might still execute if not structured correctly, or in this specific buggy code, the first two ifs print, and since they don't return/exit, the code continues. Wait, the structure is if... if... if... else. If the first if matches, it prints. Then it checks the second if. Then it checks the third if. If the third if is false, it goes to else. So for the first case, it prints the hardcoded string, then checks the second if (false), then checks the third if (false), then executes else -> oper(in). This causes double output.
    {
        printf("9.99e0");
    }
    else
    {
        oper(in);
    }
    
    return 0;
}