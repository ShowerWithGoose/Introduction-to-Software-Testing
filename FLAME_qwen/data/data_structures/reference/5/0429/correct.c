#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct number *f;
struct number{
    int a;
    int n;
    struct number *next;
};
int find(struct number*, int a, int n, int op);
int find(struct number* fc, int a, int n, int op)
{
    struct number *p;
    p = fc;
    if(op == 0){
        f->n = n;
        f->a = a;
        f->next = NULL;
        return 0;
    }
    while(fc->next != NULL){
        if(fc->n == n){
            fc->a += a;
            return 0;
        }fc = fc->next;
    }
    if(fc->n == n){
        fc->a += a;
        return 0;
    }
    p = (struct number*)malloc(sizeof(struct number));
    fc->next = p;
    p->n = n;
    p->a = a;
    p->next = NULL;
    return 0;
}
int main()
{
    char line[1000];
    struct number *fa = NULL, *fb = NULL, *fc = NULL, *p, *q;
    int a[1000] = {0}, b[1000] = {0}, da, dn, link = 0, op;
    int i, j = 0, k, len, lena, lenb;
    gets(line);
    len = strlen(line);
    f = (struct number*)malloc(sizeof(struct number));
    for(i = 0; i < len; i++){
        while(line[i] < '0' || line[i] > '9' && i < len)i++;
        do{
            a[j] = a[j] * 10 + line[i] - '0';
            i++;
        }while(line[i] >= '0' && line[i] <= '9');
        j++;
    }lena = j;
    j = 0;
    gets(line);
    len = strlen(line);
    for(i = 0; i < len; i++){
        while(line[i] < '0' || line[i] > '9' && i < len)i++;
        do{
            b[j] = b[j] * 10 + line[i] - '0';
            i++;
        }while(line[i] >= '0' && line[i] <= '9');
        j++;
    }lenb = j;
    for(i = 0; i < lena / 2; i++){
        q = (struct number*)malloc(sizeof(struct number));
        q->a = a[2 * i];
        q->n = a[2 * i + 1];;
        q->next = NULL;
        if(fa == NULL){
            fa = p = q;
        }
        else{
            p->next = q;
            p = p->next;
        }
    }
    for(i = 0; i < lenb / 2; i++){
        q = (struct number*)malloc(sizeof(struct number));
        q->a = b[2 * i];
        q->n = b[2 * i + 1];;
        q->next = NULL;
        if(fb == NULL){
            fb = p = q;
        }
        else{
            p->next = q;
            p = p->next;
        }
    }
    for(p = fa; p != NULL; p = p->next){
        for(q = fb; q != NULL; q = q->next){
            da = p->a * q->a;
            dn = p->n + q->n;
            if(q == fb && p == fa)find(f, da, dn, 0);
            else find(f, da, dn, 1);
        }
    }
    p = f;
    while(p != NULL){
        p = p->next;
        link++;
    }
    p = f;
    puts("");
    for(i = 0; i < link; i++){
        for(p = f, j = 0; j < link - 1; j++, p = p->next){
            if(p->n < p->next->n){
                op = p->a;
                p->a = p->next->a;
                p->next->a = op;
                op = p->next->n;
                p->next->n = p->n;
                p->n = op;
            }
        }
    }
    while(f != NULL){
        printf("%d %d ", f->a, f->n);
        f = f->next;
    }
    return 0;
}


