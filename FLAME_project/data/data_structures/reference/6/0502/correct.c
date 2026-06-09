#include <stdio.h>
#define MAXSIZE 100
//stack
int STACK[MAXSIZE];
int Top = -1; //init stack

int isEmpty(); //empty return 1 else return 0
int isFull();  //full return 1 else return 0
void push(int s[], int item);
void pop(int s[]);

int main()
{
    int op;   //operation 1 push 0 pop -1 end
    int item; //item to push
    while (1)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &item);
            push(STACK, item);
        }
        else if (op == 0)
            pop(STACK);
        else
            break;
    }
    return 0;
}

int isEmpty()
{
    return Top == -1;
}

int isFull()
{
    return Top == MAXSIZE - 1;
}

void push(int s[], int item)
{
    if (isFull())
        printf("error ");
    else
        s[++Top] = item;
}

void pop(int s[])
{
    if (isEmpty())
        printf("error ");
    else
        //return s[Top--];
        printf("%d ", s[Top--]);
}

