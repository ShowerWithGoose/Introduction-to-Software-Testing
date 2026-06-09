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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The condition `(a>=0&&a<=9)` and `(b>=0&&b<=9)` is incorrect because `a` and `b` are characters, not numeric values. It should compare against `'0'` and `'9'` instead of `0` and `9`.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [The loop condition `n>a` is redundant since `n` starts at `a+1`, and the loop will never run if `a >= b`. Also, it fails to print the character `b` itself, which should be included in the expansion (e.g., '0-8' should include '8').]
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