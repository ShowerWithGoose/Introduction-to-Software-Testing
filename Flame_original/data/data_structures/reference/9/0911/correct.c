#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n;
struct line{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int num;
}l[50001];
int p[10001][5]; //position; p1:x1, p2:y1, p3:x2, p4:y2
int main()
{
    int i,j,tag=1;
    int total = 0, max = 1, max_num = 0;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
        scanf("%d %d %d %d",&p[i][1],&p[i][2],&p[i][3],&p[i][4]);
    for(i=1;i<=n;++i){ //为 pi1,pi2找有无前驱，有前驱则跳过
        for(j=1;j<=n;++j){
            if(i != j && p[i][1] == p[j][3] && p[i][2] == p[j][4]){ //若找到前驱，则pi1,pi2不是线段头
                tag = 0;
                break;
            }
        }
        if(tag==1){ // pi1, pi2无前驱时
            l[++total].start_x = p[i][1];
            l[total].start_y = p[i][2];
            l[total].end_x = p[i][3];
            l[total].end_y = p[i][4];
            l[total].num = 1;
        }
        tag = 1;
    }
    for(i=1;i<=total;++i){
        for(j=1;j<=n;++j){ // 把已有线段试图接到每条line后
            if(l[i].end_x == p[j][1] && l[i].end_y == p[j][2]){
                l[i].end_x = p[j][3];
                l[i].end_y = p[j][4];
                l[i].num += 1;
                j = 0; //接好后重新开始扫描，避免扫描不到
            }
        }
    }
    for(i=1;i<=total;++i){
        if(max < l[i].num){
            max = l[i].num;
            max_num = i;
        }
    }
    printf("%d %d %d\n",max,l[max_num].start_x,l[max_num].start_y);
    system("pause");
    return 0;
}
