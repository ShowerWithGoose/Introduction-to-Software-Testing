#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r"); // @@ [Missing check for NULL return value from fopen; if file doesn't exist, subsequent fgetc leads to undefined behavior]
    char ch;
    while((ch=fgetc(in))!=EOF) // @@ [char 'ch' should be declared as int to properly handle EOF, which is outside the range of char]
        printf("%c",ch);
        
    return 0;
}