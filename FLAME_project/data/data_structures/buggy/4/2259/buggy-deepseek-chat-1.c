#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ [Error: The buffer size in fgets is 10000, but ch is declared as char ch[100], causing buffer overflow. Also, the program only prints the file content and does not count word frequencies as required.]
    printf("%s\n",ch); // @@ [Error: This line prints each line of the file, which is not the required output format. The program should output word frequencies in lexicographical order.]
    return 0;
}