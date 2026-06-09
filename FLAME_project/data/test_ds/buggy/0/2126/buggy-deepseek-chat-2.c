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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ Error: The condition `(a>=0&&a<=9)` and `(b>=0&&b<=9)` compares character values with integers 0-9, but characters '0'-'9' have ASCII values 48-57. This condition will never be true for digit characters. Should use `(a>='0'&&a<='9')` and `(b>='0'&&b<='9')`.
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ Error: The loop condition `n>a&&n<b` is incorrect. Since `n` starts at `a+1`, `n>a` is always true, but the loop should continue while `n<b`. The condition `n>a` is redundant and the loop will run indefinitely if `a+1 < b` because `n` is incremented but the condition `n>a` remains true. Should be `for(n=a+1; n<b; n++)`.
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