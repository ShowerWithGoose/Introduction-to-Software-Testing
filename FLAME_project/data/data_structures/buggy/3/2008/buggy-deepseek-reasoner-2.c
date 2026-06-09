#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s);
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i); // @@ This line prints a debug value (i) instead of the expected scientific notation. Additionally, the if branch does not output the converted c and n, resulting in the wrong answer.
        for(j=0;i<=strlen(s);j++,i++){
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){
            c[i]=s[i];
        }
        printf("%se%d",c,n);
        return 0;
    }
}