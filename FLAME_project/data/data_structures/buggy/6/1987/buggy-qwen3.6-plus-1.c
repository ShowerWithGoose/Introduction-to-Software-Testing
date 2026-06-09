#include <stdio.h>
int main()  {
    int zhan[108] = {0};
    int command, num;
    while (1) {
        scanf("%d", &command);
        if(command == -1) {
            break;
        }
        
        
        if (command == 1) {
            scanf("%d", &num);
            int i;
            for (i = 0; zhan[i] != 0 && zhan[i] < 100; i++) { // @@ The logic for finding the top of the stack is incorrect. It relies on value 0 to indicate empty slots, which fails if 0 is pushed or if non-contiguous memory is used. It should track the stack size with a separate variable. Also, the condition `zhan[i] < 100` is irrelevant to stack capacity checking.
            }
            if (i ==  100) { // @@ This check is based on the flawed loop above. It should check if the actual stack size has reached 100.
                printf("error ");
            }
            else {
                zhan[i] = num;  // @@ Pushing to index `i` found by the flawed loop does not maintain LIFO order correctly relative to the pop operation below, and doesn't handle stack full/empty states properly using a size tracker.
            }
            
        }
        else {
            int i;
            for (i = 99; i >= 0; i--) { // @@ Popping by scanning for the last non-zero element is incorrect. It assumes 0 means empty and doesn't respect the actual order of pushes if values are repeated or if 0 is a valid push value. It should pop from the current top index tracked by a size variable.
                if (zhan[i] != 0) {
                    printf("%d ", zhan[i]);
                    zhan[i] = 0;
                    break;
                }
            }
            if (i == -1) { // @@ This error check is also flawed because it depends on the incorrect scanning logic. It should check if the stack size is 0.
                printf("error ");
            }
        }
    }
    return 0;
}