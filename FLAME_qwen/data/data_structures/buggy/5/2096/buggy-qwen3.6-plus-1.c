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
int cmp(const void* a,const void* b){ // @@ Parameter names 'a' and 'b' shadow global arrays 'a' and 'b', which causes compilation errors in strict environments or when -Werror=shadow is enabled.
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
        scanf("%1c",&t); // @@ '%1c' reads exactly one character including spaces, which may incorrectly consume delimiters between terms instead of just the newline, leading to parsing issues.
        i++;
        if(t=='\n') break;
    }
    int la=i;
    i=0;
    while(scanf("%d",&b[i].x)!=EOF){ // @@ 'scanf' returns the number of successfully matched items; comparing to 'EOF' is incorrect for loop termination. It should be '== 1' to properly detect end of input.
        scanf("%d",&b[i].m);
        i++;
    }
    int lb=i;
    int k;
    k=multi(la,lb);
    guina(k);
    qsort(c,k,sizeof(node),cmp); // @@ Sorting array 'c' does not rearrange the 'pass' array accordingly, causing 'pass' indices to mismatch with 'c' elements after sorting and resulting in incorrect output.
    for(i=0;i<k;i++){
        if(!pass[i]){
            printf("%d %d ",c[i].x,c[i].m);
        }
    }
    return 0;
}