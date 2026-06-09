#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma region 栈
#pragma region 结构
// 泛型类型
typedef int TValue;
typedef struct stack
{
    TValue *array;
    int len;
    int volume;
} Stack;
#pragma endregion
#pragma region 创建
// 新建栈
Stack NewStack(int volume)
{
    volume = __max(1, volume); // @@ [Compilation Error: '__max' is not a standard C library function. It is likely a macro from <algorithm> in C++ or a specific compiler extension not available here. Should be replaced with a standard conditional check or a custom max function.]
    Stack res;
    res.array = malloc(volume * sizeof(TValue));
    res.volume = volume;
    res.len = 0;
    return res;
}
#pragma endregion
#pragma region 内部
// 拷贝
void InternalCopy(TValue *source, TValue *target, int len)
{
    for (int i = 0; i < len; i++)
    {
        target[i] = source[i];
    }
}
// 重新设置容量
void Resize(Stack *stack, int target)
{
    while (stack->volume < target)
    {
        stack->volume *= 2;
    }
    TValue *newArray = malloc(stack->volume * sizeof(TValue));
    InternalCopy(stack->array, newArray, stack->len);
    free(stack->array);
    stack->array = newArray;
}
// 默认值
TValue DefaultValue()
{
    return -1;
}
#pragma endregion
#pragma region 增
// 压
void Push(Stack *stack, TValue value)
{
    if (stack->len + 1 >= stack->volume)
    {
        Resize(stack, stack->volume + 1);
    }
    stack->array[stack->len++] = value;
}
#pragma endregion
#pragma region 删
// 弹
TValue Pop(Stack *stack)
{
    if (stack->len == 0)
    {
        return DefaultValue();
    }
    TValue res = stack->array[--stack->len];
    return res;
}
// 释放
void Dispose(Stack *stack)
{
    free(stack->array);
    stack->array=NULL;
}
#pragma endregion
#pragma region 查
// 查看
TValue Peek(Stack *stack)
{
    if (stack->len == 0)
    {
        return DefaultValue();
    }
    TValue res = stack->array[stack->len - 1];
    return res;
}
#pragma endregion
#pragma endregion

Stack stack;

void DoPush(int v)
{
    if (stack.len >= 100)
    {
        printf("error ");
        return;
    }
    Push(&stack, v);
}
void DoPop()
{
    int n = Pop(&stack);
    if (n == -1)
    {
        printf("error ");
    }
    else
    {
        printf("%d ", n);
    }
}

int main()
{
    stack = NewStack(100);
    int op,tmp;
    do
    {
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            scanf("%d",&tmp);
            DoPush(tmp);
            break;
        case 0:
            DoPop();
            break;
        }
    } while (op != -1);
    Dispose(&stack);
}