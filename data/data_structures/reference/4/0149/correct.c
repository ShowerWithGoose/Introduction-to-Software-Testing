//
//  main.c
//  词频统计链表版
//
//  Created by  on 2022/3/31.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 32
struct node{
    char word[MAXWORD];
    int count;
    struct node* link;
};
struct node *Wordlist = NULL;
int get_word(FILE *bfp, char *w);
int search_word(char *w);
int insert_word(struct node *p, char *w);
int main(int argc, const char * argv[])
{
    char filename[32], word[MAXWORD];
    FILE *bfp;
    bfp = fopen("article.txt", "r+");
    struct node *p;
    scanf("%s",filename);
    if ((bfp = fopen("article.txt", "r"))==NULL)
    {
        fprintf(stderr, "%s can't open this file\n",filename);
        return -1;
    }
    while (get_word(bfp, word)!=EOF)
    {
        if (search_word(word)==-1)
        {
            fprintf(stderr, "Memory is full\n");
            return -1;
        }
    }
    for (p=Wordlist; p!=NULL; p=p->link)
    {
        printf("%s %d\n",p->word,p->count);
    }
    fclose(bfp);
    return 0;
}
int get_word(FILE *bfp, char *w)
{
    int c;
    while (!isalpha(c=fgetc(bfp)))
    {
        if (c==EOF)
        {
            return c;
        }
        else continue;
    }
    do{
        *w++ = tolower(c);
        }while(isalpha(c=fgetc(bfp)));
    *w='\0';
    return 1;
}
int insert_word(struct node *p, char *w)
{
    struct node *q;
    q = (struct node*)malloc(sizeof(struct node));
    if (q==NULL)
        return -1;
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if (Wordlist == NULL)
        Wordlist = q;
    else if (p==NULL)
    {
        q->link = Wordlist;
        Wordlist = q;
    }
    else
    {
        q->link = p->link;
        p->link = q;
    }
    return 0;
}
int search_word(char *w)
{
    struct node *p, *q = NULL;
    for (p=Wordlist; p!=NULL; q=p,p=p->link)
    {
        if (strcmp(w, p->word)<0)
        {
            break;
        }
        else if (strcmp(w, p->word)==0)
        {
            p->count++;
            return 0;
        }
    }
    return insert_word(q, w);
}



