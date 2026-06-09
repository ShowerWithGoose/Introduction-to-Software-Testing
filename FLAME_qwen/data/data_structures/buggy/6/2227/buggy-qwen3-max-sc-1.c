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
            push(s, n[j+1]); @@ // When j is the last valid index (j == i-1), n[j+1] accesses out-of-bounds memory because n[i] is not guaranteed to exist (loop breaks on -1). This leads to undefined behavior.
            j++;
        } else {
            printf("%d ", pop(s)); @@ // The pop() function may print "error " but still returns an undefined value (since no return in error case), which is then printed as "%d". This causes incorrect output format and undefined behavior.
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
        printf("error "); @@ // Function is expected to return an ElemType (int), but in the error case, it prints "error " and falls through without returning a value, leading to undefined behavior when the caller uses the return value.
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