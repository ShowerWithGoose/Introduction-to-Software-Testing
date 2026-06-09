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
            for(n=a+1;n>a&&n<b;n++){ // @@ [The loop condition `n>a` is redundant since `n` starts at `a+1`. More critically, the loop stops before printing `b`, but the expected behavior is to include all characters up to and including `b`. However, note that the problem requires expanding `a-d` to `abcd`, meaning the expansion should include characters from `a+1` up to `b`. But the current loop condition `n<b` excludes `b`, which is correct per problem (since `a` is already printed before the '-' and we only need to print from `a+1` to `b`). However, the real issue is that the program prints expanded characters immediately instead of building the full output string, causing ordering issues when multiple expansions or non-expanded parts exist. Also, the original character before '-' is printed in the else clause, but during expansion, the '-' is replaced by the middle characters; however, the character after '-' (`b`) is never printed by the expansion loop nor by the main loop, leading to missing the end character.]
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