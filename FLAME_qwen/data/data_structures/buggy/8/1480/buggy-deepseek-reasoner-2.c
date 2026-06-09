#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int gragh[40][40]; @@ // array size too small for maximum n=100
int visited[40]; @@ // array size too small for maximum n=100
int queue[40]; @@ // array size too small for maximum n=100
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
    for(i=0;i<ding;i++){ @@ // outer loop is unnecessary and will be disrupted by modification of i inside while
        if(visited[i]!=1){
            visited[i]=1;
            printf("%d ",i);
            queue[rear]=i; @@ // queue pointers (rear, front) are not reset for each BFS call, leading to incorrect queue state
            rear++;
            while(front!=rear){
                i=queue[front]; @@ // reassigning loop variable i interferes with the outer for loop
                front++;
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
DFS(0,ding,39); @@ // before deletion, should not skip any vertex; passing 39 (a possible vertex) incorrectly skips vertex 39
printf("\n");
BFS(ding,39); @@ // before deletion, should not skip any vertex; passing 39 incorrectly marks vertex 39 as visited and skips it
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