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
            } // @@ [The condition `zhan[i] < 100` is incorrect for checking stack capacity; it confuses data value with index. Also, the stack should track top index, not search for zero.]
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
            } // @@ [Searching from index 99 downward assumes fixed size and uses zero to indicate empty, but push logic doesn't maintain contiguous stack; this breaks LIFO order and pop behavior.]
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}