#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL)
    printf("%s\n",ch); // @@ [The buffer 'ch' is declared with size 100, but fgets reads up to 10000 characters, causing a buffer overflow. This leads to undefined behavior and potential compilation/runtime errors. Additionally, the program does not implement word frequency counting or lexicographical output as required by the problem.]
    return 0;
}