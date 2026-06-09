#include<stdio.h>
int STACK[100];
int top = -1;
int main()
{
    int op, elem;
    while( 1 ) {
        scanf("%d", &op);
        if( op == 1 ) {
            scanf("%d", &elem);
            if( top == 99 ) {
                printf("error ");
                continue;
            }
            STACK[++top] = elem;
        }
        else if( op == 0 ) {
            if( top == -1 ) {
                printf("error ");
                continue;
            }
            printf("%d ", STACK[top--]);
        }
        else if( op == -1 ) 
            break;
    }
    return 0;
}

