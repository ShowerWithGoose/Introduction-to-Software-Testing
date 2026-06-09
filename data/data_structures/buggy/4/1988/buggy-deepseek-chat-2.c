#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct list{
    char s[100];
    int sum;
};
struct list lists[100000];
int find(char s[], int ListNum);
int cmp(const void *pa, const void *pb);

int main() {
    FILE *in;       // 为读写文件定义文件指针
    in = fopen("article.txt", "r");      // 为输入打开一个给定文件"input.txt"；打开方式"r"为以只读方式打开一个文件
    char c='\000', s[100]={};
    int num=0, ListNum=0;   // num是单词有几个字母 ListNum是有几个单词
    while(c = fgetc(in) != EOF){    // @@ 运算符优先级错误：赋值运算符=优先级低于!=，导致c被赋值为比较结果（0或1），而非读取的字符。应改为 (c = fgetc(in)) != EOF
        if(!isalpha(c)){        // 空格，句号，换行
            if(s[0]!='\000'){
                s[num]='\000';
                if(!find(s, ListNum)){       // 没出现过本单词
                    strcpy(lists[ListNum].s, s);
                    lists[ListNum].sum = 1;
                    ListNum++;
                }
            }
            // 初始化
            num = 0;
            strcpy(s, "\000");
            continue;
        }else{
            s[num] = tolower(c);
            num++;
        }
    }

    qsort(lists, ListNum, sizeof(struct list), cmp);
    for(int i=0; i<ListNum; i++){
        printf("%s %d\n", lists[i].s, lists[i].sum);
    }

    return 0;
}

int find(char s[], int ListNum){
    for(int i=0; i<ListNum; i++){
        if(strcmp(lists[i].s, s) == 0){
            lists[i].sum++;
            return 1;
        }
    }
    return 0;
}

int cmp(const void *pa, const void *pb){
    struct list *da = (struct list *)pa;
    struct list *db = (struct list *)pb;
    if(strcmp(da->s, db->s) < 0){
        return -1;
    }else{
        return 1; // @@ 比较函数返回值错误：当两个字符串相等时，应返回0，但这里返回了1，导致qsort排序结果不正确。应添加else if(strcmp(da->s, db->s) > 0) return 1; else return 0;
    }
}