#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this leads to compilation errors or warnings that prevent execution.]
    int i;
    for(i=0;i!=strlen(ch);i++) // @@ [Calling 'strlen' in loop condition repeatedly is inefficient but not a compilation error. However, the real issue lies elsewhere.]
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The conditions (a>=0 && a<=9) and (b>=0 && b<=9) are incorrect: they compare characters to integer values 0-9 instead of character digits '0'-'9'. This logic error causes wrong type checking, but more critically, comparing char to int like this may not cause compilation error. However, combined with other issues...]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [This loop condition 'n>a && n<b' is redundant since n starts at a+1 and increments; also, if a and b are not of same type or invalid, this may still run incorrectly. But again, not a compilation error.]
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