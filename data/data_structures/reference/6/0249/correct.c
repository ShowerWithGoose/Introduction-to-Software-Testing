#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int main(){
    int stack[N];
    int p,op;
    p=-1;
    scanf("%d",&op);
    while (op!=-1)
    {
        switch (op)
        {
        case 1:
            if (p==N)
            {
                printf("error ");
            }else{
                scanf("%d",&stack[++p]);
            }
            break;
        default:
            if (p==-1)
            {
                printf("error ");
            }else{
                printf("%d ",stack[p--]);
            }
            break;
        }
        scanf("%d",&op);
    }
    return 0;
}
