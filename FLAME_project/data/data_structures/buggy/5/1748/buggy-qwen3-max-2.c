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
int number[2000000005]={0}; // @@ [Array size 2000000005 is too large for typical stack/heap limits in C, causing compilation or runtime memory allocation failure.]

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){ // @@ [scanf returns the number of successfully read items; comparing directly to true (1) may work, but more critically, if input ends without newline, this loop may not terminate correctly. However, the primary issue is the massive array above.]
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

    for(int i=node1[1].n+node2[1].n;i>=0;i--){ // @@ [Assumes node1[1] and node2[1] exist (i.e., both polynomials have at least one term), but if either input is empty (though problem says non-zero terms are given), this could access uninitialized data. However, main error remains the huge array.]
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}