#include <stdio.h>
#include<string.h>
#include<stdlib.h>
char ch[100],ch0[100];
char str[100][100];
int str_num[100];
int main(int argc, char** argv) {
    FILE *in=fopen("article.txt","r");
    while((fgets(ch,10000,in))!=NULL) // @@ 错误：fgets的第二个参数10000超出了ch数组的大小100，可能导致缓冲区溢出；同时未检查文件是否成功打开
    printf("%s\n",ch);
    return 0;
}