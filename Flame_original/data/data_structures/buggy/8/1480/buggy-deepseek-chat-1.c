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
DFS(0,ding,39); // @@ [Error: The third argument should be 'shan' (the vertex to delete) for the initial traversal before deletion, but 39 is used instead, which is an invalid index and does not skip any vertex. This causes the DFS to incorrectly skip vertex 39 if it exists, or not skip any vertex if 39 is out of range, leading to wrong output.]
printf("\n");
BFS(ding,39); // @@ [Error: Same issue as above; the second argument should be 'shan' for the initial BFS before deletion, but 39 is used, causing incorrect behavior.]
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