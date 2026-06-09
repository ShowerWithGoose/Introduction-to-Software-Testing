#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s); // @@ [gets() is deprecated and removed in the C11 standard, causing a compilation error in modern compilers; additionally, the program does not implement the required permutation generation logic]
    printf("%s",s);
    return 0;
}