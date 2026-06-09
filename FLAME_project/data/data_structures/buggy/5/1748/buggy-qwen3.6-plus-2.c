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
int number[2000000005]={0}; // @@ [Memory Limit Exceeded / Stack Overflow: The array size 2000000005 * 4 bytes is approx 8GB, which exceeds typical memory limits for competitive programming or standard execution environments. Additionally, global arrays of this size may cause linking issues or runtime crashes depending on the system.]

int main(){
    int num,n;
    char type;
    while(scanf("%d%d",&num,&n)){ // @@ [Logical Error: scanf returns the number of successfully read items. If it fails (EOF), it returns EOF (-1), which is truthy in C, causing an infinite loop or undefined behavior. It should check if return value == 2.]
        node1[++cnt1].num=num;
        node1[cnt1].n=n;
        scanf("%c",&type);
        if(type=='\n') break;
    }

    while(scanf("%d%d",&num,&n)){ // @@ [Logical Error: Same as above, incorrect loop termination condition for scanf.]
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

    for(int i=node1[1].n+node2[1].n;i>=0;i--){
        if(number[i]) printf("%d %d ",number[i],i);
    }


    return 0;
}