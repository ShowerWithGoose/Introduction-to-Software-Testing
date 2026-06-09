#include<stdio.h>
#include<stdlib.h>
//代码思路：构建一个结构体，包含线段的起点，终点，和线段长度
//每次输入后进行一次检测，若新线段和已有线段相连，则更新起点和终点，长度++
//若没有相连的线段，则新建一条数据

//注意一条线段把两条孤立线段连起来的情况；

typedef struct _line {
    int start[2];
    int end[2];
    int length;
    struct _line *link;
} line, *lineptr;

lineptr createdata(void) {
    lineptr p;
    p = (lineptr)malloc(sizeof(line));
    scanf("%d%d%d%d", &p->start[0], &p->start[1], &p->end[0], &p->end[1]);
    p->length = 1;
    p->link = NULL;
    return p;
}

lineptr deleteLine(lineptr list, lineptr target) {
    lineptr r;
    for (r = list; r != NULL && r->link != target; r = r->link);
    if (r != NULL && r->link == target) {
        r->link = target->link;
        free(target);
    }
    return list;
}

lineptr check(lineptr data, lineptr list) {
    lineptr p, q;
    p = NULL;
    q = NULL;
    int flag = 0;
    for (p = list; p != NULL; q = p, p = p->link) {
        if (data->end[0] == p->start[0] && data->end[1] == p->start[1]) {
            if (flag == 0) {
                p->start[0] = data->start[0];
                p->start[1] = data->start[1];
                p->length += data->length;
                flag = 1;
                data = p;
            } else {
                //一条线段把两条孤立线段连起来的情况
                data->end[0] = p->end[0];
                data->end[1] = p->end[1];
                data->length += p->length;
                list = deleteLine(list, p);
                return list;
            }
        } else if (data->start[0] == p->end[0] && data->start[1] == p->end[1]) {
            if (flag == 0) {
                p->end[0] = data->end[0];
                p->end[1] = data->end[1];
                p->length += data->length;
                flag = 1;
                data = p;
            } else {
                //一条线段把两条孤立线段连起来的情况
                data->start[0] = p->start[0];
                data->start[1] = p->start[1];
                data->length += p->length;
                list = deleteLine(list, p);
                return list;
            }
        }
    }
    if (flag == 0) {
        q->link = data; // @@ [q is uninitialized when list is empty or when no matching segment is found in the loop; this leads to undefined behavior]
    }
    return list;
}

int main() {
    int n;
    int max = 0;
    scanf("%d", &n);
    lineptr list;
    lineptr p, q;
    list = createdata();
    for (int i = 0; i < n - 1; i++) {
        lineptr data;
        data = createdata();
        list = check(data, list);
    }
    for (p = list; p->link != NULL; p = p->link) { // @@ [loop condition skips the last node; if the longest segment is the last one, it won't be considered]
        if (p->length > max) {
            max = p->length;
            q = p;
        }
    }
    printf("%d %d %d", max, q->start[0], q->start[1]); // @@ [q may be uninitialized if no segment was found with length > 0, leading to undefined behavior]
    return 0;
}