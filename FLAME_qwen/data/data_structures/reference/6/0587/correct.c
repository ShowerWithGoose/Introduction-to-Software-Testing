#include <stdio.h>
#include <stdlib.h>

int a[100];
int top;

int main()
{
    top = 0;
    int c;
    while(scanf("%d", &c) != EOF){
        if(c == 1){
            int k; scanf("%d", &k);
            if(top < 100)
                a[top++] = k;
        }
        else if(c == 0){
            if(top > 0){
                printf("%d ", a[--top]);
            }
            else{
                printf("error ");
            }
        }
        else if(c == -1){
            break;
        }
    }
    return 0;
}

