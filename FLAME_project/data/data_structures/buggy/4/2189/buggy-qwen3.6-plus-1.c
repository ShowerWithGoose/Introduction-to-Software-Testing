#include<stdio.h> // @@ The program simply reads and prints the file content character by character, failing to implement word parsing, case conversion, frequency counting, or sorting as required by the problem description.
int main(){
    FILE *in=fopen("article.txt","r");
    char ch;
    while((ch=fgetc(in))!=EOF)
        printf("%c",ch); // @@ This line outputs the raw file content instead of the calculated word frequencies in lexicographical order.
        
    return 0;
}