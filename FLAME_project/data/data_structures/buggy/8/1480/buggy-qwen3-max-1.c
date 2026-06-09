#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int gragh[40][40];
int visited[40];
int queue[40];
int rear=0,front=0;
void DFS(int i,int ding,int shan){
    int j;
    visited[i]=1;
    printf("%d ",i);
    for(j=0;j<ding;j++){
        if(j==shan){
            continue;
        }
        if(gragh[i][j]==1&&visited[j]!=1){
            DFS(j,ding,shan);
        }
    }
}
void BFS(int ding,int shan){
    int i,j;
    for(i=0;i<ding;i++){
        visited[i]=0;
    }
    visited[shan]=1;
    for(i=0;i<ding;i++){
        if(visited[i]!=1){
            visited[i]=1;
            printf("%d ",i);
            queue[rear]=i;//入队
            rear++;
            while(front!=rear){
                i=queue[front];
                front++;//首元素出队赋值给i
                for(j=0;j<ding;j++){
                    if(gragh[i][j]==1&&visited[j]!=1){
                        visited[j]=1;
                        printf("%d ",j);
                        queue[rear]=j;
                        rear++;
                    }
                }
            }
        }
    }
}
int main()
{
int ding,bian,l,r,i,j,shan;
scanf("%d %d",&ding,&bian);
for(i=0;i<bian;i++){
    scanf("%d %d",&l,&r);
    gragh[l][r]=1;
    gragh[r][l]=1;
}
scanf("%d",&shan);
DFS(0,ding,39); // @@ [The third argument should be 'shan', not 39. Passing 39 causes the DFS to skip vertex 39 (which doesn't exist) instead of the actual vertex to delete, leading to incorrect traversal before deletion.]
printf("\n");
BFS(ding,39); // @@ [Same issue: passing 39 instead of 'shan' causes BFS before deletion to incorrectly treat vertex 39 as deleted, which has no effect since n <= 100 but 39 may be beyond graph size; however, in this test case n=3, so 39 is irrelevant, but the logic is wrong. It should pass 'shan' only after deletion. More critically, BFS is implemented to loop over all unvisited components, but the problem states the graph is connected and traversal must start at 0. This BFS implementation starts a new traversal for every unvisited node, which is incorrect. However, the immediate error causing WA is using 39 instead of proper handling. But note: even if we fix 39, the BFS logic is flawed. However, the primary visible bug in this test is the use of 39.]
printf("\n");
memset(visited,0,40);
for(i=0;i<ding;i++){
    for(j=0;j<ding;j++){
        if(i==shan||j==shan){
            gragh[i][j]=0;
        }
    }
}
DFS(0,ding,shan);
printf("\n");
BFS(ding,shan);
printf("\n");
return 0;
}