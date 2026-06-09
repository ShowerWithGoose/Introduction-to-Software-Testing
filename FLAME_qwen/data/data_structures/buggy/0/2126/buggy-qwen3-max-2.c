#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this can lead to compilation errors if strict standards are enforced.]
    int i;
    for(i=0;i!=strlen(ch);i++) // @@ [Calling 'strlen' in loop condition repeatedly is inefficient but not a compilation error. However, the real issue lies elsewhere.]
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The conditions (a>=0&&a<=9) and (b>=0&&b<=9) are incorrect: they compare characters to integer literals 0 and 9 instead of character literals '0' and '9'. This causes logical errors, but more critically, in some compilers with strict type checking or warnings treated as errors, this might contribute to issues. However, the primary compilation error likely stems from 'gets'.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [This loop condition 'n>a && n<b' is redundant since 'n' starts at 'a+1' and increments; also, if 'a' and 'b' are not valid (e.g., due to prior logic error), behavior is undefined. But not a compilation error.]
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