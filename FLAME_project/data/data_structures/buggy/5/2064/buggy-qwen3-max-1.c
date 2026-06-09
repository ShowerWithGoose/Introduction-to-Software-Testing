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
Node l3[500]; // @@ [The size of l3 is too small. Multiplying two polynomials with up to 500 terms each can produce up to 250,000 terms before combining like terms, but l3 only has space for 500 terms, causing buffer overflow and incorrect results.]
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
    for(int m=0;m<times3;m++){ // @@ [This loop only merges consecutive duplicate exponents once and assumes they are adjacent after sorting, but it fails to handle cases where multiple terms have the same exponent beyond immediate neighbors. Also, it accesses l3[m+1] when m == times3-1, leading to out-of-bounds access.]
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
    return -(a->pow)+(b->pow); // @@ [This comparison function returns b->pow - a->pow, which sorts in descending order, but the logic is error-prone and may cause integer overflow. More importantly, the merging logic later assumes ascending or descending order consistently, but the combination approach is flawed regardless. However, the primary issue is the inadequate merging of like terms and array bounds.]
}