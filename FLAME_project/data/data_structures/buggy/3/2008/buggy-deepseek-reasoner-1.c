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
        printf("%d\n",i); // @@ This line prints the intermediate index i (here 2) instead of the final scientific notation, causing the buggy output "2". It should be removed or replaced with the correct output.
        for(j=0;i<=strlen(s);j++,i++){ // @@ This loop copies the digits from position i onward into c, but it does not insert a decimal point after the first non-zero digit, nor does it handle the case of multiple significant digits correctly. Additionally, no final printf is provided after this loop.
            c[j]=s[i]; // @@ This line only copies a character without building the proper base for scientific notation. A decimal point should be inserted after the first digit.
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