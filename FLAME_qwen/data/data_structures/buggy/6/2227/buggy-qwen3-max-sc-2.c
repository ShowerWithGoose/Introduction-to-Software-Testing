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
            push(s, n[j+1]); @@ // When j is the last valid index (i-1), n[j+1] accesses out-of-bounds memory because j+1 >= i, leading to undefined behavior.
            j++;
        } else {
            printf("%d ", pop(s)); @@ // The pop function may print "error " but still returns an undefined value (since no return in error case), causing undefined behavior when printing %d.
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
        printf("error ");
    } else {
        return s[top--];
    }
} @@ // Missing return statement in error case; function must return a value of type ElemType in all paths, otherwise undefined behavior occurs.

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