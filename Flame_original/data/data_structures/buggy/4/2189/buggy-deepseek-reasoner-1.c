#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r"); // @@ Missing error check for fopen; should verify file opened successfully.
    char ch; // @@ Should be int to hold EOF correctly; char may be unsigned, causing infinite loop.
    while((ch=fgetc(in))!=EOF) // @@ ch is char, comparison with EOF may fail; also missing check for file open failure.
        printf("%c",ch); // @@ Does not count word frequency; should tokenize words, convert to lowercase, and output counts in lexicographic order.
        
    return 0;
}