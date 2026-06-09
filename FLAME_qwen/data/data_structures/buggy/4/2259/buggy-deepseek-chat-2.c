#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ [Error: fgets buffer size 10000 exceeds array ch size of 100, causing buffer overflow; also fgets returns NULL on error/EOF, but the loop logic is incomplete for word frequency counting]
    printf("%s\n",ch);
    return 0;
}