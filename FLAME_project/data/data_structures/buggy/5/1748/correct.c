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
Node node[10000005];
int cnt;

int cmp(const void*p1,const void* p2){
    Node *a=(Node *)p1;
    Node *b=(Node *)p2;
    return a->n<=b->n?1:-1;
}

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
            node[++cnt].n=n;
            node[cnt].num=num;
           /* printf("%d\n",num);*/
        }
    }

    qsort(&node[1],cnt,sizeof(Node),cmp);

    for(int i=1;i<=cnt;i++){
        if(node[i+1].n==node[i].n&&i+1<=cnt){
            node[i+1].num+=node[i].num;
        }
        else if(node[i].num) printf("%d %d ",node[i].num,node[i].n);
    }


    return 0;
}

