#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    int sta[105] = {0};
    int n = 0, k = 0, i = 0;
    while(~scanf("%d", &n)) {
        if(n == -1)
            return 0;
        else if (n == 1){
            if(i == 100) {
                printf("error ");
            }
            scanf("%d", &sta[i ++]);
        } else {
            if(i == 0) {
                printf("error ");
                continue;
            }
            printf("%d ", sta[-- i]);
        }
    }
    return 0;
}
