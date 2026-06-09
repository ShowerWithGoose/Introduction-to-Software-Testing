#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r"); // @@ [Missing check for NULL file pointer; if file doesn't exist or can't be opened, subsequent fgetc leads to undefined behavior]
    char ch;
    while((ch=fgetc(in))!=EOF) // @@ [char 'ch' should be declared as int to properly handle EOF, which is outside the range of char; this causes incorrect loop termination or infinite loop on some systems]
        printf("%c",ch);
        
    return 0;
}