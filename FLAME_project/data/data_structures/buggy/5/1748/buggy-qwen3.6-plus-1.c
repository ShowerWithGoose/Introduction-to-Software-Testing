#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node{
    int num;
    int n;
}Node;

Node node1[114514],node2[114514];
int cnt1,cnt2;
int number[2000000005]={0}; // @@ The array size 2000000005 is too large for stack allocation (approx 8GB), causing a segmentation fault or compilation/linker error due to memory limits. It should be allocated dynamically or reduced if the exponent range allows, but given "int" exponents, a map or sorted list approach is safer. However, strictly speaking, this static allocation exceeds typical memory limits.

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){ // @@ scanf returns the number of successfully read items. If it fails or reaches EOF, it returns EOF (-1) or 0. The loop condition should check if the return value is 2 to ensure both integers were read. Also, if input ends without newline properly, this might hang or behave unexpectedly.
        node1[++cnt1].num=num;
        node1[cnt1].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    while(scanf("%d%d",&num,&n)){ // @@ Same issue as above: incorrect check for scanf return value.
        node2[++cnt2].num=num;
        node2[cnt2].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    /*for(int i=1;i<=cnt2;i++){
        printf("%d %d\n",node2[i].num,node2[i].n);
    }*/

    for(int i=1;i<=cnt1;i++){
        for(int j=1;j<=cnt2;j++){
            n=node1[i].n+node2[j].n;
            num=node1[i].num*node2[j].num;
            number[n]+=num; // @@ If n is negative (though problem says non-negative exponents) or very large, this could access out of bounds. More critically, if the sum of exponents exceeds 2000000004, it crashes. Given int range, this array indexing strategy is flawed for general cases, but specifically here, the static array size is the primary compilation/runtime memory error.
           /* printf("%d\n",num);*/
        }
    }

    for(int i=node1[1].n+node2[1].n;i>=0;i--){ // @@ This assumes the first term read has the highest degree. The problem states input is $a_n x^n \dots a_0$, so the first term is indeed the highest degree. However, if cnt1 or cnt2 is 0 (empty polynomial, though problem implies non-zero terms), this accesses uninitialized memory. Also, iterating from max possible degree down to 0 is inefficient but logically okay if the array was valid. The main issue remains the array definition.
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}