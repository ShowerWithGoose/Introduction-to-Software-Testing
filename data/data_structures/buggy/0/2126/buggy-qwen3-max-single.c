#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, 'gets' is not available, leading to compilation error.]
    int i;
    for(i=0;i!=strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ [The conditions (a>=0&&a<=9) and (b>=0&&b<=9) compare characters with integer literals 0 and 9 instead of character literals '0' and '9', causing incorrect type checks.]
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ [Loop condition 'n>a' is always true since n starts at a+1 and increments; also, using 'n' as loop variable of type char may overflow or behave unexpectedly. Additionally, the loop does not print the full range correctly due to flawed logic.]
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