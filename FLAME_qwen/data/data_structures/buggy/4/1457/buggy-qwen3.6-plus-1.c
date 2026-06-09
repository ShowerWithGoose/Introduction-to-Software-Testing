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
    
    char c=fgetc(fp); // @@ c should be declared as int to correctly hold the EOF value returned by fgetc
    while(!isalpha(c)){ // @@ Missing EOF check, may cause infinite loop or undefined behavior if file contains only non-alphabetic characters or is empty
        c=fgetc(fp);
    }
    int i=0;
    while(~c){ // @@ ~c is not a standard or safe way to check for EOF; should use c != EOF
        if(isalpha(c)){
            word[i]=tolower(c);
            i++; 
        }
        else{
            word[i]='\0'; //必须置0  // @@ Should check if i > 0 to avoid counting empty strings when consecutive non-alphabetic characters are encountered
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
        c=fgetc(fp); // @@ When c becomes EOF, the loop terminates immediately without processing the final word accumulated in the buffer
    }
    
    
    fclose(fp);

    qsort(w, n, sizeof(Word), compare);

    for (int i = 0; i < n; ++i) {
        printf("%s %d\n", w[i].word, w[i].count);
    }

    return 0;
}