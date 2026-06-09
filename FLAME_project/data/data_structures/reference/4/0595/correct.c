#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Word
{
    char str[30];
    int n;
    struct Word *link;
} *head;

void addList(char *s)
{
    struct Word *p;
    p = (struct Word *)malloc(sizeof(struct Word));
    p->link = NULL;
    p->n = 1;
    strcpy(p->str,s);

    if(head == NULL){
        head = p;
        return;
    }
    int k;
    struct Word *tem = head,*t = head;

    if(strcmp(t->str,s) > 0){
        head = p;
        head->link = t;
        return;
    }
    while(tem != NULL){
        k = strcmp(tem->str,s);
        if(k < 0){
            t = tem;
            tem = tem->link;
            continue;
        }
        else if(k == 0){
            tem->n++;
            return;
        }
        break;
    }
    t->link = p;
    p->link = tem;
    return;
}

int main()
{
    FILE *fp;
    int i,m;
    char c,s[30] = {'\0'};
    struct Word *t;

    fp = fopen("article.txt","r");
    if(fp == NULL){
        printf("打开文件失败！");
        exit(1);
    }
    while(1){
        while(1){
            m = fscanf(fp,"%c",&c);
            if(m != 1)
                break;
            if((c <= 'z' && c >= 'a') || (c >= 'A' && c <= 'Z'))
                break;
        }
        if(m != 1)
            break;
        i = 0;
        while(1){
            if(c <= 'z' && c >= 'a')
                s[i++] = c;
            else if(c <= 'Z' && c >= 'A')
                s[i++] = c - 'A' + 'a';
            else
                break;
            fscanf(fp,"%c",&c);
        }
        s[i] = '\0';
        addList(s);
    }
    while(head != NULL){
        t = head;
        head = head->link;
        printf("%s %d\n",t->str,t->n);
        free(t);
    }
    fclose(fp);

    return 0;
}

