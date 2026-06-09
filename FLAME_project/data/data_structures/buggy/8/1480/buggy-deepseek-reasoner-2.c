#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int gragh[40][40]; // @@ [Error: Array size 40 is insufficient; the problem allows up to 100 vertices, causing out-of-bounds access]
int visited[40]; // @@ [Error: Array size 40 is insufficient for n up to 100]
int queue[40]; // @@ [Error: Array size 40 is insufficient for up to 100 vertices]
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
    visited[shan]=1; // @@ [Error: Before deletion, shan is 39 (a possibly valid vertex), making BFS skip vertex 39 incorrectly; should use a sentinel like -1]
    for(i=0;i<ding;i++){
        if(visited[i]!=1){
            visited[i]=1;
            printf("%d ",i);
            queue[rear]=i;//入队
            rear++;
            while(front!=rear){
                i=queue[front]; // @@ [Error: Overwrites the loop variable i, causing the outer for loop to behave incorrectly]
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
DFS(0,ding,39); // @@ [Error: 39 is not a valid sentinel; should be a value outside vertex range (e.g., -1) to indicate no deletion]
printf("\n");
BFS(ding,39); // @@ [Error: Same sentinel issue; also BFS implementation is logically flawed]
printf("\n");
memset(visited,0,40); // @@ [Error: Should reset visited for DFS after deletion as well; also uses hardcoded 40 instead of ding]
for(i=0;i<ding;i++){
    for(j=0;j<ding;j++){
        if(i==shan||j==shan){
            gragh[i][j]=0;
        }
    }
}
DFS(0,ding,shan);
printf("\n");
BFS(ding,shan); // @@ [Error: BFS function still contains the same logical flaws (overwriting i, incorrect handling of visited[shan])]
printf("\n");
return 0;
}