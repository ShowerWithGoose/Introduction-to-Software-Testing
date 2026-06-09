#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r"); // @@ missing error check for NULL
    char ch; // @@ should be int to handle EOF properly
    while((ch=fgetc(in))!=EOF) // @@ assignment in condition; char may not capture EOF; also logic missing: does not count words
        printf("%c",ch);
    return 0;
}