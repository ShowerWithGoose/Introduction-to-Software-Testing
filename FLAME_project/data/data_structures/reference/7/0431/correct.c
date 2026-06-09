#include<stdio.h>
#include<stdlib.h>
struct tree{
	int num;
	struct tree *llind, *rlind;
}*treeptr;
struct tree *insert(struct tree *p, int w){
    if(p == NULL){
        p = (struct tree *)malloc(sizeof(struct tree));
        p->num = w;
        p->llind = p->rlind = NULL;
    }else{
        if(w < p->num){
            p->llind = insert(p->llind, w);
        }else{
            p->rlind = insert(p->rlind, w);
        }
    }
    return p;
}
void find(struct tree *p, int high){
	if(p == NULL){
		return;
	} 
    if(p->rlind == NULL && p->llind == NULL){
        printf("%d %d\n", p->num, high);
    }else{
        find(p->llind, high + 1);
        find(p->rlind, high + 1);
    }
}
int main(){
	int n, i, temp;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &temp);
        treeptr = insert(treeptr, temp);
    }
    find(treeptr, 1);
    return 0;
}

