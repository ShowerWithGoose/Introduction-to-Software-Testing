#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sum = 0;
typedef struct intstack {
    int data;
      struct intstack* next;
}intstack;
intstack* head = NULL;
int insert(int data) {
    intstack* temp = (intstack*)malloc(sizeof(intstack));
    temp->data = data;
    if (head ==NULL) {
        head = temp;
        temp->next = NULL;
    }
    else {
        intstack* t;
        t = head;
        while (t->next != NULL) {
            t = t->next;
        }t->next = temp;
        temp->next = NULL;
    }
    return sum + 1; // @@ The function returns sum+1 but the caller assigns it to sum, which increments sum by 1 each time, but sum is also incremented elsewhere inconsistently. This leads to incorrect stack size tracking.
}
int out() {
    intstack* now,* pre=NULL;
    now = head;
    int k;
    if (now->next ==NULL) {
        k = now->data;
        free(now);
        head = NULL;
    }
    else {
        while (now->next != NULL) {
            pre = now;
            now = now->next;
        } k = now->data;
        pre->next = NULL;
        free(now);
    }
    
    return k;

}
int main() {
    int n;
    int data;
    while (1) {
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d", &data);
            if (sum > 100) // @@ Should be sum >= 100 to check if stack is full (max capacity 100). Using > allows 101 elements.
                printf("error");
            else sum = insert(data); // @@ The insert function returns sum+1, but sum is already the current size. This assignment incorrectly updates sum.
        }
        else if (n == 0)
        {
            if (sum == 0)
                printf("error");
            else {
                printf("%d", out()); // @@ Missing space after the popped element. Should be printf("%d ", out());
                sum--;
            }
        }if (n == -1)
            return 0;
    }
}