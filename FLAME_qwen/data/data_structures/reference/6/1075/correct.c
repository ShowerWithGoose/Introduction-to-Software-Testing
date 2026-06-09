#include <stdio.h>
#include <string.h>

int Top = -1;
int Stack[500];

void push(int Stack[] ,int n)
{
    Stack[++Top] = n;

}

void pop(int Stack[])
{
    if(Top==-1)
        printf("error ");
    else
        printf("%d ", Stack[Top--]);
}

int main() {

    int k,i,j,n;

    while(scanf("%d ",&k)!= -1)
    {

        if(k==1)
        {
            scanf("%d ",&n);
            push(Stack, n);
        }

        if(k==0)
        {
            pop(Stack);
        }

    }



    return 0;
}


