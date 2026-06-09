#include <stdio.h>
#include <string.h>
int main(){
    char str[105];
    gets(str);
    int n=strlen(str);
    int j=0,k=0;
    for(int i=0;i<n;i++){
    if(str[i]=='.'){
        j=i;
    }
    }
    if(j==1){
       if(str[0]=='0'){
        while(str[2+k]=='0'){ // @@ The loop may access out-of-bounds if all digits after decimal are zero; also, the logic for finding the first non-zero digit is incorrect for numbers like 0.001 where k should start from 0 but the index should be j+1+k
            k++;
        }
    printf("%c",str[2+k]);
    printf(".");
    for(int i=3+k;i<n;i++){
        printf("%c",str[i]);
    }printf("e-%d",k+1); // @@ The exponent calculation is wrong; for 0.001, k=2, exponent should be -3, but k+1 gives 3, which is incorrect. The correct exponent should be -(j+1+k) or -(k+1) depending on indexing, but here j=1, so exponent should be -(k+2) for numbers like 0.001
       }
    else printf("%s",str); // @@ This branch does not handle the case where j==1 and str[0]!='0' correctly; it should output the number in scientific notation with exponent 0, but it just prints the original string, which is incorrect for numbers like 1.23 (should output "1.23e0")
    }
    else {
        printf("%c",str[0]);
        printf(".");
        for(int i=1;i<n;i++){
            if(str[i]!='.')
          printf("%c",str[i]);
    }printf("e%d",j-1); // @@ The exponent calculation is wrong for numbers with more than one digit before decimal; for example, 12.34 should output "1.234e1", but j-1 gives 1, which is correct, but the loop prints all digits after the first, including the decimal point, which is incorrect because it should skip the decimal point and print all other digits
    }
    
    return 0;
}