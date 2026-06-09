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
int visited2[101];
int visited[101];
struct link* dot[101];
int quee[101];int rear = 0;
int node;

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

    quee[rear++] = pos; 
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
    quee[rear++] = pos;visited[pos] = 1;
    while(front < rear){
        struct link* p = dot[node[front++]];
        struct link* q = p;
        while(q->next != NULL){
            if(!visited[q->next->num]){
                node[rear++] = q->next->num;
                quee[rear++] = q->next->num;
                visited[q->next->num] = 1;
            }
            q = q->next;
        }
    }
    


}

void ansPrint(){
    for(int i=0;i<rear;i++)
        printf("%d ",quee[i]);
    printf("\n");

}

int main(){
    int line;

    scanf("%d%d",&node,&line);

    for(int i=0;i<node;i++){//初始化
        struct link * tmp = malloc(sizeof(struct link));
        tmp->next = NULL;
        tmp->num = i;
        dot[i] = tmp; 
    }

    for(int i=0;i<line;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    // 绘图完成

    int quit;
    scanf("%d",&quit);
    
    dfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(quee,0,sizeof(quee));
    rear = 0;

    
    bfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(quee,0,sizeof(quee));
    memset(visited2,0,sizeof(visited2));
    rear = 0;

    for(int i=0;i<node;i++){
        struct link * p = dot[i];
        while(p->next != NULL){
            if(p->next->num == quit)
                p->next = p->next->next;
            else
                p = p->next;
        }
    }

    dfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(quee,0,sizeof(quee));
    rear = 0;

    
    bfs(0);
    ansPrint();
    memset(visited,0,sizeof(visited));
    memset(quee,0,sizeof(quee));
    memset(visited2,0,sizeof(visited2));
    rear = 0;

    return 0;
}
