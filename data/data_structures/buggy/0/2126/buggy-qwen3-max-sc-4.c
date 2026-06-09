#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. Also, some compilers may not support it, leading to compilation errors.]
    int i;
    for(i=0;i!=strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The condition (a>=0&&a<=9) compares characters with integer literals 0 and 9 instead of character literals '0' and '9', which is incorrect for checking digit characters.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [The loop condition 'n>a' is always true since n starts at a+1 and increments; this is redundant and may confuse logic. More critically, 'n' is a char, and if a and b are far apart, this loop may overflow or behave unexpectedly. However, the main issue is the digit comparison above.]
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