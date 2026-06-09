#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _Word{
    char word[100];
    int count;
} Word;

int compare(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main() {
    FILE *fp = fopen("article.txt", "r");
    if (fp == NULL) {
        perror("Failed to open the file.\n");
        return 1; 
    }
    // 初始化单词数组
    Word w[1000];
    int n = 0;

    // 初始化每个单词的计数为0
    for (int i = 0; i < 1000; ++i) {
        w[i].count = 0;
    }

    // 读取文件并统计单词出现次数
    char word[100];
    
    char c=fgetc(fp);
    while(!isalpha(c)){ // @@ 如果文件为空或全部是非字母字符，则会进入无限循环，因为EOF（-1）不是字母，条件始终为真。
        c=fgetc(fp);
    }
    int i=0;
    while(~c){ // @@ 循环条件使用~c检测EOF，但c是char类型，可能无法正确检测EOF；另外，若文件以字母结尾，最后一个单词不会被处理，需在循环结束后补充处理。
        if(isalpha(c)){
            word[i]=tolower(c);
            i++; 
        }
        else{
            word[i]='\0'; // @@ 当i==0时，即连续遇到非字母字符，此处会将空串存入word，导致后续添加空单词到数组中，应添加条件 i>0 才处理。
            int flag=0;
         for (int j = 0; j < n; ++j) {
            if (strcmp(w[j].word, word) == 0) {
                w[j].count++;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            strcpy(w[n].word, word);
            w[n].count = 1;
            n++;
        }
        i=0;
    }
        c=fgetc(fp);
    }
    
    
    fclose(fp);

    qsort(w, n, sizeof(Word), compare);

    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", w[i].word, w[i].count);
    }

    return 0;
}