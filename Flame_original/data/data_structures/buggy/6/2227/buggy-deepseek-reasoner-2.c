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
            printf("%d ", pop(s)); // @@ [This line attempts pop for any non-1 value, but according to the problem, only 0 represents a pop operation; pushed values (not 1,0,-1) are being mistaken for pop requests, causing incorrect stack behavior.]
        }
    }
    return 0;
}

void push(ElemType s[], ElemType item){
    if(isFull() == 1){
        printf("error "); // @@ [When the stack is full, the program should output "error " and stop further execution (as the reference program does by calling exit). This line only prints but does not terminate, so a push on a full stack still occurs after the error message, leading to buffer overflow and incorrect state.]
    } else {
        s[++top] = item;
    }
}

ElemType pop(ElemType s[]){
    if(isEmpty() == 1){
        printf("error "); // @@ [On empty stack, the function prints "error " but does not return a value; the function has a non‑void return type, so this path leads to undefined behavior. Also, no termination is performed as in the reference program.]
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