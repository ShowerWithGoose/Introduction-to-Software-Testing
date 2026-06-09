#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int N = 0; // 单词总数
struct list_node{ // 单词表结点
    char word[33];
    int count; // 词频数
};
// 从文件中读入一个单词（仅由字母组成的串），并转换成小写字母
int getWord(FILE *fp, char *w){ // *w为word字符数组的头指针，后同
    char c;
    while(!isalpha(c = fgetc(fp))){ // isalpha(): 非字母则返回0
        if(c == EOF) return c;  
        else continue;
    }
    do{ // 转换小写
        *w++ = tolower(c);
    } while(isalpha(c = fgetc(fp))); 
    *w = '\0';
    return 1;
}
// 在表中相应位置插入一个单词，同时置词频数为1
void insertWord(struct list_node list[], int pos, char *w){
    int i;
    for(i=N-1; i>=pos; --i){
        strcpy(list[i+1].word, list[i].word); //后移
        list[i+1].count = list[i].count;
    }
    strcpy(list[pos].word, w);
    list[pos].count = 1;
    N += 1;
    return;
}
// 在表中查找一单词（二分法），若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时词频数置1
void searchWord(struct list_node list[], char *w){
    int low = 0, high = N - 1, mid = 0;
    while(low <= high){
        mid = (high + low) / 2;
        if(strcmp(w, list[mid].word) < 0)
            high = mid -1;
        else if(strcmp(w, list[mid].word) > 0)
            low = mid + 1;
        else{ // 找到了，次数加1
            list[mid].count ++;
            return;
	    }
    }
    // 未找到，将该单词w插入到low位置
    insertWord(list, low, w);
}
int main()
{
    struct list_node wordlist[1025]; // 单词表
    char word[33]; // 临时储存词语
    int i;
    FILE *in;
    in = fopen("article.txt","r");
    while(getWord(in, word) != EOF){
        searchWord(wordlist, word);
    }
    for(i=0; i<=N-1; ++i)
        printf("%s %d\n", wordlist[i].word, wordlist[i].count);
    system("pause");
    return 0;
}
