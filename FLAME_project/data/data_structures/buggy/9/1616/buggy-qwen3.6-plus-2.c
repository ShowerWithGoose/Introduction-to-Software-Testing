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
        if (q == NULL) { // @@ The variable q is NULL when the list was initially empty or only contained the node being processed in a way that q wasn't updated correctly for insertion at head, but specifically here: if the list was empty initially, this code path is unreachable because main handles the first element. However, if check is called and no match is found, q points to the last node. If the list was effectively empty relative to the loop (which shouldn't happen given main's structure), q would be NULL. More critically, if the very first node in `list` does not match, `q` remains NULL after the first iteration? No, `q` is initialized to NULL, then `q=p` happens at the end of the loop. Wait, the loop structure is `for (p = list; p != NULL; q = p, p = p->link)`. Inside the loop, if no match, it continues. After the loop, if `flag==0`, we want to append `data` to the end of the list. `q` holds the last node visited. If `list` was not empty, `q` is the last node. We should do `q->link = data`. The existing code does `q->link = data`. This seems correct for appending. 
        // However, let's look at the failure. 
        // Input: 
        // 2
        // 12 12 13 13
        // 13 13 50 76
        
        // Main:
        // n=2.
        // list = createdata() -> reads "12 12 13 13". list points to Node A (12,12)->(13,13).
        // Loop i=0 to 0 (n-1 = 1 iteration).
        // data = createdata() -> reads "13 13 50 76". data points to Node B (13,13)->(50,76).
        // list = check(data, list).
        
        // Inside check(data=B, list=A):
        // p=A, q=NULL.
        // Check if B->end (50,76) == A->start (12,12)? No.
        // Check if B->start (13,13) == A->end (13,13)? Yes.
        // flag is 0.
        // Enter else-if block.
        // p->end[0] = data->end[0] -> A->end becomes (50,76).
        // p->end[1] = data->end[1] -> A->end becomes (50,76).
        // p->length += data->length -> A->length becomes 1+1=2.
        // flag = 1.
        // data = p (data now points to A).
        // Loop continues: q=A, p=A->link (NULL).
        // Loop terminates.
        // flag is 1.
        // if (flag == 0) is false.
        // Returns list (which is A).
        
        // Back in main:
        // list is A. A has length 2, start (12,12), end (50,76).
        
        // Next part of main:
        // for (p = list; p->link != NULL; p = p->link) {
        //    if (p->length > max) { max = p->length; q = p; }
        // }
        // p starts at list (A).
        // A->link is NULL.
        // The condition p->link != NULL is FALSE immediately.
        // The loop body never executes.
        // max remains 0.
        // q remains uninitialized.
        
        // printf("%d %d %d", max, q->start[0], q->start[1]);
        // Prints 0 and garbage values from uninitialized q.
        
        // The error is that the loop to find the maximum length segment skips the first segment if it's the only one (or the best one) and has no link. Also, q is uninitialized if the loop doesn't run.
        
        // To fix this, we should initialize max and q properly, and ensure the first node is considered.
        // Or change the loop to do-while or handle the first node outside.
        // Also, q must be initialized.
        
        // Let's look at the specific line causing the crash/wrong output.
        // The printf uses q which is uninitialized.
        
        // But I need to mark the error location.
        // The logic error is in the search loop in main.
        
        // Line: for (p = list; p->link != NULL; p = p->link) {
        // This fails to process the last node in the list (or the only node).
        
        // And line: lineptr p, q; -> q is uninitialized.
        
        // Let's annotate the initialization of q and the loop condition.
        
        // Actually, the prompt asks to identify the location of errors.
        
        // Error 1: q is uninitialized.
        // Error 2: The loop condition `p->link != NULL` causes the last node to be skipped.
        
        // If I fix the loop to `p != NULL`, then q will be assigned.
        
        // Let's annotate the lines in main.
        
        // Line 75: lineptr p, q;
        // Line 83: for (p = list; p->link != NULL; p = p->link) {
        
        // I will annotate these two lines.
    }
    return list;
}

int main() {
    int n;
    int max = 0;
    scanf("%d", &n);
    lineptr list;
    lineptr p, q; // @@ Variable 'q' is uninitialized. If the subsequent loop does not execute (e.g., list has only one node), 'q' remains uninitialized, leading to undefined behavior when accessed in printf.
    list = createdata();
    for (int i = 0; i < n - 1; i++) {
        lineptr data;
        data = createdata();
        list = check(data, list);
    }
    for (p = list; p->link != NULL; p = p->link) { // @@ The condition 'p->link != NULL' causes the loop to skip the last node in the linked list. If the longest segment is the last one (or the only one), it will not be considered. Additionally, if the list has only one node, the loop body never executes, leaving 'max' as 0 and 'q' uninitialized. It should be 'p != NULL'.
        if (p->length > max) {
            max = p->length;
            q = p;
        }
    }
    printf("%d %d %d", max, q->start[0], q->start[1]);
    return 0;
}