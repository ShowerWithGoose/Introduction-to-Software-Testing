#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int  main()
{   
    char ch[1000],a,b,n;
    gets(ch); // @@ gets() is removed in the C11 standard and causes compilation errors in modern environments; use fgets() or scanf() instead.
    int i;
    for(i=0;i!=strlen(ch);i++)
    {
        if(ch[i]=='-')
        {
        a=ch[i-1],b=ch[i+1];
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ Logical error: compares character values to integers 0 and 9 instead of character literals '0' and '9'. Should be (a>='0' && a<='9').
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){
            printf("%c",n);
            }
        }    
        else printf("-");    // @@ Logical error: only prints '-' when types mismatch. If types match but a>=b, '-' is omitted, failing to output the original string unchanged.
        }
        else{
              n=ch[i];
              printf("%c",n);
        }
    }
    return 0;
}