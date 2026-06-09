#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int max=100;
   // scanf("%d",&max);
    int *top;
    top=(int*)malloc(sizeof(int)*(max+1));
    memset(top,0,sizeof(int)*(max+1));
    int* head=top;
    while (1)
    {
        int op;
        int val;
        scanf("%d",&op);
        if(-1==op)break; 
        if(1==op)
        {
            scanf("%d",&val);
            if((top-head)==max-1)
            {
                printf("error ");
                continue;
            }
            top++;
            *(top)=val;
        }
        if(0==op)
        {
            if((top-head)==0)
            {
                printf("error ");
                continue;
            }
            printf("%d ",*(top));
            top--;
        }
    }
    putchar('\n');
    free(head);
    system("pause");
    return 0;
}
