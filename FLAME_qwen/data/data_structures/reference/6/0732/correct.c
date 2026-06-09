#include <stdio.h>
int stack[100];
int top=-1;
void Push(int item)
{
    stack[++top]=item;
}
void Pop() {
    top--;
}
int main()
{
    int op;
    int item;
    while(1)
    {
        scanf("%d",&op);
        if(op==-1){
            return 0;
        }
        else if(op==1)
        {
            scanf("%d",&item);
            if(top==99)
            {
                printf("error ");
            }
            else{
                Push(item);
            }
        }
        else if(op==0)
        {

            if(top==-1)
                printf("error ");
            else
            {
                printf("%d ",stack[top]);
                Pop();
            }

        }
    }
    return 0;
}

