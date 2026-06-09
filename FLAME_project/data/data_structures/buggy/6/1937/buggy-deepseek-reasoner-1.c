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
    return sum + 1;
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
            if (sum > 100) // @@ Condition should be `sum == 100` to correctly detect full stack
                printf("error"); // @@ Missing space after "error"
            else sum = insert(data);
        }
        else if (n == 0)
        {
            if (sum == 0)
                printf("error"); // @@ Missing space after "error"
            else {
                printf("%d", out()); // @@ Missing space after the popped element
                sum--;
            }
        }if (n == -1)
            return 0;
    }
}