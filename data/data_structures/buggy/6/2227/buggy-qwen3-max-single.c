#include<stdio.h>
#include<stdlib.h>
#define N 100
typedef int ElemType;
ElemType s[N];
int top = -1;
void push(ElemType s[], ElemType item);
ElemType pop(ElemType s[]);
int isEmpty();
int isFull();
int main() {
    int n[N], i = 0;
    while((scanf("%d", &n[i])) != EOF){
        if(n[i] == -1){
            break;
        }
        i++;
    }
    for(int j = 0;j < i;j++){
        if(n[j] == 1){
            push(s, n[j+1]);
            j++;
        } else {
            printf("%d ", pop(s)); // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value which is then printed as "%d ", leading to incorrect output format and potential undefined behavior.]
        }
    }
    return 0;
}

void push(ElemType s[], ElemType item){
    if(isFull() == 1){
        printf("error ");
    } else {
        s[++top] = item;
    }
}

ElemType pop(ElemType s[]){
    if(isEmpty() == 1){
        printf("error "); // @@ [This prints "error " but the function is expected to return an integer. In the main loop, the return value is always printed with "%d ", so when the stack is empty, both "error " and an undefined/garbage integer will be printed, violating the required output format.]
    } else {
        return s[top--];
    }
}

int isFull(){
    if(top == N-1){
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(){
    if(top == -1){
        return 1;
    } else {
        return 0;
    }
}