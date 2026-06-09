#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch);
    int i;
    for(i=0;i!=strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ The condition for digits is incorrect: a and b are char type, so comparing with integer 0-9 will compare ASCII values, not digit characters. Should use a>='0' && a<='9' and b>='0' && b<='9'.
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ The loop condition n>a is always true for the first iteration, but the loop logic is flawed. It should iterate from a+1 to b-1, but the condition n>a is redundant and the loop may not execute correctly. Also, n is declared as char, which may cause issues with integer overflow.
            printf("%c",n);
            }
        }    
        else printf("-"); // @@ This prints '-' when the characters around '-' are not of the same type or when a>=b, but the problem requires that in such cases the '-' should be output as part of the original string, not just a single '-'. The original '-' character is already skipped by the if condition, so this incorrectly replaces it.
        }
        else{
              n=ch[i];
              printf("%c",n);
        }
    }
    return 0;
}