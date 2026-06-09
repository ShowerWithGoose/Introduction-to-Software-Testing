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
        for(i=1;s[i]!='.';i++){ // @@ This loop incorrectly copies digits before the decimal point, including the decimal point itself, and the index logic is flawed.
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){ // @@ This loop has an off-by-one error and does not properly handle the string termination.
            c[i]=s[i];
        }
        printf("%se%d",c,n);
        return 0;
    }
}