#include <stdio.h>
#include <stdlib.h>

typedef struct shed{
    int num;
    struct shed *link;
}node,*nodeptr;
#define MAXSIZE 100;
nodeptr Top = NULL,p;
int cnt = 0;

int main()
{
    int ope;
    scanf("%d",&ope);
    while(ope != -1){
        if(ope){
            if(cnt == 100)
               printf("error ");
            else{
                p = (nodeptr)malloc(sizeof(node));
                scanf("%d ",&p->num);
                if(Top == NULL)
                    Top =p;
                else{
                    p -> link = Top;
                    Top = p;
                }
                cnt++;
            }
            scanf("%d",&ope);
        }else{
            if(cnt == 0)
                printf("error ");
            else{
                p = Top;
                printf("%d ",p->num);
                Top = p->link;
                free(p);
                cnt--;
            }
            scanf("%d",&ope);
        }
    }
    return 0;
}


