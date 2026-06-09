#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
typedef struct
{
    char w[20];
    int n;
}word;
int cmp(const void* a, const void* b)
{
    return strcmp((char*)a, (char*)b); // @@ 比较函数类型错误：应先将参数转换为 word* 再比较其 w 成员，否则可能导致未定义行为
}
int main()
{
    FILE* in;
    in = fopen("article.txt", "r");
    word a[100] = { 0 };
    int i = 0, flag = 0;
    while (1)
    {
        int x = 0, j = 0;
        char k[20] = { 0 };
        x = fgetc(in);
        while ((x>= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
        {
            k[j] = tolower(x);
            j++;
            flag = 1;
            x = fgetc(in);
        }
        if (x == -1)
            break;
        if(flag)
        {
            for (int q = 0; q < i; q++)
            {
                if (!strcmp(k, a[q].w))
                {
                    a[q].n++;
                    break;
                }
                else if (q == i - 1) // @@ 条件错误：应在遍历完所有已有单词且未找到匹配时添加新单词，此条件仅当 i>0 时可能触发，但添加位置 a[i] 是未初始化区域，且后续无条件 i++ 导致逻辑混乱
                {
                    strcpy(a[i].w, k);
                    a[i].n++;
                }
            }
            i++; // @@ 错误：无论是否添加新单词都递增 i，导致数组中出现未初始化的元素，并第一次遇到单词时因 i=0 循环不执行而丢失单词
        }
        flag = 0;
    }
    qsort(a, i, sizeof(a[0]), cmp);
    for (int q = 0; q < i; q++)
    {
        printf("%s %d\n", a[q].w, a[q].n);
    }
    return 0; 
}