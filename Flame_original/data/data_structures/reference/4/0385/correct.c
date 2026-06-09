#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct wordsTimes{
    char s[50];
    int cnt;
    struct wordsTimes *link;
}node,*nodeptr;
char sen[150],word[50];//sen用于存储整个句子,word用于暂时存储从文件读入的每一个单词
nodeptr list=NULL,p,q,r;

void getData(char word[50]);
void createList(FILE *in);
void seperate(char sen[150]);

int main()
{
    FILE *in;
    in = fopen("article.txt","r");
    createList(in);
    p = list;
    while(p != NULL){
        printf("%s %d\n",p->s,p->cnt);
        p = p->link;
    }
    fclose(in);
    return 0;
}

void createList(FILE *in)
{
    while((fgets(sen, 150, in)) != NULL)
        seperate(sen);//分隔单词
}

void getData(char word[50])
{
    r = list;//开始判断字符串的位置并加入到链表中
    int isIN = 0;
    while(isIN == 0){
        if(r == NULL){
            r=p;
            strcpy(r->s,word);
            r->cnt = 1;
            break;
        }else if(strcmp(r->s,word) == 0){
            (r->cnt)++;
            break;
        }
        else if (r->link == NULL){
            strcpy(p->s,word);
            p->cnt = 1;
            break;
        }else if (strcmp(r->s,word) < 0 && strcmp(r->link->s,word) > 0){
            nodeptr u;
            u = (nodeptr)malloc(sizeof(node));
            strcpy(u->s,word);
            u->cnt = 1;
            u->link = r->link;
            r->link = u;
            break;
        }else if(r == list && strcmp(r->s,word) > 0){
            nodeptr u;
            u = (nodeptr)malloc(sizeof(node));
            strcpy(u->s,word);
            u->cnt = 1;
            u->link = list;
            list = u;
            break;
        }else
            r = r->link;
    }
}

void seperate(char sen[150])
{
    int i = 0,cnt = 0;
    for(;i < (int)strlen(sen);i++){
        if(sen[i] >= 'A' && sen[i] <= 'Z')
            sen[i] -= ('A'-'a');
        if(sen[i] >= 'a' && sen[i] <= 'z'){
            word[cnt++] = sen[i];
        }
        else{
            word[cnt] = '\0';
            if(word[0] != '\0'){
                p = (nodeptr)malloc(sizeof(node));
                p->link = NULL;
                getData(word);
                cnt = 0;
                if(strlen(p->s) != 0){
                if(list != NULL)
                    q->link = p;
                else
                    list = q = p;
                q=p;
                }else
                    continue;
            }
            else
                continue;
        }
    }
}



