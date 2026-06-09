#include <stdio.h>
#include <string.h>
int main(){
    char str[105];
    gets(str); // @@ gets is deprecated and removed in C11, causing compilation errors in modern compilers; use fgets instead.
    int n=strlen(str);
    int j=0,k=0;
    for(int i=0;i<n;i++){
    if(str[i]=='.'){
        j=i;
    }
    }
    if(j==1){
       if(str[0]=='0'){
        while(str[2+k]=='0'){
            k++;
        }
    printf("%c",str[2+k]);
    printf("."); // @@ Unconditionally prints a decimal point, but if there are no remaining digits, the base should be an integer without a decimal point.
    for(int i=3+k;i<n;i++){
        printf("%c",str[i]);
    }printf("e-%d",k+1);
       }
    else printf("%s",str);           // @@ Fails to print the exponent "e0" for numbers with a single non-zero digit before the decimal point.
    }
    else {
        printf("%c",str[0]);
        printf(".");
        for(int i=1;i<n;i++){
            if(str[i]!='.')
          printf("%c",str[i]);
    }printf("e%d",j-1);
        
    }
    
    return 0;
}