#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 100

bool graph[MAX][MAX], visited[MAX];
int point1, point2, point_num, side_num, i, j, k, del, num, Num, bfsv[MAX], bfse[MAX], bfsh[MAX];

void dfs(int root);
void bfs(int root);
void initvisit();
bool is_over();

int main(){
    scanf("%d %d",&point_num, &side_num);
    while(side_num--){
        scanf("%d %d",&point1, &point2);
        graph[point1][point2] = graph[point2][point1] = 1;
    }
//    for(i = 0; i < point_num; i++){
//    	for(j = 0; j < point_num; j++){
//    		
//		}
//	}
    dfs(0);
    printf("\n");
    initvisit();
    bfs(0);
    num = 0;
    for (k = 0; k < j; k++){
        bfse[num] = bfsv[k];
        num++;
    }
    while (!is_over()){
        Num = num;
        num = 0;
        for (i = 0; i < Num; i++){
            bfs(bfse[i]);
            for (k = 0; k < j; k++){
                bfsh[num] = bfsv[k];
                num++;
            }
        }
        for (k = 0; k < num; k++)
            bfse[k] = bfsh[k];
    }
    printf("\n");
    initvisit();
    scanf("%d",&del);
    
    for(i = 0; i < point_num; i++)
        graph[del][i] = graph[i][del] = 0;
    dfs(0);
    printf("\n");
    initvisit();
    visited[del] = 1;
    bfs(0);
    num = 0;
    for (k = 0; k < j; k++){
        bfse[num] = bfsv[k];
        num++;
    }
    while (!is_over()){
        Num = num;
        num = 0;
        for (i = 0; i < Num; i++){
            bfs(bfse[i]);
            for (k = 0; k < j; k++){
                bfsh[num] = bfsv[k];
                num++;
            }
        }
        for (k = 0; k < num; k++)
            bfse[k] = bfsh[k];
    }
    printf("\n");
	return 0;
}

bool is_over(){
    for(i = 0; i < point_num; i++)
        if(visited[i] == 0)
            return false;
    return true;
}

void initvisit(){
    int i;
    for(i = 0; i < point_num; i++)
        visited[i] = 0;
    return ;
}

void dfs(int root){
    if(visited[root] == 1)
        return ;
    int i;
    num = 0;
    printf("%d ", root);
    visited[root] = 1;
    for(i = 0; i < point_num; i++)
        if(graph[root][i] == 1 && visited[i] == 0){
            dfs(i);
		}
    return ;
}

void bfs(int root){
    int i;
    j = 0;
    if(visited[root] == 1)
        return ;
    printf("%d ", root);
    visited[root] = 1;
    for(i = 0; i < point_num; i++){
        if(graph[root][i] == 1 && visited[i] == 0){
//        	printf("%dsb%d ",I,j);
            bfsv[j] = i;
            j++;
        }
    }
    return ;
}

