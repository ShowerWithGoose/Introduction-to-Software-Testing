#include <stdio.h>
int main()  {
    int zhan[108] = {0};
    int command, num;
    int top = -1; // @@ [The original code uses value-based detection (checking for 0) to manage the stack, which fails when pushing 0 or negative numbers, and incorrectly identifies empty slots. A proper stack pointer 'top' is needed to track the actual stack state.]
    while (1) {
        scanf("%d", &command);
        if(command == -1) {
            break;
        }
        
        
        if (command == 1) {
            scanf("%d", &num);
            if (top == 99) { // @@ [Check if stack is full using the top pointer instead of scanning for non-zero values.]
                printf("error ");
            }
            else {
                top++;
                zhan[top] = num; // @@ [Push the element onto the stack at the position indicated by top.]
            }
            
        }
        else {
            if (top == -1) { // @@ [Check if stack is empty using the top pointer.]
                printf("error ");
            }
            else {
                printf("%d ", zhan[top]); // @@ [Pop the element from the top of the stack.]
                top--; // @@ [Decrement the top pointer to remove the element.]
            }
        }
    }
    return 0;
}