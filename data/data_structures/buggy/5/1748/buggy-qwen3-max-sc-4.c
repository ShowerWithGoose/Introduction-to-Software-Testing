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
int number[2000000005]={0}; // @@ [Array size 2000000005 is too large for stack allocation and may cause compilation or runtime memory errors; also, maximum exponent sum may not require such a huge fixed-size array]

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){ // @@ [scanf may fail (return <=0) on EOF or invalid input, causing infinite loop; also, input format expects alternating coeff and exponent pairs until newline, but this loop doesn't correctly detect end-of-line]
        node1[++cnt1].num=num;
        node1[cnt1].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    while(scanf("%d%d",&num,&n)){ // @@ [Same issue as above: incorrect input termination condition and potential infinite loop]
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

    for(int i=node1[1].n+node2[1].n;i>=0;i--){ // @@ [Assumes first terms of both polynomials have highest degree, which may not be true; should find actual max exponent instead]
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}