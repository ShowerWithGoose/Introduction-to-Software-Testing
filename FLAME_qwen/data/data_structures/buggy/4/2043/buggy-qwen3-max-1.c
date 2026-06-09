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

    scanf("%s", filename); // @@ [The problem states that the program should read from "article.txt" directly, but this line reads a filename from stdin, which is not required and may cause issues if input is not provided. However, the real error causing compilation failure is missing fclose(bfp); but that wouldn't cause compilation error. Actually, the compilation error in test output "/bin/sh: 1: gcc: not found" indicates environment issue, but based on code logic and expected behavior, the actual bug is in output format and EOF handling. But since error type says Compilation Error, yet code compiles fine normally. Re-examining: The true logical errors are:]
    if((bfp = fopen("article.txt", "r")) == NULL){
        fprintf(stderr, "%s  can't open!\n", "article.txt");
        return -1;
     }
    while( getWord(bfp,word) != EOF) // @@ [getWord returns -1 on EOF, not EOF itself. So condition should be != -1. This causes infinite loop or incorrect termination.]
        if(searchWord(wordlist, word) == -1) {
            fprintf(stderr, "Wordlist is full!\n");
            return -1;
        }
    for(i=0; i<= N-1; i++)
        printf("%s  %d\n", wordlist[i].word, wordlist[i].count); // @@ [Output uses two spaces between word and count, but problem requires exactly one space.]
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
        list[i+1] = list[i]; // @@ [This assignment copies struct by value, which is acceptable in C, so not an error. No issue here.]
    
    strcpy(list[pos].word, w);
    list[pos].count = 1;
    N++;
    return 1;
 }