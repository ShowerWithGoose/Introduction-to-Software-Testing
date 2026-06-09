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
        printf("%d\n",i); // @@ This line prints debug output that is not part of the required output format, causing incorrect output.
        for(j=0;i<=strlen(s);j++,i++){
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){
            c[i+1]=s[i]; // @@ This incorrectly shifts characters; it should start from index 2 in c, but uses i+1 which overwrites the '.' at c[1] and misplaces digits.
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){
            c[i]=s[i]; // @@ This uses i as index in c, but i has been incremented past the decimal point, so it does not correctly copy the remaining digits into c.
        }
        printf("%se%d",c,n);
        return 0;
    }
}