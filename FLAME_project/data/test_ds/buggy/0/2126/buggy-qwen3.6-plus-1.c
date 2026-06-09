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
        if(((a>='a'&&a<='z')&&(b>='a'&&b<='z'))||((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))||((a>=0&&a<=9)&&(b>=0&&b<=9))) // @@ The condition a>=0&&a<=9 checks ASCII values 0-9 instead of character digits '0'-'9'. It should be a>='0'&&a<='9'.
        {
            if(a<b)
            for(n=a+1;n>a&&n<b;n++){ // @@ The loop condition n<b excludes the end character b, causing the last character of the range to be missing. It should be n<=b.
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