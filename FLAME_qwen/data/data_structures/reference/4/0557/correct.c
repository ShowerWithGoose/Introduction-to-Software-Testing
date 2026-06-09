#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXSIZE 100
typedef struct list{
    char a[MAXSIZE];
    int cnt;
} list;
list words[10000];

char buf[MAXSIZE];

int num = 0, flag = 1;
int getWord(FILE* fp);
int cmp(const void *a, const void *b);
void del(void);
void output(void);

int main() {
    FILE *fin  = fopen("article.txt", "r+");
    while (getWord(fin) != EOF);//只读取单词
    qsort(words, num, sizeof(list), cmp);//字典序排序
    del();//去重
    output();//输出
    fclose(fin);
    return 0;
}
int getWord(FILE *fp){
    while (strlen(buf) == 0) {
        if(fscanf(fp, "%[a-zA-Z]s", buf) != EOF && flag){
            flag = 0;
            continue;
        }
        if (fscanf(fp, "%*c%[a-zA-Z]s", buf) == EOF) {//只读取单词，忽略任意其他字符
            return EOF;
        }
    }
    int i = 0;
    while (isalpha(buf[i])) {
        buf[i] = tolower(buf[i]);//转换小写
        i++;
    }
    words[num].cnt = 1;
    strcpy(words[num++].a, buf);//单词复制给结构体
    memset(buf, 0, sizeof(buf));
    return 1;
}
int cmp(const void *a, const void *b){//字典序
    list *x = (list*)a;
    list *y = (list*)b;
    return strcmp(x->a, y->a);
}
void del(void){
    int i;
    for (i = 0; i < num; i++) {
        int j = 1;
        while (!strcmp(words[i].a, words[i+j].a)) {//去重
            words[i].cnt += words[i+j].cnt;
            words[i+j].cnt = 0;
            j++;
        }
    }
}
void output(void){//输出
    int i;
    for (i = 0; i < num; i++) {
        if (words[i].cnt == 0) {
            continue;
        }else{
            printf("%s %d\n", words[i].a, words[i].cnt);
        }
    }
}



