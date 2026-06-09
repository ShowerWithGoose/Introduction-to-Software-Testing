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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The condition `(a>=0&&a<=9)` and `(b>=0&&b<=9)` is incorrect because `a` and `b` are characters, not numeric values. It should compare against `'0'` and `'9'` instead of 0 and 9.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [The loop condition `n>a&&n<b` is redundant and misleading; it should simply be `n < b`. Also, the loop does not handle the case when `b` is immediately after `a` (e.g., a-b), which should output nothing between, but current logic may skip correctly. However, the main issue is that this loop prints intermediate characters but does not skip printing the '-' itself, and also fails to avoid re-printing surrounding characters. Additionally, the original character before '-' is already printed in the else clause, but the character after '-' will be printed again when the loop reaches it, causing duplication.]
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