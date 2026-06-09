#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 10000
struct node{
    char s[500];
    int num;
}p[MAX];                           //存单词和次数

int cmp(const void* a, const void* b)
{
    struct node* c = (struct node*)a; 
    struct node* d = (struct node*)b;
    return strcmp(c->s, d->s);          //对单词字典序排序
}
int main()
{
    FILE* fp = fopen("article.txt", "r");
    char str[14124];
    char c;
    int cnt = 0;
    while ((c = fgetc(fp)) != EOF) {
        str[cnt] = c; 
		cnt++;                //读入所有字符
    }
    cnt = 0;
    int k = 0;
    for (int i = 0; i<strlen(str); i++)
    {
         if (!isalpha(str[i]))          
        {
            cnt++;                      //不是字母的话，直接增加单词的个数，可能会有空的，但没关系
            k = 0;                      //同时更新单词
        }
        else if(isalpha(str[i]))
			p[cnt].s[k++] = tolower(str[i]); //是字母的话就变成小写加在后面。
    }
    qsort(p, cnt, sizeof(p[0]), cmp);    //对单词进行排序

    for (int i = 0; i < cnt; i++)
        if(strlen(p[i].s)) p[i].num = 1;    //如果有单词，该单词的数量加1
    for (int i = 0; i < cnt; i++)
        if (!strcmp(p[i].s, p[i + 1].s))
        {
            p[i + 1].num += p[i].num;       //计算重复单词
            p[i].num = 0;
        }
    for (int i = 0; i < cnt; i++)
        if (p[i].num != 0)
            printf("%s %d\n", p[i].s, p[i].num);    //输出
    return 0;
}

