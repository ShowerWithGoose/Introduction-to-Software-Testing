#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ [Using gets is unsafe and deprecated, but more importantly, the logic below fails to print the result for the '0' case correctly]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){ // @@ [This loop skips leading zeros after decimal. For "0.9", s[2] is '9', so loop doesn't run, i remains 2. This is incorrect logic for finding the first significant digit if there were zeros, but for 0.9 it stops immediately.]
        }
        n=1-i; // @@ [Calculates exponent. For 0.9, i=2, n = -1. This part is technically correct for 0.9, but the subsequent printing is wrong.]
        printf("%d\n",i); // @@ [This prints debug information or incorrect output instead of the significant digits. It should not be here. It prints "2" which matches the buggy output.]
        for(j=0;i<=strlen(s);j++,i++){ // @@ [This loop copies the significant digits into c. For 0.9, it copies '9' and '\0'. However, the result is never printed.]
            c[j]=s[i];
        }
    } // @@ [Missing code to print the result for the case where s[0]=='0'. The program falls through without printing the scientific notation for numbers like 0.9]
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
} // @@ [The function ends without returning a value or printing anything for the if-branch, leading to missing output for inputs starting with '0'.]