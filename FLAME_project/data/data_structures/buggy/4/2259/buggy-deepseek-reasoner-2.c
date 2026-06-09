#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL)@@ [Buffer overflow: ch size is 100 but fgets reads up to 10000; also the loop should extract words and count frequencies, not just print lines.]
    printf("%s\n",ch);@@ [This line prints the raw line, not word frequency counts as required.]
    return 0;
}