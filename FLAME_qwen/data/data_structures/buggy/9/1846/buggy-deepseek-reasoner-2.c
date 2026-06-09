#include <stdio.h>

struct line{
    int x1 ;
    int y1;
    int x2 ;
    int y2 ;
};
struct line list[105] ;//储存每条线段端点的坐标
int pro[105][3] ;//储存每条线段起点坐标以及能连接线段数量

int main() {
    int n ;//线段个数
    int i ,j ;
    scanf("%d", &n) ;
    //输入
    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &list[i].x1, &list[i].y1, &list[i].x2, &list[i].y2) ;
    }
    int cnt ;
    int x, y ;
    //连线
    for (i = 0; i < n; i++) {
        pro[i][1] = list[i].x1 ;
        pro[i][2] = list[i].x2 ;  // @@ Error: should store list[i].y1 (the y-coordinate of the starting point), not list[i].x2
        x = list[i].x2 ;
        y = list[i].y2 ;
        for (j = 0,  cnt = 1; j < n; j++) {
            if(x == list[j].x1 && y == list[j].y1){
                cnt ++ ;
                x = list[j].x2 ;
                y = list[j].y2 ;
                j = -1 ;//重新从第一条线段开始遍历
            }
        }
        pro[i][0] = cnt ;
    }
    //找到包含最多线段数的连续线段
    int flag ;
    for (i = 0, flag = 0; i < n; i++) {
        if(pro[i][0] > pro[flag][0])
            flag = i ;
    }
    //输出
    printf("%d %d %d", pro[flag][0], pro[flag][1], pro[flag][2]) ;

    return 0;
}