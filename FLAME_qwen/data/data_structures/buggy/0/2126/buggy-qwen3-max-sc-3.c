#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this leads to compilation errors or warnings that prevent execution.]
    int i;
    for(i=0;i!=strlen(ch);i++) // @@ [Calling 'strlen' in every loop iteration is inefficient but not a compilation error. However, the real issue lies elsewhere.]
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The condition '(a>=0&&a<=9)' compares characters with integer literals 0 and 9 instead of character literals '0' and '9'. This is a logical error that causes incorrect type checking, but more critically, since 'a' and 'b' are chars (signed or unsigned), comparing with 0–9 (ASCII 0–9 are 48–57) will almost always be false. However, this is not a compilation error. The actual compilation error likely stems from 'gets' being removed in C11 and newer standards, causing a compilation failure if the compiler enforces it strictly.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [This loop condition 'n>a && n<b' is redundant since 'n' starts at 'a+1' and increments until 'n < b'; also, if 'a' and 'b' are not of the same type due to earlier bug, expansion may still occur incorrectly. But again, not a compilation error.]
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