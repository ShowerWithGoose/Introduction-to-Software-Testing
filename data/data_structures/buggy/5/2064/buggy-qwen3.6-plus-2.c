#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    int com;
    int pow;
};
typedef struct node Node;
Node l1[500];
Node l2[500];
Node l3[500];
int cmp(const void *p1,const void *p2 );
int main(){
    int times1=0,times2=0,times3=0;
    char ch;
    do{
        scanf("%d%d%c",&l1[times1].com,&l1[times1].pow,&ch);
        times1++;
    }while(ch!='\n');
    do{
        scanf("%d%d%c",&l2[times2].com,&l2[times2].pow,&ch);
        times2++;
    }while(ch!='\n');
    qsort(l1,times1,sizeof(Node),cmp);
    qsort(l2,times2,sizeof(Node),cmp);    
    for(int m=0;m<times1;m++){
        for(int n=0;n<times2;n++){
            l3[times3].com=l1[m].com*l2[n].com;
            l3[times3].pow=l1[m].pow+l2[n].pow;
            times3++;
        }
    }
    qsort(l3,times3,sizeof(Node),cmp);
    for(int m=0;m<times3;m++){ // @@ Array index out of bounds: when m equals times3-1, l3[m+1] accesses invalid memory. The loop condition should be m < times3 - 1.
        if(l3[m].pow==l3[m+1].pow){
            l3[m+1].com+=l3[m].com;
            l3[m].com=0;
        }
    }
    qsort(l3,times3,sizeof(Node),cmp);
    for(int m=0;m<times3;m++){
        if(l3[m].com==0){
            continue;
        }else {
            printf("%d %d ",l3[m].com,l3[m].pow);
        }
    }
    return 0;
}
int cmp(const void *p1,const void *p2 ){
    Node *a=(Node *)p1;
    Node *b=(Node *)p2;
    return -(a->pow)+(b->pow);
}