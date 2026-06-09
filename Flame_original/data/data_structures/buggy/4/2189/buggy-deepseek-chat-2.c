#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r");
    char ch;
    while((ch=fgetc(in))!=EOF)
        printf("%c",ch);
        
    return 0;
}