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
            } // @@ [The loop condition is incorrect: it checks zhan[i] < 100, which compares the stored value rather than the index. This leads to wrong stack top detection and capacity check. Also, using zero-initialized array to simulate stack with gaps is logically flawed.]
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
            } // @@ [This pop logic scans from index 99 downward to find the last non-zero element, which assumes elements are stored contiguously from low to high indices without gaps. However, due to the flawed push logic, gaps may exist, causing incorrect pop behavior or popping from wrong positions. Additionally, it doesn't track actual stack size, so it can't correctly detect empty stack in all cases.]
            if (i == -1) {
                printf("error ");
            }
        }
    }
    return 0;
}