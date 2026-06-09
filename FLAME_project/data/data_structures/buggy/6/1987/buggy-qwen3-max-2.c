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
            for (i = 0; zhan[i] != 0 && zhan[i] < 100; i++) {
            } // @@ [The condition `zhan[i] < 100` is incorrect. It mistakenly treats stack values less than 100 as occupied slots. The loop should only check if the slot is non-zero (or use a separate size counter). Also, this approach fails when pushing negative numbers or zero, which are valid stack elements but treated as empty slots.]
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
            } // @@ [The pop operation searches from the end of the array (index 99 downward) for a non-zero value, which assumes the stack grows upward in the array. However, the push operation fills from index 0 upward. This mismatch causes incorrect pop order and logic. Additionally, using zero to mark empty slots fails when zero is a valid pushed value.]
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}