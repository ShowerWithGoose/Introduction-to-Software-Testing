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
            printf("%d ", pop(s)); // @@ The pop function may print "error " and then return an undefined value (since there is no return after the error case), causing incorrect output. Also, the program does not handle the case where the input is 0 (pop) correctly because it treats any non-1 value as a pop, but the problem specifies that 0 represents pop and -1 ends input; however, -1 is already handled, so 0 is the only other operation. The logic is correct for 0, but the pop function's error handling is flawed.
        }
    }
    return 0;
}

void push(ElemType s[], ElemType item){
    if(isFull() == 1){
        printf("error "); // @@ This prints "error " but does not stop the program or handle the full stack condition as required; the problem expects "error " to be printed and the operation to be ignored, but here the push is not performed, which is correct, but the function does not return after printing error, so it continues to execute the else block? Actually, the else is not executed because of the if-else structure, so this is fine. However, the problem requires that if a push is attempted when the stack is full, output "error " and do not push. This implementation does that, but note that the reference program exits on error, while this one continues. This may be acceptable depending on interpretation, but the main issue is in pop.
    } else {
        s[++top] = item;
    }
}

ElemType pop(ElemType s[]){
    if(isEmpty() == 1){
        printf("error "); // @@ When the stack is empty, this prints "error " but then does not return a value, leading to undefined behavior when the caller tries to print the return value. The function should either return a dummy value or handle the error differently. Additionally, the problem expects that if a pop is attempted on an empty stack, "error " is printed and no pop occurs, but here the function still returns something (garbage) which gets printed.
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