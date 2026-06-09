#include<stdio.h>
#include<stdlib.h>
int saveStack[110];
int rear = -1;
int isEmpty(void);
int isFull(void);
int main()
{
    int op, elem;
    while (~scanf("%d", &op) && op != -1)
    {
        switch (op)
        {
        case 0:
            if (isEmpty())
                printf("error ");
            else
                printf("%d ", saveStack[rear--]);
            break;
        case 1:
            scanf("%d", &elem);
            if (isFull())
                printf("error ");
            else
                saveStack[++rear] = elem;
        default:
            break;
        }
    }
    // system("pause");
    return 0;
}

int isEmpty(void)
{
    return rear == -1;
}

int isFull(void)
{
    return rear == 99;
}
