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
    if (now->next ==NULL) { // @@ [Error: If head is NULL (empty stack), dereferencing now->next causes a segmentation fault. The function does not check for an empty stack before accessing now->next.]
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
            if (sum > 100) // @@ [Error: The condition should be sum >= 100 to check if the stack is full (maximum capacity 100). Using > allows 101 elements to be pushed before error.]
                printf("error");
            else sum = insert(data);
        }
        else if (n == 0)
        {
            if (sum == 0)
                printf("error");
            else {
                printf("%d", out()); // @@ [Error: Output should be followed by a space as per problem specification: "output the sequence of elements popped... separated by spaces. Ensure there is a space after the last element."]
                sum--;
            }
        }if (n == -1)
            return 0;
    }
}