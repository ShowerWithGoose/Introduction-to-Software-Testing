#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ [Error: The buffer 'ch' is declared as char ch[100], but fgets is reading up to 10000 characters, causing a buffer overflow. Additionally, the program does not implement the required word frequency counting or lexicographical output as specified in the problem description.]
    printf("%s\n",ch);
    return 0;
}