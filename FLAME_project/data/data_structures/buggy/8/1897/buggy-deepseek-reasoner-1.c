#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<string.h>
int matrix[200][200];
int visited[200];
void creatmatrix(int matrix[][200],int Vnum,int Enum){
    int i,j,k,weight;
    for(i=0;i<Vnum;i++){
        for(j=0;j<Vnum;j++){
            matrix[i][j]=0;
        }
    }
    for(int k=0;k<Enum;k++){
        scanf("%d%d",&i,&j);
        matrix[i][j]=1;
        matrix[j][i]=1;
    }

}
void dfs(int v,int Vnum){
    printf("%d ",v);
    visited[v]=1;
    for(int w=0;w<Vnum;w++){
        if((matrix[v][w]!=0)&&(!visited[w])) dfs(w,Vnum);
    }
}
void bfs(int v,int vnum)
{
    int que[200];
    int i,head=0,tail=1,tmp;    //队头，队尾，出列的元素 
    que[head]=v;    //入队 
    while(head<=tail)    //队列访问完毕 @@ while条件错误：当head==tail时队列为空不应再处理，应改为head<tail，否则会访问未初始化的队列元素导致数组越界或打印垃圾值
    {
        tmp=que[head];    //出队 
        head++;            //出队
        if(visited[tmp])    continue;    //如果访问过 
        else
        {
            printf("%d ",tmp);        //打印出队元素 
            visited[tmp]=1;            //已访问 
            for(i=0;i<vnum;i++)
                if (matrix[tmp][i]==1&& !visited[i])    //如果矩阵元素为 1 且未访问过 
                    que[tail++]=i;        //入队 
        }
    }
}

int main(){
    int Vnum,Enum;
    scanf("%d%d",&Vnum,&Enum);
    creatmatrix(matrix,Vnum,Enum);
    int del;
    scanf("%d",&del);
    dfs(0,Vnum);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0,Vnum);
    printf("\n");
    for(int i=0;i<Vnum;i++){
        for(int j=0;j<Vnum;j++){
            if((i==del)||(j==del)) matrix[i][j]=0;
        }
    }
    memset(visited,0,sizeof(visited));
    dfs(0,Vnum);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0,Vnum);
    printf("\n");
    return 0;
}