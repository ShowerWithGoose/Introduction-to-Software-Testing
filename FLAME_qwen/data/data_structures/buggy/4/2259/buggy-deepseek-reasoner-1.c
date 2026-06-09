#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100]; // @@ buffer ch is only 100 bytes, but later fgets uses size 10000, causing buffer overflow
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ fgets size 10000 exceeds actual buffer size of ch (100); also fgets reads lines, not words
    printf("%s\n",ch); // @@ program does not process words; just prints entire lines, ignoring requirement to count word frequencies
    return 0;
}