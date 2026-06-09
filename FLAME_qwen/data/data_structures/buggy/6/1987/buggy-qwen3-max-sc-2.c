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
            } // @@ [The loop condition is incorrect: it checks zhan[i] < 100 which compares stack value instead of index; also, using zero-initialized array to simulate stack leads to logical errors when pushing zero values or when gaps exist]
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
            } // @@ [This pop logic scans from the end of the array backward to find a non-zero element, which does not simulate a LIFO stack correctly; it breaks stack order and fails when zeros are valid pushed values]
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}