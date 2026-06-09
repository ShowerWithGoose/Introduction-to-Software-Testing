#include<stdio.h>
#include<stdlib.h>

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
                data->start[0] = p->start[0];
                data->start[1] = p->start[1];
                data->length += p->length;
                list = deleteLine(list, p);
                return list;
            }
        }
    }
    if (flag == 0) {
        q->link = data;
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
    for (p = list; p->link != NULL; p = p->link) { // @@ [Error: Loop condition stops before the last node, so the last segment (or the only segment when n==1) is never checked. max remains 0 and q is uninitialized, leading to garbage output. Should be: for(p=list; p!=NULL; p=p->link)]
        if (p->length > max) {
            max = p->length;
            q = p;
        }
    }
    printf("%d %d %d", max, q->start[0], q->start[1]);
    return 0;
}