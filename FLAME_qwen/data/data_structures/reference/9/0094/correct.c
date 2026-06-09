#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

//#define DEBUG

typedef struct {
    int x1, y1 ;
    int x2, y2 ;
    int num ;
    } STR_Line ;
STR_Line Lines[MAX_LINES] ;

int     Num_Lines ;

// 从控制台输入全部线段，保存到全局数组
void InputLines( void )
{
    int i ;

    scanf("%d\n", &Num_Lines) ;

    for ( i=0; i<Num_Lines; i++ )
        scanf("%d%d%d%d", &Lines[i].x1, &Lines[i].y1, &Lines[i].x2, &Lines[i].y2 ) ;
}

// 根据两个线段在数组中的编号，交换两个线段
void SwapLine( int j )
{
    STR_Line tmp ;

    tmp.x1 = Lines[j].x1 ;
    tmp.y1 = Lines[j].y1 ;
    tmp.x2 = Lines[j].x2 ;
    tmp.y2 = Lines[j].y2 ;

    Lines[j].x1 = Lines[j+1].x1 ;
    Lines[j].y1 = Lines[j+1].y1 ;
    Lines[j].x2 = Lines[j+1].x2 ;
    Lines[j].y2 = Lines[j+1].y2 ;

    Lines[j+1].x1 = tmp.x1 ;
    Lines[j+1].y1 = tmp.y1 ;
    Lines[j+1].x2 = tmp.x2 ;
    Lines[j+1].y2 = tmp.y2 ;
}
// 按x坐标，对所有线段排序
void SortLines( void )
{
    int i, j ;

    for ( i=0; i<Num_Lines; i++ ) {
        for ( j=0; j<Num_Lines-i-1; j++ ) {
            if (Lines[j].x1 > Lines[j+1].x1)
                SwapLine(j) ;
            }
        }

#ifdef DEBUG
    PrintLines() ;
#endif
}

// 判断两条线段是否连接在一起。1：连接；0：不连接
int IsConnect( int i, int j )
{
    if ( (Lines[i].x2 == Lines[j].x1) && (Lines[i].y2==Lines[j].y1) )
        return 1 ;
    else
        return 0 ;
}

// 统计每条线段的连接情况
void ConnectLines( void )
{
    int i, j ;
    int p ;
    int f ;

    // 初始化统计结果：假设每条线段都是完全独立的，即彼此无法连接的
    for ( i=0; i<Num_Lines; i++ )
        Lines[i].num = 1 ;

    // 从第0个线段开始直到第N-2个进行遍历
    // 每次遍历都以当前线段为起始线段，遍历其后的所有线段的连接情况
    // p：指向当前的连续线段的最后一段
    for ( i=0; i<Num_Lines-1; i++ ) {
        p = i ;
#ifdef DEBUG
        printf( "%2d: ", i ) ;
#endif
        for ( j=i+1; j<Num_Lines; j++ ) {
            f = IsConnect(p, j) ;
            if ( f ) {                      // 有一个点可以连接
                Lines[i].num ++ ;           // 连接数+1
                p = j ;                     // 指向新线段
#ifdef DEBUG
                printf( "%3d ", j ) ;
#endif
                }
            }
#ifdef DEBUG
        printf( "\n" ) ;
#endif
        }
}

int main( void )
{
    int max, i, p ;

    InputLines() ;
    SortLines() ;
    ConnectLines() ;

    max = 1 ;
    p = 0 ;
    for (i=0; i<Num_Lines; i++)
        if ( Lines[i].num > max ) {
            max = Lines[i].num ;
            p = i ;
            }

    printf( "%d %d %d\n", Lines[p].num, Lines[p].x1, Lines[p].y1 ) ;
    return 0 ;
}



