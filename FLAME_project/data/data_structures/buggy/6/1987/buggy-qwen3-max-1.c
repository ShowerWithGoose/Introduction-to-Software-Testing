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
            } // @@ [The loop condition is incorrect: it checks zhan[i] != 0 and zhan[i] < 100, but zhan[i] holds data values, not indices or counts. This leads to wrong stack top detection. Also, the stack should track content size separately instead of relying on zero-initialized values, especially since pushed values can be negative or zero.]
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
            } // @@ [The pop operation searches from the end of the array (index 99 downward) for a non-zero value, which assumes the stack grows upward and uses zero as empty marker. However, this conflicts with the push logic and fails when zero or negative numbers are pushed. Moreover, the stack should behave as LIFO using a top pointer, not by scanning the entire array.]
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}