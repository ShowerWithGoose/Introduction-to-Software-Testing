#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ [Buffer overflow: 'ch' is only 100 characters long, but fgets reads up to 10000 characters, which can cause memory corruption.]
    printf("%s\n",ch);
    return 0;
}