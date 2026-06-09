#include <stdio.h>
#include <stdlib.h>
void TRAVEL_DFS(int a[],int n); // @@ 参数类型错误：应接受二维数组，但声明为一维数组
void DFS(int a[],int n,int v); // @@ 参数类型错误：应接受二维数组，但声明为一维数组
void TRAVEL_BFS(int a[],int n); // @@ 参数类型错误：应接受二维数组，但声明为一维数组
void BFS(int a[],int n,int v); // @@ 参数类型错误：应接受二维数组，但声明为一维数组
int QUE[100]= {};
int front=-1;
int rear=-1;
int visited[100]= {};
int main()
{
    int v_num;
    int e_num;
    scanf("%d%d",&v_num,&e_num);
    int i,j,k;
    int edge[v_num][v_num];
    for(i=0; i<v_num; i++)
    {
        for(j=0; j<v_num; j++)
        {
            edge[i][j]=0;
        }
    }
    for(i=0; i<e_num; i++)
    {
        scanf("%d %d",&j,&k);
        edge[j][k]=1;
        edge[k][j]=1;
    }
    for(i=0; i<e_num; i++) // @@ 循环上限错误：应为 v_num 而非 e_num，可能导致部分顶点未被初始化
    {
        visited[i]=0;
    }
    TRAVEL_DFS(edge,v_num); // @@ 传递二维数组给期望一维数组的函数，类型不匹配
    printf("\n");
    for(i=0; i<e_num; i++) // @@ 循环上限错误：应为 v_num 而非 e_num
    {
        visited[i]=0;
    }
    TRAVEL_BFS(edge,v_num); // @@ 传递二维数组给期望一维数组的函数，类型不匹配
    scanf("%d",&k);
    for(i=0;i<v_num;i++)
    {
        edge[k][i]=0;
        edge[i][k]=0;
    }
    for(i=0; i<e_num; i++) // @@ 循环上限错误：应为 v_num 而非 e_num
    {
        visited[i]=0;
    }
    visited[k]=1;
    TRAVEL_DFS(edge,v_num); // @@ 传递二维数组给期望一维数组的函数，类型不匹配
    printf("\n");
    for(i=0; i<e_num; i++) // @@ 循环上限错误：应为 v_num 而非 e_num
    {
        visited[i]=0;
    }
    visited[k]=1;
    TRAVEL_BFS(edge,v_num); // @@ 传递二维数组给期望一维数组的函数，类型不匹配
    return 0;
}
void TRAVEL_DFS(int a[],int n) // @@ 函数定义参数类型错误：应接受二维数组，但声明为一维数组
{
    int i;

    for(i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            DFS(a,n,i);
        }
    }
}
void DFS(int a[],int n,int v) // @@ 函数定义参数类型错误：应接受二维数组，但声明为一维数组
{
    int i,j;
    int jud=0;
    int w;
    printf("%d ",v);
    visited[v]=1;
    j=v*n;
    for(i=0; i<n; i++)
    {
        if(a[j+i]!=0&&visited[i]==0)
        {
            w=j+i;
            jud=1;
            break;
        }
        if(jud==0) // @@ 逻辑错误：此条件在 for 循环内部且每次迭代都会执行，导致未找到第一个邻居时 w 立即被设为 -1，破坏后续循环
        {
            w=-1;
        }
    }
    while(w!=-1)
    {
        if(visited[i]==0)
        {
            DFS(a,n,w-j);
        }
        jud=0;
        for(i=w-j+1; i<n; i++)
        {
            if(a[j+i]!=0&&visited[i]==0)
            {
                w=j+i;
                jud=1;
                break;
            }
        }
        if(jud==0)
        {
            w=-1;
        }
    }
}
void TRAVEL_BFS(int a[],int n) // @@ 函数定义参数类型错误：应接受二维数组，但声明为一维数组
{
    int i;
    for(i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            BFS(a,n,i);
        }
    }
}
void BFS(int a[],int n,int v) // @@ 函数定义参数类型错误：应接受二维数组，但声明为一维数组
{
    int w;
    int i,j=v*n,jud=0;
    printf("%d ",v);
    visited[v]=1;
    rear=(rear+1)%100;
    QUE[rear]=v;
    while(rear!=front)
    {
        front=(front+1)%100;
        v=QUE[front];
        j=v*n;
        for(i=0; i<n; i++)
        {
            if(a[j+i]!=0&&visited[i]==0)
            {
                w=j+i;
                jud=1;
                break;
            }
            if(jud==0) // @@ 逻辑错误：同 DFS，在 for 循环内部错误设置 w=-1
            {
                w=-1;
            }
        }
        while(w!=-1)
        {

            if(visited[w-j]==0)
            {
                printf("%d ",w-j);
                rear=(rear+1)%100;
                QUE[rear]=w-j;
                visited[w-j]=1;
            }
            jud=0;
            for(i=w-j+1; i<n; i++)
            {
                if(a[j+i]!=0)
                {
                    w=j+i;
                    jud=1;
                    break;
                }
            }
            if(jud==0)
            {
                w=-1;
            }

        }


    }

}