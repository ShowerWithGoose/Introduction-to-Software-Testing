#include <stdio.h>
#include <stdlib.h>

typedef struct shed{
    int num;
    struct shed *link;
}node,*nodeptr;
#define MAXSIZE 100;
nodeptr top = NULL,p;
int item = 0;

int main()
{
    int n;
    scanf("%d",&n);
    while(n != -1){
        if(n){
            if(item == 100)
               printf("error ");
            else{
                p = (nodeptr)malloc(sizeof(node));
                scanf("%d ",&p->num);
                if(top == NULL)
                    top =p;
                else{
                    p -> link = top;
                    top = p;
                }
                item++;
            }
            scanf("%d",&n);
        }else{
            if(item == 0)
                printf("error ");
            else{
                p = top;
                printf("%d ",p->num);
                top = p->link;
                free(p);
                item--;
            }
            scanf("%d",&n);
        }
    }
    return 0;
}


