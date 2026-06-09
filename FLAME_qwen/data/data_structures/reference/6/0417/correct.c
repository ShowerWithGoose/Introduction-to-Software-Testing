#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int a[200] = {0};

int main()
{
    int op;
    int now = 0;
    scanf("%d", &op);
    while (op!=-1) {
        if (op==1) {
            scanf("%d", &a[now]);
            now++;
            if (now==100) {
                printf("error ");
                now--;
            }
        } else if (op==0) {
            if (now==0) {
                printf("error ");
            } else {
                now--;
                printf("%d ", a[now]);
            }
        }
        scanf("%d", &op);
    }
    
    
    
    
    return 0;
}









