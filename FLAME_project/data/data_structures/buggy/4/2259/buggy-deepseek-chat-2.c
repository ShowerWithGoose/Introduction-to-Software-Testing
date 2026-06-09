#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ [Error: The second argument to fgets should be the size of the buffer, which is 100, not 10000. This can cause buffer overflow and undefined behavior.]
    printf("%s\n",ch); // @@ [Error: This line prints the raw input lines instead of counting word frequencies and outputting them in lexicographical order as required. The entire program logic is missing.]
    return 0;
}