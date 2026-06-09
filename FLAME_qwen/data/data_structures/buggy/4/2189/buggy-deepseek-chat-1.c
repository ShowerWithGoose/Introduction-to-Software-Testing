#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r");
    char ch;
    while((ch=fgetc(in))!=EOF) // @@ [Error: The program does not implement word frequency counting as required. It only reads and prints characters from the file, ignoring the problem's specifications to count word occurrences, convert to lowercase, and output in lexicographical order.]
        printf("%c",ch);
        
    return 0;
}