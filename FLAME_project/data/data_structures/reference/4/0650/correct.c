#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int compar(const void* a, const void* b);
struct node {
    char s[10001];
    int num;

}p[10001];                           //存单词和次数


int main()
{
	int i,j,cnt = 0,k = 0,l;
	char x[10001];
    char c;
    FILE* f = fopen("article.txt", "r");
    while ((c = fgetc(f)) != EOF) {
        x[cnt++] = c;                 //读入所有字符
    }
    l=strlen(x);
    cnt = 0;
    for (i = 0; i<l; i++)
    {
         
        if((x[i]>='a'&&x[i]<='z')||(x[i]>='A'&&x[i]<='Z')){
		
		 p[cnt].s[k++] = tolower(x[i]); //是字母的话就变成小写加在后面。
        }
        else          
        {
            cnt++;                      //不是字母的话，直接增加单词的个数，可能会有空的，但没关系
            k = 0;                      //同时更新单词
        }
    }

    qsort(p, cnt, sizeof(p[0]), compar);    //对单词进行排序

    for (i = 0; i < cnt; i++)
        if(strlen(p[i].s)>0){ 
		p[i].num = 1;   } //如果有单词，该单词的数量加1
    for (i = 0; i < cnt; i++)
        if (strcmp(p[i].s, p[i + 1].s)==0)
        {
            p[i + 1].num += p[i].num;       //计算重复单词
            p[i].num = 0;
        }
    for (i = 0; i < cnt; i++)
        if (p[i].num != 0)
            printf("%s %d\n", p[i].s, p[i].num);    //输出
    return 0;
}
int compar(const void* a, const void* b)
{
    struct node* c = (struct node*)a; 
    struct node* d = (struct node*)b;
    return strcmp(c->s, d->s);          //对单词字典序排序
}


    

