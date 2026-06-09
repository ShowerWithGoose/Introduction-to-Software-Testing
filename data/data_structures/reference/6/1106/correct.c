#include <stdio.h>
int main()
{
    int stack[128],op,elem,top=-1,flag=1;
    while(flag)
    {
        scanf("%d",&op);
        switch(op)
        {
            case -1:
                flag=0; 
                break;
            case 1:
                scanf("%d",&elem);
                if(top==99) printf("error ");
                else stack[++top]=elem;
                break;
            case 0:
                if(top==-1) printf("error ");
                else printf("%d ",stack[top--]);
                break;
        }
    }
    return 0;
}

