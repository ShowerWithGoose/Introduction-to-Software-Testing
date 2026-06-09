#include <stdio.h>
#include <stdlib.h>
//建立结构存储一条线段的两个端点坐标和flag，建立数组储存数据,按照前端点x升序排列

struct node
{
    int x1, y1, x2, y2;
}line[105];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
    }

//根据线段前端点逐个（已经充当过其他线段之后的线段的不遍历）遍历，记录当前线段数num
    int max = 0, maxline = 0;
    for (int i = 0; i < n; i++){
        int len = 1;
        int current = i;

        int sign = 1;
        while(sign){
            sign = 0;
            for (int j = 0; j < n; j++){
                if (line[current].x2 == line[j].x1 && line[current].y2 == line[j].y1){
                    len++;
                    current = j;
                    sign = 1;
                    break;
                }
            }
        }

        if (len > max){//若len >max,则记录该端点，max=num
            max = len;
            maxline = i;
        }
    }

    printf("%d %d %d", max, line[maxline].x1, line[maxline].y1);

    return 0;
}


