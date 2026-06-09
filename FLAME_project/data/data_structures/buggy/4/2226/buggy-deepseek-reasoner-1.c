# include <stdio.h>
int main(int argc, const char * argv[]) 
{
    FILE *b;
    char filename[32]={"article.txt"};
    char c;
    if((b = fopen(filename, "r")) == NULL)
        { 
            fprintf(stderr, "%s  can¡¯t open!\n",filename);
            return -1;
        }
    while((c=fgetc(b) ) != EOF) // @@ 错误：应读取单词并统计词频，而不是直接输出字符
        printf("%c",c); // @@ 错误：输出字符不符合题目要求，应转换为小写并统计出现次数
    printf("Hello, World!\n"); // @@ 错误：输出无关的字符串，应输出词频统计结果
    return 0;
}