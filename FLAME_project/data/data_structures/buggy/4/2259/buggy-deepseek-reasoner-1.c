#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ Buffer size (10000) exceeds allocated size of ch (100), causing buffer overflow; also loop does not extract words or count frequencies as required.
    printf("%s\n",ch); // @@ Outputs entire lines instead of word frequency counts in lexicographical order, which does not match expected output.
    return 0;
}