#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ Buffer overflow: 'ch' is declared with size 100, but fgets is called with size 10000, which will write beyond the array bounds and cause undefined behavior.
    printf("%s\n",ch); // @@ Logical error: The program merely prints raw lines from the file. It completely fails to parse individual words, convert them to lowercase, count their frequencies, and output the results in lexicographical order as required by the problem.
    return 0;
}