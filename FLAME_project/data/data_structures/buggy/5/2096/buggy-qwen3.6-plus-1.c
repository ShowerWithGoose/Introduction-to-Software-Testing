#include<stdio.h>
#include<stdlib.h>
#define MAX 1000005
typedef struct node{
    int x;
    int m;
}node;
node a[MAX];
node b[MAX];
node c[MAX];
int pass[MAX];
int multi(int,int);
void guina(int);
int multi(int la,int lb){
    int i,j,k=0;
    for(i=0;i<la;i++){
        for(j=0;j<lb;j++){
            c[k].x=a[i].x*b[j].x;
            c[k].m=a[i].m+b[j].m;
            k++;
        }
    }
    return k;
}
int cmp(const void* a,const void* b){
    node* x=(node*) a;
    node* y=(node*) b;
    return y->m-x->m;
}
void guina(int k){
    int i,j;
    for(i=0;i<k;i++){
        if(pass[i]) continue;
        for(j=i+1;j<k;j++){
            if(c[i].m==c[j].m){
                c[i].x+=c[j].x;
                pass[j]=1;
            }
        }
    }
    for(i=0;i<k;i++){
        if(!pass[i]&&c[i].x==0){
            pass[i]=1;
        }
    }
}
int main(){
    int i;
    char t;
    for(i=0;;){
        scanf("%d%d",&a[i].x,&a[i].m);
        scanf("%1c",&t);
        i++;
        if(t=='\n') break;
    }
    int la=i;
    i=0;
    while(scanf("%d",&b[i].x)!=EOF){
        scanf("%d",&b[i].m);
        i++;
    }
    int lb=i;
    int k;
    k=multi(la,lb);
    guina(k);
    qsort(c,k,sizeof(node),cmp); // @@ The sorting is performed after merging coefficients, but the `pass` array marks indices based on the pre-sorted order. Sorting changes the positions of elements, so the `pass` flags no longer correspond to the correct elements in the sorted array. The `qsort` should be called before `guina`, or the output logic should not rely on `pass` indices after sorting.
    for(i=0;i<k;i++){
        if(!pass[i]){ // @@ Because the array `c` was sorted after `guina` marked indices in `pass`, `pass[i]` now refers to the wrong term. Additionally, terms that were merged into another term (marked as passed) might have moved to index `i`, causing valid terms to be skipped or zeroed-out terms to be printed if they moved to an unpassed index.
            printf("%d %d ",c[i].x,c[i].m);
        }
    }
    return 0;
}