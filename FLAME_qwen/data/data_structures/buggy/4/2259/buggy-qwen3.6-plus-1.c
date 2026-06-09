#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r"); // @@ Missing NULL check for fopen; if the file fails to open, 'in' will be NULL, causing undefined behavior/crash in fgets.
    while((fgets(ch,10000,in))!=NULL) // @@ Buffer overflow: 'ch' is declared with size 100, but 10000 is passed as the size limit to fgets. Also, fgets reads entire lines instead of individual words.
    printf("%s\n",ch); // @@ Logical error: The program only prints raw lines. It completely lacks the logic to parse words, convert to lowercase, count frequencies, and sort lexicographically as required.
    return 0;
}