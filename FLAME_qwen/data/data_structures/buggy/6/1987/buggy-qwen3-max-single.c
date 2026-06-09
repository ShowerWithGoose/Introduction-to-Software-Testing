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
            } // @@ [The loop condition is logically incorrect: it checks zhan[i] < 100, which compares the stored value (not index) to 100. Also, using zero-initialized array to simulate stack leads to ambiguity since 0 could be a valid pushed value. This breaks stack behavior.]
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
            } // @@ [This simulates pop by scanning from high index downward for non-zero values, but fails if 0 was explicitly pushed (since 0 is treated as empty). Also, doesn't track actual top of stack, leading to incorrect pop order and potential "error" misreporting.]
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}