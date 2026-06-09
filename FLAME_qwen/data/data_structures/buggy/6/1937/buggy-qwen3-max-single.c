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
    return sum + 1; // @@ [The function returns sum + 1 but does not update sum; this causes sum to remain 0, leading to incorrect stack size tracking]
}
int out() {
    intstack* now,* pre=NULL;
    now = head;
    int k;
    if (now->next ==NULL) { // @@ [Dereferencing 'now' without checking if 'now' is NULL; if the stack is empty (head == NULL), this causes undefined behavior]
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
            if (sum > 100) // @@ [Condition should be sum >= 100 because stack capacity is 100; also, sum is never updated correctly due to insert() bug]
                printf("error");
            else sum = insert(data);
        }
        else if (n == 0)
        {
            if (sum == 0)
                printf("error");
            else {
                printf("%d", out()); // @@ [Missing space after printed number as required by output format]
                sum--;
            }
        }if (n == -1)
            return 0;
    }
}