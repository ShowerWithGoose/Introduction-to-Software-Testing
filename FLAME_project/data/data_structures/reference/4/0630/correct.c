#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int get_ch(char mem[]);
void bld_tab();
void cmp_tab();

struct five{
    char ch[50];
    int ti;
    struct five *next;
} *fst = NULL, *p, *q, *s, *zero = NULL;
char mem[150] = {'\0'};
int times = 0;
FILE *in;

int main(){
    in = fopen("article.txt", "r");
    while(get_ch(mem) == 1) {
        bld_tab();

    }
    fst = zero->next;
    s = fst;
    while(s != NULL){
        printf("%s %d\n", s->ch, s->ti);
        s = s->next;
    }
    return 0;
}

int get_ch(char mem[]) {
    int i = 0;
    char ch = '\0';
    for(i = 0; /*(mem[i] = fgetc(in)) != EOF && ((mem[i] >= 'a' && mem[i] <= 'z') || (mem[i] >= 'A' && mem[i] <= 'Z'))*/! isalpha(ch = fgetc(in)); i ++){
        if (ch == EOF)
            return ch;
    }
    mem[0] = ch;
    i = 0;
    do {
        mem[i] = tolower(mem[i]);
        i ++;
    } while(isalpha(mem[i] = fgetc(in)));
    mem[i] = '\0';
    return 1;
}

void bld_tab() {
    times ++;
    if(fst == NULL){
        q = malloc(sizeof(struct five));
        memset(q->ch, '\0', sizeof(q->ch));
        zero = malloc(sizeof(struct five));
        strcpy(q->ch, mem);
        q->ti = 1;
        q->next = NULL;
        fst = q;
        zero->next = fst;
    } else{
        cmp_tab();//完成插入和连接，直到结束。
    }
    return;
}

void cmp_tab() {
    s = zero;
    while(s->next != NULL && strcmp(s->next->ch, mem) < 0) {
        s = s->next;
    }
    if(s->next == NULL) {
        q = malloc(sizeof(struct five));
        memset(q->ch, '\0', sizeof(q->ch));
        strcpy(q->ch, mem);
        if(times == 2){
            fst->next = q;
        }
        q->next = NULL;
        q->ti = 1;
        s->next = q;
    } else {
        int cp = strcmp(s->next->ch, mem);
        if(cp == 0) {
            s->next->ti ++;
        } else {
            q = malloc(sizeof(struct five));
            memset(q->ch, '\0', sizeof(q->ch));
            strcpy(q->ch, mem);
            if(times == 2){
                fst->next = q;
            }
            q->ti = 1;
            q->next = s->next;
            s->next = q;
        }
    }
    return;
}

