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
    while(!isalpha(c)){
        c=fgetc(fp);
    }
    int i=0;
    while(~c){
        if(isalpha(c)){
            word[i]=tolower(c);
            i++; 
        }
        else{
            word[i]='\0'; //必须置0 // @@ [When i==0, this sets word[0]='\0', creating an empty string. The subsequent code adds this empty word to the list, causing a blank line with count in the output.]
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