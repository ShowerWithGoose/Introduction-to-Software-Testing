#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct wordsTimes{
    char s[50];
    int cntWord;
    struct wordsTimes *link;
}node,*nodeptr;
char c[150],word[50];//sen用于存储整个句子,word用于暂时存储从文件读入的每一个单词
nodeptr head=NULL,u,qm,pm;

void getData(char word[50]);
void createList(FILE *in);
void seperate(char c[150]);

int main()
{
    FILE *in;
    in = fopen("article.txt","r");
    createList(in);
    u = head;
    while(u != NULL){
        printf("%s %d\n",u->s,u->cntWord);
        u = u->link;
    }
    fclose(in);
    return 0;
}

void createList(FILE *in)
{
    while((fgets(c, 150, in)) != NULL)
        seperate(c);//分隔单词
}

void getData(char word[50])
{
    pm = head;//开始判断字符串的位置并加入到链表中
    int is_put = 0;
    while(is_put == 0){
        if(pm == NULL){
            pm=u;
            strcpy(pm->s,word);
            pm->cntWord = 1;
            break;
        }else if(strcmp(pm->s,word) == 0){
            (pm->cntWord)++;
            break;
        }
        else if (pm->link == NULL){
            strcpy(u->s,word);
            u->cntWord = 1;
            break;
        }else if (strcmp(pm->s,word) < 0 && strcmp(pm->link->s,word) > 0){
            nodeptr u;
            u = (nodeptr)malloc(sizeof(node));
            strcpy(u->s,word);
            u->cntWord = 1;
            u->link = pm->link;
            pm->link = u;
            break;
        }else if(pm == head && strcmp(pm->s,word) > 0){
            nodeptr u;
            u = (nodeptr)malloc(sizeof(node));
            strcpy(u->s,word);
            u->cntWord = 1;
            u->link = head;
            head = u;
            break;
        }else
            pm = pm->link;
    }
}

void seperate(char c[150])
{
    int i = 0,cntWord = 0;
    for(;i < (int)strlen(c);i++){
        if(c[i] >= 'A' && c[i] <= 'Z')
            c[i] -= ('A'-'a');
        if(c[i] >= 'a' && c[i] <= 'z'){
            word[cntWord++] = c[i];
        }
        else{
            word[cntWord] = '\0';
            if(word[0] != '\0'){
                u = (nodeptr)malloc(sizeof(node));
                u->link = NULL;
                getData(word);
                cntWord = 0;
                if(strlen(u->s) != 0){
                if(head != NULL)
                    qm->link = u;
                else
                    head = qm = u;
                qm=u;
                }else
                    continue;
            }
            else
                continue;
        }
    }
}



