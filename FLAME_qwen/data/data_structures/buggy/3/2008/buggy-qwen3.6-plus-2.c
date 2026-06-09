#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern compilers; use fgets() instead.
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i); // @@ Debug print statement left in code violates the required output format.
        for(j=0;i<=strlen(s);j++,i++){
            c[j]=s[i];
        }
    } // @@ Missing printf statement to output the calculated scientific notation for the s[0]=='0' case.
    else{
        c[0]=s[0];
        c[1]='.'; // @@ Incorrectly forces a decimal point for all inputs, violating the requirement that integers should not contain a decimal point.
        for(i=1;s[i]!='.';i++){ // @@ Fails to handle integer inputs without a decimal point, causing out-of-bounds array access and incorrect formatting.
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