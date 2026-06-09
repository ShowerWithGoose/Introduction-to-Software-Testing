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
            printf("%d ", pop(s)); // @@ [Error: When pop is attempted on an empty stack, the function prints "error " but does not return a value, leading to undefined behavior. Additionally, the logic here does not check for empty stack before calling pop, and the pop function's return type is ElemType but it may not return a value on error.]
        }
    }
    return 0;
}

void push(ElemType s[], ElemType item){
    if(isFull() == 1){
        printf("error "); // @@ [Error: According to the problem, when a push is attempted on a full stack, the program should output "error " and then terminate (as in the reference program using exit(-1)). Here it only prints "error " and continues, which is incorrect.]
    } else {
        s[++top] = item;
    }
}

ElemType pop(ElemType s[]){
    if(isEmpty() == 1){
        printf("error "); // @@ [Error: When pop is attempted on an empty stack, the function prints "error " but does not return a value. The return type is ElemType, so this causes undefined behavior. Also, the program should terminate after printing "error " as per the reference program.]
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