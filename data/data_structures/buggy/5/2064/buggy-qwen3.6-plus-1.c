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
Node l3[500]; // @@ Array size 500 may be insufficient for the product polynomial (times1 * times2 terms), causing buffer overflow.
int cmp(const void *p1,const void *p2 );
int main(){
    int times1=0,times2=0,times3=0;
    char ch;
    do{
        scanf("%d%d%c",&l1[times1].com,&l1[times1].pow,&ch); // @@ Using %c to detect newline is fragile; it reads the immediate next character which may be a space, potentially causing incorrect loop termination or waiting for more input.
        times1++;
    }while(ch!='\n');
    do{
        scanf("%d%d%c",&l2[times2].com,&l2[times2].pow,&ch); // @@ Same fragility as above for reading the second polynomial.
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
    for(int m=0;m<times3;m++){ // @@ Loop condition m < times3 leads to out-of-bounds access l3[m+1] when m == times3 - 1. Should be m < times3 - 1.
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