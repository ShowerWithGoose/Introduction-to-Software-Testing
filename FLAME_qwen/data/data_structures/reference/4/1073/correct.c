#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Word{
    char words[100];
    int times;
    struct Word *next;
}word;

typedef struct Head{
    word word;
}head;

word *init_word(char* words){
    word *p = (word*)malloc( sizeof (word) );
    strcpy(p->words , words);
    p->times = 1;
    p->next = NULL;
    return p;
}

head *init_head(){
    head *h = (head*)malloc(sizeof(head));
    h->word.next = NULL;
    return h;
}

void clear_word(word* p) {
    if(p==NULL)return;
    free(p);
    return;
}

void clear_head(head* h) {
    if(h==NULL)return;
    word *p = h->word.next, *q;
    while (p) {
        q = p->next;
        clear_word(p);
        p = q;
    }
    free(h);
    return ;
}

void insert(head *h , int ind , char* words) {
    word *p = init_word(words) , *q = &(h->word) , *temp;
    while (ind--) q = q->next;
    temp = q->next;
    q->next = p;
    p->next = temp;
    return;
}

void erase(head *h , int ind) {
    word *p = &(h->word) , *q;
    while(ind--) p = p->next;
    q = p->next->next;
    clear_word(p->next);
    p->next = q;
    return;
}

int cmp(int );

int main(){
    char words[1000];
    int i , j = 0 , flag , end = 0; 
    head *h = init_head();
    word *p;
    FILE *fp1 = fopen("article.txt","r");
    while(1){
        words[j] = fgetc(fp1);
        if(words[j] <= 'Z' && words[j] >= 'A'){
            words[j] += 'a' - 'A';
            j++;
        }
        else if(words[j] <= 'z' && words[j] >= 'a') j++;
        else if(words[j] == ' ' || words[j] == '\n') {
            words[j] = '\0';
            j++;
            break;
        }
        else if(words[j]==EOF){
            end = 1;
            words[j] = '\0';
            break;
        }
        else ;
    }
    while(1){
        i = 0; flag = 0 ; p = &(h->word) ;
        while(p->next){
            if(words[0] <= 'z' && words[0] >= 'a') {
                if(strcmp(words , p->next->words) > 0);
                else if(strcmp(words , p->next->words) == 0){
                    p->next->times++;
                    flag = 1;
                    break;
                }
                else {
                    insert(h , i , words);
                    flag = 1;
                    break;
                }
                i++;p = p->next;
            }
            else break;
            
        }
        if(words[0] == EOF)break;
        if(!flag && words[0] <= 'z' && words[0] >= 'a')insert(h , i , words);
        if(words[j] == EOF) break;
        j = 0;
        while(1){
            words[j] = fgetc(fp1);
            if(words[j] <= 'Z' && words[j] >= 'A'){
                words[j] += 'a' - 'A';
                j++;
            }
            else if(words[j] <= 'z' && words[j] >= 'a') j++;
            else if(words[j] == EOF){
                end = 1;
                words[j++] = '\0';
                words[j] = EOF;
                break;
            }
            else {
                words[j] = '\0';
                j++;
                break;
            }
        }
    }
    p = &(h->word);
    while(p->next){
        p = p->next;
        printf("%s %d\n" , p->words , p->times);
    }
    clear_head(h);
    fclose(fp1);
}

