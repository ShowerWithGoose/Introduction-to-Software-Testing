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
            for (i = 0; zhan[i] != 0 && zhan[i] < 100; i++) { // @@ The condition `zhan[i] < 100` is incorrect; it should check if `i < 100` to limit the stack capacity. Also, the loop condition should only check for empty slots (zhan[i] == 0) to find the next available position.
            }
            if (i ==  100) {
                printf("error ");
            }
            else {
                zhan[i] = num; 
            }
            
        }
        else {
            int i;
            for (i = 99; i >= 0; i--) {
                if (zhan[i] != 0) {
                    printf("%d ", zhan[i]);
                    zhan[i] = 0;
                    break;
                }
            }
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}