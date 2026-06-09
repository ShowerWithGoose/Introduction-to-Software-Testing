//本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 32
struct link{
    char word[MAXWORD];
    int num;
    struct link *next;
};
struct link *wordlist = NULL;
int getword(FILE *fp, char word[MAXWORD]);
int searchword(char *w);
int insertword(struct link *p, char *w);
int main()
{
    FILE *fp;
    char word[MAXWORD];
    struct link *p, *q;
    if((fp = fopen("article.txt", "r")) == NULL){
        printf("article.txt can't open!\n");
    }
    while(getword(fp, word) != EOF){
        if(searchword(word) == -1){
            printf("The memory is full!\n");
            fclose(fp);
            return -1;
        }
    }
    for(p = wordlist; p != NULL; p = p->next){
        printf("%s %d\n", p->word, p->num);
    }
    return 0;
}
int getword(FILE *fp, char *w)
{
    char c;
    while(!isalpha(c = fgetc(fp))){
        if(c == EOF){
            return c;
        }
        else continue;
    }
    do{
        *w++ = tolower(c);
        c = fgetc(fp);
    }while(isalpha(c));
    *w = '\0';
    return 1;
}
int searchword(char *w)
{
    struct link *p, *q = NULL;
    for(p = wordlist; p != NULL; q = p, p = p->next){
        if(strcmp(p->word, w) == 0){
            p->num++;
            return 0;
        }
        else if(strcmp(p->word, w) > 0){
            break;
        }
    }
    return insertword(q, w);
}
int insertword(struct link *q, char *w)
{
    struct link *t;
    t = (struct link*)malloc(sizeof(struct link));
    t->next = NULL;
    t->num = 1;
    strcpy(t->word, w);
    if(wordlist == NULL){
        wordlist = t;
    }
    else if(q == NULL){
        t->next = wordlist;
        wordlist = t;
    }
    else {
        t->next = q->next;
        q->next = t;
    }
    return 0;
}


