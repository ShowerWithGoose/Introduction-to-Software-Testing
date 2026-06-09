#include <stdio.h>
#include <stdlib.h>

// 定义一个结构体用于存储端点信息
typedef struct {
    int x, y;
} Point;

// 定义一个结构体用于存储线段信息
typedef struct {
    Point start, end;
} Segment;

// 寻找连续线段
int findLongestSequence(Segment segments[], int n, Point *startPoint) {
    // 初始化最长连续线段的长度为0
    int maxLength = 0;
    // 初始化起点
    Point bestStart;

    // 对每个线段作为起点检查
    for (int i = 0; i < n; i++) {
        int length = 1;
        Point currentStart = segments[i].start;
        Point currentEnd = segments[i].end;

        // 在剩余线段中查找连续的线段
        int found;
        do {
            found = 0;
            for (int j = 0; j < n; j++) {
                if (segments[j].start.x == currentEnd.x && segments[j].start.y == currentEnd.y) {
                    length++;
                    currentEnd = segments[j].end;
                    found = 1;
                    break;
                }
            }
        } while (found);

        // 更新最长连续线段信息
        if (length > maxLength) {
            maxLength = length;
            bestStart = currentStart;
        }
    }

    *startPoint = bestStart;
    return maxLength;
}

int main() {
    int n;
    scanf("%d", &n);

    Segment segments[n];

    // 读入线段数据
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &segments[i].start.x, &segments[i].start.y, &segments[i].end.x, &segments[i].end.y);
    }

    Point startPoint;
    int maxLength = findLongestSequence(segments, n, &startPoint);

    // 输出结果
    printf("%d %d %d\n", maxLength, startPoint.x, startPoint.y);

    return 0;
}


