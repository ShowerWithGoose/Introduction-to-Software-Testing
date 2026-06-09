#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int gragh[40][40]; // @@ Array size too small (max n=100, but only 40)
int visited[40]; // @@ Array size too small
int queue[40]; // @@ Queue size too small (n up to 100)
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
    visited[shan]=1; // @@ Marks a valid vertex (39) as visited before deletion, causing it to be skipped incorrectly
    for(i=0;i<ding;i++){
        if(visited[i]!=1){
            visited[i]=1;
            printf("%d ",i);
            queue[rear]=i;//入队
            rear++;
            while(front!=rear){
                i=queue[front]; // @@ Modifies outer loop variable i, disrupting traversal order
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
DFS(0,ding,39); // @@ Should use a sentinel like ding or -1; 39 may be a valid vertex, causing incorrect skip
printf("\n");
BFS(ding,39); // @@ Same issue; also BFS implementation logic is flawed
printf("\n");
memset(visited,0,40); // @@ Only clears 40 bytes, not the whole visited array (should be 40*sizeof(int))
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