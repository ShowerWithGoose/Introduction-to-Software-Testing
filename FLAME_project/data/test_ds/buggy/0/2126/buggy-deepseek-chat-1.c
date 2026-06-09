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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ Error: The condition for digits uses integer comparison (a>=0&&a<=9) instead of character comparison (a>='0'&&a<='9'). Since a and b are char, comparing with integers 0-9 checks ASCII values, not digit characters. For example, '0' has ASCII value 48, so '0'>=0 is true but '0'<=9 is false, causing digit expansion to never trigger.
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ Error: The loop condition n>a&&n<b is incorrect. n starts at a+1, so n>a is always true, but the loop should continue while n<b. The condition n>a is redundant and the loop variable n is of type char, which may cause overflow or infinite loop if b is small. Also, the loop does not output the starting character a or the ending character b.
            printf("%c",n);
            }
        }    
        else printf("-"); // @@ Error: When expansion conditions are not met, the program prints '-' instead of the original '-' character. This is correct for the '-' itself, but it fails to output the characters before and after the '-' that were already printed by the else branch. The logic should handle the case where no expansion occurs by outputting the '-' and the surrounding characters properly.
        }
        else{
              n=ch[i];
              printf("%c",n);
        }
    }
    return 0;
}