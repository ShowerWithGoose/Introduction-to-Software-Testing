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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>='0'&&a<='9')&&(b>='0'&&b<='9'))) // @@ [Error: The condition (a>=0&&a<=9) checks if the ASCII value of character 'a' is between 0 and 9, which is incorrect for digit characters. It should check if the character is between '0' and '9'.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [Error: The loop condition n<a is false immediately if n starts at a+1, but the logic n>b is also problematic. More importantly, the loop prints characters from a+1 up to b-1. It misses printing 'b' itself if the requirement is inclusive, or it might be correct depending on interpretation. However, the main issue in the previous line causes the digit case to fail entirely. Also, the loop variable n is declared as char, which is fine, but the condition `n>a` is redundant if `n` starts at `a+1` and increments. The critical error is the digit check above.]
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