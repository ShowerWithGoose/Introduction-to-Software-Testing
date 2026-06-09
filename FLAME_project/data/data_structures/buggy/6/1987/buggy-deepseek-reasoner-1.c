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
            for (i = 0; zhan[i] != 0 && zhan[i] < 100; i++) { // @@ The condition stops at elements >=100, causing overwrite of existing data (e.g., 901 overwritten by 655). Should find first empty slot without the <100 constraint, or use a stack pointer.
            }
            if (i ==  100) { // @@ This full-check never triggers correctly because i stops early due to flawed condition; stack capacity logic is incorrect.
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