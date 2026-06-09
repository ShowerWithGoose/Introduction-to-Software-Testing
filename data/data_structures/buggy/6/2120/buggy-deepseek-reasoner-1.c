#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma region 栈 // @@ [Non-standard pragma may cause compilation error in strict compilers]
#pragma region 结构 // @@ [Non-standard pragma may cause compilation error]
// 泛型类型
typedef int TValue;
typedef struct stack
{
    TValue *array;
    int len;
    int volume;
} Stack;
#pragma endregion // @@ [Non-standard pragma may cause compilation error]
#pragma region 创建 // @@ [Non-standard pragma may cause compilation error]
// 新建栈
Stack NewStack(int volume)
{
    volume = __max(1, volume); // @@ [__max is not a standard function; results in implicit declaration and linker error]
    Stack res;
    res.array = malloc(volume * sizeof(TValue));
    res.volume = volume;
    res.len = 0;
    return res;
}
#pragma endregion // @@ [Non-standard pragma may cause compilation error]
#pragma region 内部 // @@ [Non-standard pragma may cause compilation error]
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
#pragma endregion // @@ [Non-standard pragma may cause compilation error]
#pragma region 增 // @@ [Non-standard pragma may cause compilation error]
// 压
void Push(Stack *stack, TValue value)
{
    if (stack->len + 1 >= stack->volume)
    {
        Resize(stack, stack->volume + 1);
    }
    stack->array[stack->len++] = value;
}
#pragma endregion // @@ [Non-standard pragma may cause compilation error]
#pragma region 删 // @@ [Non-standard pragma may cause compilation error]
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
#pragma endregion // @@ [Non-standard pragma may cause compilation error]
#pragma region 查 // @@ [Non-standard pragma may cause compilation error]
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
#pragma endregion // @@ [Non-standard pragma may cause compilation error]
#pragma endregion // @@ [Non-standard pragma may cause compilation error]

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