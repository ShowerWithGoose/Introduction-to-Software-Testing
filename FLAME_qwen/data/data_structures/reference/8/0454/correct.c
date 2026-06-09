#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

struct link{
    int num;
    struct link * next;
};
int ansVisited[101];
int visited[101];
struct link* dot[101];
int ans[101];int ansSize = 0;
int dotNum;

void add(int a,int b){
    struct link* p = dot[a];
    while(p->next != NULL){
        if(b > p->next->num)
        p = p->next;
        else
        break;
    }
        
    struct link* tmp = malloc(sizeof(struct link));
    tmp ->num = b;
    tmp->next = p->next;
    p->next = tmp;

}

void dfs(int pos){
    if(visited[pos])
    return;

    ans[ansSize++] = pos; 
    struct link* p = dot[pos];
    visited[pos] = 1;

    while(p->next != NULL){
        if(!visited[p->next->num])
        dfs(p->next->num);

        p = p->next;
    }

}

void bfs(int pos){

    int node[101];
    int front = 0,rear = 0;
    node[rear++] = pos;
    ans[ansSize++] = pos;visited[pos] = 1;
    while(front < rear){
        struct link* p = dot[node[front++]];
        struct link* q = p;
        while(q->next != NULL){
            if(!visited[q->next->num]){
                node[rear++] = q->next->num;
                ans[ansSize++] = q->next->num;
                visited[q->next->num] = 1;
            }
            q = q->next;
        }
    }
    


}

void ansPrint(){
    for(int i=0;i<ansSize;i++)
        printf("%d ",ans[i]);
    printf("\n");

}

int main(){
    int edgeNum;

    scanf("%d%d",&dotNum,&edgeNum);

    for(int i=0;i<dotNum;i++){//初始化
        struct link * tmp = malloc(sizeof(struct link));
        tmp->next = NULL;
        tmp->num = i;
        dot[i] = tmp; 
    }

    for(int i=0;i<edgeNum;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    // 绘图完成

    int deDot;
    scanf("%d",&deDot);
    
    dfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(ans,0,sizeof(ans));
    ansSize = 0;

    
    bfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(ans,0,sizeof(ans));
    memset(ansVisited,0,sizeof(ansVisited));
    ansSize = 0;

    for(int i=0;i<dotNum;i++){
        struct link * p = dot[i];
        while(p->next != NULL){
            if(p->next->num == deDot)
                p->next = p->next->next;
            else
                p = p->next;
        }
    }

    dfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(ans,0,sizeof(ans));
    ansSize = 0;

    
    bfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(ans,0,sizeof(ans));
    memset(ansVisited,0,sizeof(ansVisited));
    ansSize = 0;

    return 0;
}
