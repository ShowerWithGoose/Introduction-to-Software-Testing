#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r"); // @@ [Missing check for NULL return value; if file doesn't exist, fopen returns NULL and subsequent fgetc leads to undefined behavior]
    char ch; // @@ [char should be int to properly handle EOF, which is outside the range of char]
    while((ch=fgetc(in))!=EOF) // @@ [fgetc returns int, but ch is char; this causes incorrect EOF comparison and potential infinite loop or missed characters]
        printf("%c",ch);
        
    return 0;
}