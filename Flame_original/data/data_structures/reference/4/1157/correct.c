#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxn 1000

typedef struct node
{
    int val;
    char str[100];
    int nxt, pre;
} node;

node point[maxn];
int tail;
int head = 1, end = 2;

char buf[maxn]; // gets的缓存区
char tmp[maxn]; // 插入字典的缓存区

void init() // 初始化函数
{
    tail = 2;
    point[1].nxt = 2;
    point[2].pre = 1;
    point[1].str[0] = 0; point[1].str[1] = '\0';
    point[2].str[0] = 'z' + 1; point[1].str[1] = '\0';
    return;
}

void nextWord(int *l, int *r) // 在buf中寻找下一个合法单词，并将其复制到tmp
{
    int f = 0, i;
    *l = *r; // 如果return时*l == *r 则无新单词
    for(i = *r; buf[i] != '\0'; ++i)
    {
        if(isalpha(buf[i]) && !f)
            *l = i, f = 1; // 遇到第一个字母
        if(f && isalpha(buf[i])) tmp[i - *l] = tolower(buf[i]); //大小写转换
        if(!isalpha(buf[i]) && f) // 在遇到字母后遇到第一个非字母
            break;
    }
    if(f == 1) *r = i, tmp[i - *l] = '\0';
    return ;
}

int findUpper(int l, int r) // 寻找第一个大于等于tmp中字符串的节点
{
    int now = head;
    while(now != end) // 遍历链表
    {
        if(strcmp(point[now].str, tmp) < 0) now = point[now].nxt;
        else return now; // 找到返回
    }
    return end;
}

void insert(int l, int r, int pos) // 插入tmp中的字符串
{
    if(strcmp(point[pos].str, tmp) == 0) // tmp中的单词已经存在
    {
        ++point[pos].val;
        return;
    }
    // 以下为新建节点
    ++tail;
    point[tail].val = 1;
    memcpy(point[tail].str, tmp, sizeof(char) * (r - l + 1)); // 拷贝tmp中字符串
    point[point[pos].pre].nxt = tail;
    point[tail].pre = point[pos].pre;
    point[tail].nxt = pos;
    point[pos].pre = tail;
    return ;
}

int main()
{
    #ifdef DBG
    freopen("in.txt", "r", stdin);
    #else
    freopen("article.txt", "r", stdin);
    #endif
    init();
    int p;
    while(gets(buf) != NULL)
    {
        int wl, wr = 0;
        nextWord(&wl, &wr);
        while(wr != wl)
        {
            p = findUpper(wl, wr);
            insert(wl, wr, p);
            nextWord(&wl, &wr);
        }
        memset(buf, 0, sizeof(buf));
    }
    for(int i = point[head].nxt; i != end; i = point[i].nxt)
        printf("%s %d\n", point[i].str, point[i].val);
    return 0;
}


