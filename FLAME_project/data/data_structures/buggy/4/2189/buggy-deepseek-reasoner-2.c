#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r");
    char ch;
    while((ch=fgetc(in))!=EOF) // @@ [Error: This loop prints the file content instead of counting word frequencies. The program does not extract words, convert to lowercase, or count occurrences.]
        printf("%c",ch); // @@ [Error: Printing characters directly outputs the raw file content, not the required word frequency list. The program lacks word storage, sorting, and proper output formatting.]
        
    return 0;
}