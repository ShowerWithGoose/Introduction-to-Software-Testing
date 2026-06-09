#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r");
    char ch;
    while((ch=fgetc(in))!=EOF)
        printf("%c",ch); // @@ [The program simply reads and prints the file content character by character without processing words, converting to lowercase, counting frequencies, or sorting lexicographically as required by the problem.]
        
    return 0;
}