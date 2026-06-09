#include<stdio.h>
#include<string.h>
#include<iostream> // @@ 在C程序中不应包含C++头文件，可能导致编译错误或警告
#include<stdlib.h>//先q 后判重归类
char str[105], data[105][20]; // @@ 数组大小可能过小，若单词长度超过19或单词数量超过105会导致溢出
int id[105];
int cmp(const void*p, const void*q)
{
    int a = *(int*)p;
    int b = *(int*)q;
    return strcmp(data[a], data[b]);
}
int main()
{
    FILE*in;
    in = fopen("article.txt", "r"); // @@ 未检查fopen返回值，文件不存在时将错误
    int n, j = 0, i = 0, state, len, s = 1, site = 0, k;
    while(~fscanf(in, "%s", str)) // @@ fscanf返回值检查方式不够标准，但功能正确
    {
        len = strlen(str);
        for(n = 0; n < len; n++)
        {
            j = 0;
            state = 0;
            while(isalpha(str[n]))
            {
                state = 1;
                data[i][j] = tolower(str[n]); // @@ 若超出data列大小20，将越界
                n++;
                id[i] = i;
                j++;
            }
            if(state > 0)
            {
                i++;
            }
        }    
    }
    fclose(in);
    qsort(id, i, sizeof(id[0]), cmp);
    printf("%s ", data[id[0]]); // @@ 错误：第一个单词的计数未被输出，且缺少换行，不符合输出格式
    for(k = 1; k < i; k++)
    {
        if(strcmp(data[id[k]], data[id[k-1]]) == 0)
        {
            site = 1;
            s++;
        }
        else
        {
            site = 0;
            printf("%d\n%s ", s, data[id[k]]); // @@ 错误：输出顺序和格式颠倒，应先输出单词再输出计数，且最后一行不应有歧义
            s = 1;
        }
    }
    if(site == 0) // @@ 逻辑复杂且可能错误：对于单个单词或多个单词的最后一行应有统一处理，且缺少末尾换行符
    {
        printf("1");
    }
    else
    {
        printf("%d", s);
    }
    return 0 ;
}