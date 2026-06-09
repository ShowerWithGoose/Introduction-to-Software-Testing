#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL)
    printf("%s\n",ch); // @@ [Buffer overflow: 'ch' is only 100 characters long but fgets tries to read up to 10000 characters, which causes undefined behavior. Also, the program does not implement word frequency counting or lexicographical output as required by the problem.]
    return 0;
}