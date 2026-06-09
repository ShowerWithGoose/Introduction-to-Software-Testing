#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 1000

typedef struct DXS{
    int val;
    int inde;
    struct DXS* next;
}dxs;

dxs in1[M], in2[M], *ans;

dxs* search(int key){
    dxs *p = ans, *fron = NULL;
    while(p!=NULL&&((p->inde)>key)){
        fron = p;
        p = p->next;
    }
    return fron?fron:ans;
}

void insert(dxs* elem){
    dxs* r = search(elem->inde);
    if(r == NULL){
        ans = (dxs*) malloc (sizeof (dxs));
        ans = elem;
    }
    else if(r->next == NULL){
        r->next = elem;
        elem->next = NULL;
    }
    else if(r->next->inde != elem->inde){
        dxs* tmp = r->next;
        r->next = elem;
        elem->next = tmp;
    }
    else {
        r->next->val += elem->val;
    }
}

int main(){
    int size1 = 0, size2 = 0;
    char s;
    do{
        scanf("%d %d", &in1[size1].val, &in1[size1].inde);
        size1++;
        s = getchar();
    }while(s!='\n');
    do{
        scanf("%d %d", &in2[size2].val, &in2[size2].inde);
        size2++;
        s = getchar();
    }while(s!='\n');

    for(int i = 0; i<size1; i++){
        for(int j = 0; j<size2; j++){
            dxs* new = (dxs*) malloc (sizeof (dxs));
            new->inde = in1[i].inde + in2[j].inde;
            new->val = in1[i].val * in2[j].val;
            new->next = NULL;
            insert(new);
        }
    }

    dxs* res = ans;
    while(res){
        printf("%d %d ", res->val, res->inde);
        res = res->next;
    }

    free(ans);

    return 0;
}
