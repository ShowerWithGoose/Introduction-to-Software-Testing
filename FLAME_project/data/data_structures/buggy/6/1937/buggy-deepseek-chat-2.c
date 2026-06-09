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
    return sum + 1; // @@ The function returns sum+1 but the caller assigns this to sum, which incorrectly increments sum by the return value instead of just incrementing by 1. This causes sum to grow exponentially (e.g., after first insert, sum becomes 1; after second, sum becomes 2; after third, sum becomes 4, etc.), leading to incorrect stack full detection and pop behavior.
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
            if (sum > 100) // @@ The condition should be sum >= 100 to check if the stack is full (max capacity 100). Using > allows one extra element beyond capacity. Also, due to the bug in insert(), sum grows incorrectly, making this check unreliable.
                printf("error");
            else sum = insert(data); // @@ Assigning the return value of insert() to sum causes sum to become the return value (sum+1) instead of just incrementing by 1, leading to incorrect sum tracking.
        }
        else if (n == 0)
        {
            if (sum == 0)
                printf("error");
            else {
                printf("%d", out()); // @@ Missing space after the popped element. The expected output requires a space after each popped element (e.g., "655 "), but this prints the number directly without a space, causing concatenation like "655901".
                sum--;
            }
        }if (n == -1)
            return 0;
    }
}