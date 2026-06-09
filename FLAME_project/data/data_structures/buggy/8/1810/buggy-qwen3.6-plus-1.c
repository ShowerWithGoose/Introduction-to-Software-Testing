#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxV 100
int G[MaxV][MaxV];
int visit[MaxV], queue[MaxV];
int dot, side;
void dfs(int x);
void bfs(int x);
void delete_ay(int x);
void circulate();
int main()
{
    scanf("%d%d", &dot, &side);
    int u, v;
    while(side--){
        scanf("%d %d", &u, &v);
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int ay;
    scanf("%d", &ay);
    circulate();
    
    delete_ay(ay);
    
    circulate();
    return 0;
}
void dfs(int item)
{
    printf("%d ", item); // @@ The output format requires no trailing space at the end of the line, but this prints a space after every vertex including the last one. While the provided "Buggy Output" shows trailing spaces, strict judging systems often reject trailing whitespace. However, looking at the Expected Output vs Buggy Output in the prompt, they look identical visually except for potential hidden characters or newlines. Let's look closer. The problem says "separated by spaces". Usually, this implies `val val val\n`. The reference program prints `val ` (with space). The buggy output shows `0 1 2 `. The expected output shows `0 1 2`. If the judge is strict, the trailing space is an error. But wait, the reference program ALSO prints a trailing space (`printf("%d ",v)`). So if the reference is correct, the trailing space is acceptable. Let's look for other errors.
    visit[item] = 1;
    for(int i = 0; i < dot; i++){
        if(G[item][i] == 1 && visit[i] == 0){
            dfs(i);
        }
    }
    return;
}
void bfs(int item)
{
    int head = 0, tail = 1, tmp;
    queue[head] = item;
    while(head <= tail){ // @@ The condition `head <= tail` is incorrect for a standard queue implementation where `tail` points to the next empty slot. When `head == tail`, the queue is empty. Using `<=` causes the loop to process one extra element when the queue is effectively empty, or access uninitialized memory if `tail` was incremented beyond valid elements without checking. Specifically, if the queue becomes empty, `head` will equal `tail`. The loop continues, `tmp = queue[head]` accesses potentially invalid data, and `head++` increments past `tail`. It should be `head < tail`.
        tmp = queue[head];
        head++;
        if(visit[tmp] == 1)
            continue;
        else if(visit[tmp] == 0){
            printf("%d ", tmp);
            visit[tmp] = 1;
            for(int i = 0; i < dot; i++)
                if(G[tmp][i] == 1 && visit[i] == 0)
                    queue[tail++] = i;
        }
    }
}
void circulate()
{
    dfs(0);
    printf("\n");
    memset(visit, 0, sizeof(int)*MaxV);
    
    bfs(0);
    printf("\n");
    memset(visit, 0, sizeof(int)*MaxV);
}
void delete_ay(int ay)
{
    
    for(int i = 0; i < dot; i++){
            G[ay][i] = 0;
            G[i][ay] = 0;
    }
}