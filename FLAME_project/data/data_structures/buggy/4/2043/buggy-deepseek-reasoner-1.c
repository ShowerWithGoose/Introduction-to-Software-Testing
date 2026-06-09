/*词频统计：晏老师课件上代码*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD  32
#define MAXSIZE  1024

struct lnode {
    char word[MAXWORD];
    int count;
};

int N=0; //单词表中单词的实际个数

int getWord(FILE *bfp,char *w);
int searchWord(struct lnode list[], char *w);
int insertWord(struct lnode list[ ],  int pos, char *w);

int main()
{
    struct lnode wordlist[MAXSIZE];    /*单词表*/
    int i;    
    char filename[MAXWORD], word[MAXWORD];
    FILE *bfp;

    scanf("%s", filename);
    if((bfp = fopen("article.txt", "r")) == NULL){
        fprintf(stderr, "%s  can't open!\n", "article.txt");
        return -1;
     }
    while( getWord(bfp,word) != EOF)
        if(searchWord(wordlist, word) == -1) {
            fprintf(stderr, "Wordlist is full!\n");
            return -1;
        }
    for(i=0; i<= N-1; i++)
        printf("%s  %d\n", wordlist[i].word, wordlist[i].count); // @@ 输出格式错误：单词和数字之间应为单个空格，但这里使用了两个空格，导致输出与预期不符。
    return 0;
} 
/* getWord:从文件中读入一个单词（仅由字母组成的串），并转换成小写字母*/
int getWord(FILE *bfp, char *w){
    int c;
    
    while(!isalpha(c = fgetc(bfp)))
        if(c == EOF)
            return -1;
        else continue;
    do{
        *w++ = tolower(c);
    }while(isalpha(c = fgetc(bfp)));
    *w = '\0';
    return 1;
}
/* searchWord: 在表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/ 
int searchWord(struct lnode list[], char *w)
{
    int low = 0, high = N - 1, mid = 0;
    while(low <= high){
        mid = (high + low) / 2;
        if(strcmp(w, list[mid].word) < 0)
            high = mid - 1;
        else if(strcmp(w, list[mid].word) > 0)
            low = mid + 1;
        else{
            list[mid].count++;
            return 0;
        }
    }
    return insertWord(list, low, w);
}
/* insertWord: 在表中相应位置插入一个单词，同时置次数为1*/
int insertWord(struct lnode list[], int pos, char *w)
{
    int i;
    
    if(N == MAXSIZE)
        return -1;
    for(i = N - 1; i >= pos; i--)
        list[i+1] = list[i];
    
    strcpy(list[pos].word, w);
    list[pos].count = 1;
    N++;
    return 1;
 }