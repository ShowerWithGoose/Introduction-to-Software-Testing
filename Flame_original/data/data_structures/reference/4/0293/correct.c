#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024
#define WORD 64
char trans(char a){//大写换成小写
    if (a >= 65 && a <= 90)
        a += 32;
    return a; 
}

typedef struct{//用于记录单词的结构体
    char word[WORD];
    int cnt;
    struct sta *next;
}sta;

int main(){
    int i,j,len;
    char line[MAX + 1] = {};
    sta *head,*p,*q,*r;
    FILE *in;
    in = fopen("article.txt","r");
    if(in == NULL)
        return -1;//打开失败时返回-1
    
    head = (sta *)malloc(sizeof(sta));//留出空表头
    if(head == NULL)
        return -2;//申请失败时返回-2
    head->next = NULL;
    head->word[0] = 0;

    while(fgets(line,MAX,in) != NULL){
        len = strlen(line);
        for(i = 0;i < len;i++)
            line[i] = trans(line[i]);

        for(i = 0;i < len;i++){
            if(line[i] >= 97 && line[i] <= 122){
                r = (sta *)malloc(sizeof(sta));
                r->cnt = 1;
                r->next = NULL;
                for(j = 0;j < WORD;j++)
                    r->word[j] = 0;
                for(j = 0;line[i] >= 97 && line[i] <= 122;i++,j++)
                    r->word[j] = line[i];

                q = head;
                for(;;){
                    if(q != NULL){
                        if(strcmp(q->word,r->word) < 0){
                            p = q;
                            q = q->next;
                            continue;
                        }
                        else{
                            if(strcmp(q->word,r->word) > 0){
                                p->next = r;
                                r->next = q;
                            }
                            else{
                                (q->cnt)++;
                                free(r);    
                            }
                            break;
                        }
                    }
                    else{
                        r->next = NULL;
                        p->next = r;
                        break;
                    }
                }
            }
            else
                continue;
        }
    }
    
    for(r = head->next;r != NULL;r = r->next)
        printf("%s %d\n",r->word,r->cnt);
    fclose(in);
    return 0;
} 
