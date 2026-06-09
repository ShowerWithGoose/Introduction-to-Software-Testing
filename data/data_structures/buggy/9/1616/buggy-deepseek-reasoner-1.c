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
    for (r = list; r != NULL && r->link != target; r = r->link); // @@ 未处理 target 为头节点的情况，若 target 是头节点，函数无法将其删除，导致逻辑错误
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
                data = p; // @@ 新创建的 data 节点未被释放，造成内存泄漏
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
                data = p; // @@ 新创建的 data 节点未被释放，造成内存泄漏
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
        q->link = data; // @@ 当 list 为空时 q 为 NULL，会导致空指针解引用；当前逻辑下虽不会发生，但仍存在潜在风险
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
    for (p = list; p->link != NULL; p = p->link) { // @@ 循环条件错误，会跳过最后一个节点，若最长连续线段在末尾则无法被找到
        if (p->length > max) {
            max = p->length;
            q = p;
        }
    }
    printf("%d %d %d", max, q->start[0], q->start[1]); // @@ 当链表只有一个节点且该节点为最长时，q 未被赋值，输出未定义数据
    return 0;
}