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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ Error: The condition for digits uses integer comparison (a>=0) instead of character comparison (a>='0'). This will always be true for any character with ASCII value >=0, causing incorrect expansion for non-digit characters.
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ Error: The loop condition `n>a&&n<b` is incorrect. Since `n` is a char, `n>a` is always true after `n=a+1`, but the loop should simply be `for(n=a+1; n<b; n++)`. The current condition may cause an infinite loop or incorrect behavior.
            printf("%c",n);
            }
        }    
        else printf("-");    
        }
        else{
              n=ch[i];
              printf("%c",n);
        }
    }
    return 0;
}