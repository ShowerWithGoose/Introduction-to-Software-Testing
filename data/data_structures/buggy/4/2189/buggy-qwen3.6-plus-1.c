#include<stdio.h>
int main(){
    FILE *in=fopen("article.txt","r");
    char ch; // @@ ch should be declared as int to correctly handle the EOF value returned by fgetc
    while((ch=fgetc(in))!=EOF) // @@ The loop only prints characters; it completely lacks the logic to extract words, convert case, count frequencies, and sort results
        printf("%c",ch); // @@ Should implement word frequency counting and lexicographical output instead of printing raw characters
        
    return 0;
}