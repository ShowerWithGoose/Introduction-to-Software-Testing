#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Words{
    char words[30];
    int cnt;
    struct Words* next;
    struct Words* last;
};
int main(){
    FILE *in = fopen("article.txt","r");
    struct Words *head = (struct Words *)malloc(sizeof(struct Words));
    head->next = NULL;
    memset(head->words,0,sizeof(head->words));
    char c;
    c=fgetc(in);
    struct Words *now;
    do
    {
        while(!isalpha(c)&&c!=EOF) c=fgetc(in);
        struct Words *p = (struct Words *)malloc(sizeof(struct Words));
        
        int cnt = 0;
        while(isalpha(c)){
            p->words[cnt++] = tolower(c);
            c = fgetc(in);
        }
        p->words[cnt]='\0';
        now = head;
        int cmp = strcmp(now->words,p->words);
        while(cmp < 0 && now->next!=NULL) {
            now = now->next;
            cmp = strcmp(now->words,p->words);
        }
        if(now->next==NULL){
            if(cmp<0){
                now->next = p;
                p->next = NULL;
                p->cnt = 1;
                p->last = now;
            }
            else if(cmp>0){
            	p->next = now;
                p->cnt = 1;
                p->last = now->last;
                now->last = p;
                (p->last)->next = p;
			}
            else{
                now->cnt++;
                free(p);
            }
        }
        else{
            if(cmp){
                p->next = now;
                p->cnt = 1;
                p->last = now->last;
                now->last = p;
                (p->last)->next = p;
            }
            else{
                now->cnt++;
                free(p);
            }
        }
        struct Words *test;
        test = head->next;
    }
    while(c!=EOF);
    head = head->next;
    while(head!=NULL){
        printf("%s %d\n",head->words,head->cnt);
        head = head->next;
    }
    fclose(in);
    return 0;
}

