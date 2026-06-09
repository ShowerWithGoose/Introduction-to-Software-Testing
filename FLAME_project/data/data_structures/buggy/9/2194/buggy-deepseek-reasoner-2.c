#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int flag[15]; // @@ Array size too small; for n=16 it causes out-of-bounds access. Should be dynamic or large enough.
int num=0,max=0,ans=0;
typedef struct {
    int x1,y1,x2,y2;
} Site;
Site line[15]; // @@ Array size too small; with n=16 this is insufficient. Should be allocated after reading n.
typedef struct NODE{
    int X1,Y1,X2,Y2;
    struct NODE *next;
} Node,*Npp;
Node *createNode(int m,int n){
    Node *tmp=(Node*) malloc(sizeof (Node));
    tmp->X1=m;
    tmp->Y1=n;
    tmp->next=NULL;
    return tmp;
}
int cmp(const void *a, const void *b) {
    Site x = *(Site *) a;
    Site y = *(Site *) b;
    if(x.x1>y.x1) return 1;
    return -1; // @@ Missing return 0 when x.x1 == y.x1, violating qsort's requirement for a total order. Causes undefined behavior.
}
void creatlist(int x,int n){
    int i=x,j=x+1;
    num=0;
    while(j<n){
        if(line[i].x2==line[j].x1 && line[i].y2==line[j].y1){
            flag[j]=1; // @@ Potential out-of-bounds write if j >= 15 (here n=16, j max 15). Leads to memory corruption.
            i=j;
            num++;
        }
        j++;
    }
    if(num>max){
        max=num;
        ans=x;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i =0;i<n;i++){
        scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    }
    qsort(line,n,sizeof(line[0]),cmp);
    int k=0;
    while(k<n){
        if(flag[k]==0) // @@ Out-of-bounds read when k >= 15 (since flag size is 15). Corrupts memory and leads to incorrect logic.
            creatlist(k,n);
        k++;
        }
    printf("%d %d %d",max+1,line[ans].x1,line[ans].y1);
    return 0;
}