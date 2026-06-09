// 1.判断关键字
// 创建stack  存放  进行正常的操作


#include<stdio.h>
#include<string.h>

int stack[100];
int top;


void judge_push(int* temp, int i)
{
    for(int j = 0; j < i; j++)
    {
    if(temp[j] == 1)
    {
        j++;
        stack[top++] = temp[j];
    }

    else if(temp[j] == 0)
    {
        top--;
        if(top >= 0)
        {
        printf("%d ", stack[top]);
        }

        else
        {
            top = 0;
            printf("error ");
        }
    }

    else if(temp[j] == -1)
    {
        break;
    }
    }
}

int main()
{
    top = 0;
    int temp[200];
    memset(temp, 0, sizeof(temp));
    int i = 0;

    while(1)
    {
        scanf("%d", &temp[i++]);

        if(getchar() == '\n')
        {
            break;
        }
    }

    judge_push(temp, i);

    return 0;
}
