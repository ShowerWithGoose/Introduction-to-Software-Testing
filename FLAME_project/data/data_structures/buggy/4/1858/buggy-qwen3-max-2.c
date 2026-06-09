#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // 包含ctype.h头文件，以使用isalpha和tolower函数

#define MAXWORD  32

struct node {
    char word[MAXWORD];
    int count;
    struct node *link;
}; // 单词表结构

struct node *Wordlist = NULL; // 单词表头指针

int getWord(FILE *bfp, char *w);
int searchWord(char *w);
int insertWord(struct node *p, char *w);

int main() {
    char word[MAXWORD];
    FILE *bfp;

    if ((bfp = fopen("article.txt", "r")) == NULL) { // 打开一个文件
        printf("article can't open!\n");
        return -1;
    }

    while (getWord(bfp, word) != EOF) { // 从文件中读入一个单词
        if (searchWord(word) == -1) { // 在单词表中查找插入单词
            fprintf(stderr, "Memory is full!\n");
            return -1;
        }
    }

    fclose(bfp); // 关闭文件

    struct node *p;
    for (p = Wordlist; p != NULL; p = p->link) { // 遍历输出单词表
        printf("%s  %d\n", p->word, p->count); // @@ [Output uses two spaces between word and count, but expected output uses only one space]
    }

    return 0;
}

int getWord(FILE *bfp, char *w) {
    int c;
    while ((c = fgetc(bfp)) != EOF) {
        if (isalpha(c)) {
            *w++ = tolower(c); // 转换为小写
            while ((c = fgetc(bfp)) != EOF && isalpha(c)) {
                *w++ = tolower(c); // 继续读入并转换为小写
            }
            *w = '\0'; // 在单词末尾添加字符串结束符
            return 0; // @@ [Should return 1 or non-EOF value to indicate success; returning 0 causes loop condition in main to misinterpret success as EOF]
        }
    }
    return EOF; // 文件结束
}

int insertWord(struct node *p, char *w) {
    struct node *q;

    q = (struct node *)malloc(sizeof(struct node));
    if (q == NULL) return -1; // 没有内存空间
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if (Wordlist == NULL) // 空链表
        Wordlist = q;
    else if (p == NULL) { // 插入到头结点前
        q->link = Wordlist;
        Wordlist = q;
    } else {
        q->link = p->link;
        p->link = q;
    }
    return 0;
}

int searchWord(char *w) {
    struct node *p, *q = NULL; // q为p的前序结点指针
    for (p = Wordlist; p != NULL; q = p, p = p->link) {
        if (strcmp(w, p->word) < 0)
            break;
        else if (strcmp(w, p->word) == 0) {
            p->count++;
            return 0;
        }
    }
    return insertWord(q, w);
}