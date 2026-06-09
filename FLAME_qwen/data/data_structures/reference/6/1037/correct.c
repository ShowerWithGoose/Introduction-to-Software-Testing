#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int RD(){
    int x;
    scanf("%d",&x);
    return x;
}

int stack[100000];
int ptr = 0;

int main(){
#ifdef VSCODE
    freopen("input.in", "r", stdin);
#endif
    int op, val;
    while ((op = RD()) != -1){
        if (op == 1){
            val = RD();
            stack[ptr++] = val;
            if (ptr == 101){
                printf("error ");
                ptr--;
            }
        }
        else {
            if (ptr == 0){
                printf("error ");
                continue;
            }
            ptr--;
            printf("%d ", stack[ptr]);
        }
    }
    return 0;
}

