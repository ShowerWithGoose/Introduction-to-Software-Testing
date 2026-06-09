#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int gragh[40][40]; // @@ Array size 40 is insufficient as n can be up to 100, causing out-of-bounds access.
int visited[40]; // @@ Array size 40 is insufficient as n can be up to 100.
int queue[40]; // @@ Array size 40 is insufficient as n can be up to 100.
int rear=0,front=0; // @@ Global queue pointers are not reset between BFS calls, leading to incorrect traversal on subsequent calls.
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
    visited[shan]=1; // @@ Accessing visited[shan] when shan=39 may be out-of-bounds or incorrectly mark a vertex. Queue pointers should also be reset here.
    for(i=0;i<ding;i++){
        if(visited[i]!=1){
            visited[i]=1;
            printf("%d ",i);
            queue[rear]=i;//入队
            rear++;
            while(front!=rear){
                i=queue[front]; // @@ Modifying the outer loop variable i here disrupts the BFS logic and traversal order. Should use a separate local variable.
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
DFS(0,ding,39); // @@ Passing 39 as the deleted vertex is incorrect; it may skip a valid vertex if n > 40. Should pass -1 or ding.
printf("\n");
BFS(ding,39); // @@ Same issue as above; passing 39 is incorrect for the pre-deletion traversal.
printf("\n");
memset(visited,0,40); // @@ memset size should be sizeof(visited) or 40*sizeof(int), otherwise only the first 10 elements are cleared.
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