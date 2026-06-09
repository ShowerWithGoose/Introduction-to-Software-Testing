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
int number[2000000005]={0}; // @@ The array size is too large (2,000,000,005 integers), causing stack overflow or memory allocation failure. The maximum exponent sum could be up to 2*INT_MAX, but this array is impractical and likely exceeds memory limits.

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){
        node1[++cnt1].num=num; // @@ Pre-increment (++cnt1) starts indexing from 1, but cnt1 is uninitialized (default 0), so first element is stored at index 1, leaving index 0 unused. This is inconsistent with later loops that start from i=1.
        node1[cnt1].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    while(scanf("%d%d",&num,&n)){
        node2[++cnt2].num=num; // @@ Same issue as above: pre-increment starts from index 1, leaving index 0 unused.
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
            number[n]+=num;
           /* printf("%d\n",num);*/
        }
    }

    for(int i=node1[1].n+node2[1].n;i>=0;i--){ // @@ Assumes the maximum exponent is the sum of the first terms' exponents, but the first terms may not have the highest exponents (input order is descending, but the first term is the highest degree). This is correct only if input is strictly descending, but the problem guarantees descending order, so this is acceptable. However, the loop may iterate over many unused indices if the array is large.
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}