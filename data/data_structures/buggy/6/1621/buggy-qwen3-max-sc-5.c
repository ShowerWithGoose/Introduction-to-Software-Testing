#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
#define MAXSIZE 100
ElemType Stack[MAXSIZE];
int top=-1;
void initStack(){
    top=-1;
}
int isEmpty(){
    return top == -1;
}
int isFull(){
    return top==MAXSIZE-1;
}
void Error(char s[]){
    printf("%s ", s); // @@ [Passing a string literal "error " to Error() already includes a space, but the function appends another space, causing double space in output. However, this is not the main issue. The real problem is that when pop() returns -1 due to error, the main function checks `if (ele != -1)` and skips printing, but the error message has already been printed by pop() via Error("error "). This leads to correct error output. So why compilation error? Actually, the reported error "/bin/sh: 1: gcc: not found" is NOT a compilation error in the code—it's an environment issue. But since the problem states "Compilation Error" and asks to find code errors, we must look deeper.]

    // However, note: the actual bug is logical, not compilation. But the prompt says "Compilation Error", which contradicts the given output. Given the instructions, perhaps there's no syntax error. But wait: the function Error is defined to take char[], and called with "error " which is fine.

    // Re-examining: the real issue might be that in the pop() function, when stack is empty, it prints "error " and returns -1. Then in main(), if ele != -1, it prints the value. That's correct.

    // But note: what if the popped value is actually -1 (a valid integer pushed)? Then main() would treat it as an error and not print it, which is wrong.

    // Example: push -1 (via op 1 -1), then pop -> returns -1, main sees ele == -1 and does NOT print it, but it should print -1.

    // So the bug is: using -1 as both error indicator and possible valid data.

    // Therefore, the error is in the design of pop() returning -1 on error, because -1 can be a valid element.

    // This causes incorrect output when popping an actual -1.

    // However, the problem says: "If a pop operation is attempted when the stack is empty... output 'error'".

    // So the program must distinguish between error and valid -1.

    // Hence, the error is in the pop() function's return value convention and how main() interprets it.

    // Specifically, in main(), after `ele = pop();`, checking `if (ele != -1)` assumes that -1 only comes from error, but -1 can be a valid popped value.

    // Therefore, the logic error is in main() and pop(): they use -1 to signal error, but -1 is a valid integer that can be pushed.

    // This matches the problem statement: push operation uses integers that are "not 1, 0, or -1"? Wait, re-read problem:

    // "1 followed by an integer (which is not 1, 0, or -1)" — so the pushed integers are guaranteed NOT to be 1, 0, or -1.

    // Therefore, -1 will never be pushed! So returning -1 for error is safe.

    // Then why the discrepancy?

    // Given the problem statement says pushed integers are not 1, 0, or -1, then -1 is not a valid data value. So using -1 as error code is acceptable.

    // So the code logic is correct under the problem constraints.

    // But the reported error is "/bin/sh: 1: gcc: not found", which is not a code error—it's that gcc isn't installed.

    // However, the problem says "Error type: Compilation Error", and we're to find errors in the program.

    // Since the code compiles fine (no syntax errors), and the problem constraints ensure -1 isn't pushed, the code should work.

    // But wait: the reference program uses `push` returning -1 on error, but doesn't use that return value in main. Similarly, our buggy code's push doesn't return anything, but that's okay because push only prints error.

    // The real issue might be elsewhere.

    // Let's compare reference and buggy:

    // Reference pop() returns -1 on error, and main checks if x != -1 to print. Buggy does same.

    // But in buggy code, the Error function prints "error " (with space). Reference directly prints "error ".

    // Both should be same.

    // However, note: in the buggy code, the Error function is called with "error " (which includes a space), and then Error prints that string plus a space: so it prints "error  " (two spaces). But the expected output has single space.

    // Example: Error("error ") -> printf("%s ", s) becomes printf("error  ") — two spaces.

    // That would cause extra space.

    // But the problem says: output "error" followed by a space. So one space after "error".

    // The buggy code outputs two spaces.

    // However, the test case input isn't provided, so we don't know.

    // But the main logical flaw that matches common bugs is the error reporting in Error function.

    // So the line `printf("%s ", s);` is wrong because s already contains a space.

    // It should be `printf("%s", s);` if s is "error ", or call Error("error") and then printf("%s ", s).

    // In main, Error is called as Error("error "), so s is "error " (with space). Then printf adds another space.

    // Therefore, this line causes double space after "error".

    // But the problem requires: "output the string 'error' followed by a space".

    // So it should be "error ", not "error  ".

    // Hence, this is an error.

    // However, the problem says the error type is "Compilation Error", but this is a runtime output error.

    // Given the confusion, and since the instructions say to mark lines with @@ if error may occur, and the Error function's printf is flawed, we mark it.

    // Also, note: the problem says "If you think an error may occur on a particular line", so even if it's logical/runtime, we mark.

    // Another possibility: the code has no compilation error, but the online judge reports compilation error due to something else? Unlikely.

    // After careful analysis, the only plausible code error affecting output is the double space in Error().

    // But wait: the problem's expected output format says: "output the string 'error' followed by a space". So one space.

    // The current Error("error ") call passes a string that ends with space, and then printf adds another space -> two spaces.

    // So to fix, either:
    //   Call Error("error") and keep printf("%s ", s)
    //   Or keep Error("error ") and change printf to "%s"

    // Since the call is Error("error "), the printf should not add extra space.

    // Therefore, the error is in the printf inside Error.

}
void push(ElemType item){
    if(isFull()) Error("error "); // @@ [This passes "error " (with space) to Error, which then prints it with an additional space, resulting in two spaces. But the requirement is one space after "error".]
    else Stack[++top]=item;
}
ElemType pop(){
    if (isEmpty()){
        Error("error "); // @@ [Same issue: passes "error " to Error, leading to double space in output.]
        return -1;
    } 
    else return Stack[top--];
}
int main(){
    int cmd;
    ElemType ele;
    initStack();
    while(1){
        scanf("%d", &cmd);
        if(cmd==-1) break;
        if(cmd==1){
            scanf("%d", &ele);
            push(ele);
        }else if(cmd==0){
            ele=pop();
            if (ele != -1)
            printf("%d ", ele);
        }
    }
    return 0;
}