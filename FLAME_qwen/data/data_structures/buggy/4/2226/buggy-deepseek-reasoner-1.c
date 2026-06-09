# include <stdio.h>
int main(int argc, const char * argv[]) 
{
    FILE *b;
    char filename[32]={"article.txt"};
    char c;
    if((b = fopen(filename, "r")) == NULL)
        { 
            fprintf(stderr, "%s  can¡¯t open!\n",filename); // @@ 非ASCII字符"¡¯"可能导致编译错误，且错误信息不标准
            return -1;
        }
    while((c=fgetc(b) ) != EOF) // @@ 将fgetc返回值赋给char，无法正确比较EOF（通常为-1），应使用int类型
        printf("%c",c); // @@ 仅输出字符，未实现词频统计功能
    printf("Hello, World!\n"); // @@ 多余的输出，不符合题目要求
    return 0;
}