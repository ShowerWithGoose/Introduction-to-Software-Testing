/* 第七次作业 图 第一题图的遍历
实现了深度优先搜索和广度优先搜索 
由于提前告知了edge和vertex数, 所以所用方法非标准方法*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
// #include<windows.h>

//图基础例程
struct EDGE {
    int vertex1;
    int vertex2;
};
typedef struct EDGE *EDGE_;

struct VERTEX {
    int harsh_edge[100];//edge哈希值, 要始终保证指向的邻节点是从小到大排序的(heap)
    int post_size;//edge数
};
typedef struct VERTEX *GRAPH_;

struct VERTEX graph[100];
struct EDGE edge[100];
void AddEdge( int link_v, int cur_v, int *edge_num );
void heapSort( int size, int *edge_harsh_table );
//遍历例程
void Dfs( int begin, int isDeleted, int d );
void Bfs( int begin, int isDeleted, int d );
int visited[100];
void initVisited( ) {
    int i;
    for ( i = 0; i < 100; i++ ) {
        visited[i] = 0;
    }
}

#define ElementType int
#define Q_SIZE 1000
#ifndef _QUEUE_H_
#define _QUEUE_H_

struct Q_NODE {
    ElementType value;
}queue[Q_SIZE];
int rear = Q_SIZE-1;//同时处理循环情况和为空情况
int front = Q_SIZE;
int count = 0;//记队元素总数

struct Q_NODE QueuePop( ) {
    if ( count - 1 < 0 ) {
        printf( "error! queue already empty" );
        exit( 1 );
    }
    else
        count--;
    front %= Q_SIZE;//给上一次擦屁股
    return queue[front++];
}
void QueuePush( struct Q_NODE tmp ) {
    if ( count + 1 > Q_SIZE ) {
        printf( "error! overflow the queue" );
        return;
    }
    count++;
    rear++;
    rear %= Q_SIZE;
    queue[rear].value = tmp.value;
    return;
}
void InitQueue( ) {
    rear = Q_SIZE-1;
    front = Q_SIZE;
    count = 0;
}//每次要重复利用队列时必须重新初始化（该实现方法弊端）

#endif  //_QUEUE_H_

int main( ) {
    int vertex_size, edge_size, v1, v2, deleted;
    int edge_num = 0;
    // freopen( "F:\\notes\\assign\\seven_graph\\in.txt", "r", stdin );
    scanf( "%d%d", &vertex_size, &edge_size );

    while ( scanf( "%d%d", &v1, &v2 ) == 2 ) {
        AddEdge( v1, v2, &edge_num );
    }
    deleted = v1;
    Dfs( 0, 0, deleted );
    printf( "\n" );
    initVisited( );
    Bfs( 0, 0, deleted );
    initVisited( );
    printf( "\n" );
    Dfs( 0, 1, deleted );
    initVisited( );
    InitQueue( );
    printf( "\n" );
    Bfs( 0, 1, deleted );
    return 0;
}

void AddEdge( int link_v, int cur_v, int *edge_num ) {
    edge[*edge_num].vertex1 = link_v;
    edge[*edge_num].vertex2 = cur_v;

    graph[link_v].harsh_edge[graph[link_v].post_size] = *edge_num;
    graph[link_v].post_size++;
    heapSort( graph[link_v].post_size, graph[link_v].harsh_edge );

    graph[cur_v].harsh_edge[graph[cur_v].post_size] = *edge_num;
    graph[cur_v].post_size++;
    heapSort( graph[cur_v].post_size, graph[cur_v].harsh_edge );
    ( *edge_num )++;
}

void heapSort( int size, int *edge_harsh_table ) {
    int i, j, sum;
    j = edge_harsh_table[size - 1];
    sum = edge[j].vertex1 + edge[j].vertex2;
    for ( i = size - 2; i >= 0 && edge[edge_harsh_table[i]].vertex1 + edge[edge_harsh_table[i]].vertex2 > sum; i-- )
        edge_harsh_table[i + 1] = edge_harsh_table[i];
    edge_harsh_table[i + 1] = j;
}


void Dfs( int begin, int isDeleted, int d ) {
    int i, j, edge_h;
    if ( begin == 0 ) {
        visited[0] = 1;
        printf( "0 " );
    }
    
    for ( i = 0; i < graph[begin].post_size; i++ ) {
        edge_h = graph[begin].harsh_edge[i];
        j = edge[edge_h].vertex1 + edge[edge_h].vertex2 - begin;//利用相减的办法去除另一个顶点
        if ( isDeleted && d == j ) {
            continue;
        }
        if ( !visited[j] ) {
            visited[j] = 1;//全部访问一遍完就结束, 不需要回溯
            printf( "%d ", j );
            Dfs( j, isDeleted, d );
        }
    }
}

//假定都是连通的， 否则访问函数都要改写
void Bfs( int begin, int isDeleted, int d ) {
    int i, j, edge_h;
    struct Q_NODE tmp, e;
    printf( "%d ", begin );//访问顶点0
    visited[0] = 1;
    tmp.value = begin;
    QueuePush( tmp );

    while ( count ) {
        tmp = QueuePop( );
        /* printf( "tmp: %d\n", tmp.value);
        for ( i = front; i <= rear; i++ ) {
            printf( "%d ", queue[i].value );
        }
        printf( "\n" ); */
        for ( i = 0; i < graph[tmp.value].post_size; i++ ) {
            edge_h = graph[tmp.value].harsh_edge[i];
            j = edge[edge_h].vertex1 + edge[edge_h].vertex2 - tmp.value;
            if ( isDeleted && j == d ) {
                continue;
            }
            if ( !visited[j] ) {
                printf( "%d ", j );
                visited[j] = 1;
                e.value = j;
                QueuePush( e );
            }
        }
    }

}
