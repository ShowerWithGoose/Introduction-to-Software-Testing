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
int number[2000000005]={0}; // @@ [Error: Array size is too large (2,000,000,005), causing stack overflow or compilation failure. The maximum exponent sum could be up to 2*INT_MAX, but such a large array is not feasible. Use a dynamic structure or smaller array based on input constraints.]

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){
        node1[++cnt1].num=num;
        node1[cnt1].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    while(scanf("%d%d",&num,&n)){
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
            number[n]+=num;
           /* printf("%d\n",num);*/
        }
    }

    for(int i=node1[1].n+node2[1].n;i>=0;i--){ // @@ [Error: Assumes the maximum exponent is from the first terms only, but the maximum exponent could be from any pair. Should compute the actual maximum exponent sum from all terms.]
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}