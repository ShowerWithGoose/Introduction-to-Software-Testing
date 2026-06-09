#include<stdio.h>
#include<stdlib.h>

typedef struct Stack//栈的结构定义 
{
 	int *data;
    int top, size;
} Stack;

 Stack *init(int n)//栈的初始化 
{
 	Stack *s = (Stack *)malloc(sizeof(Stack));
 	s->data = (int *)malloc(sizeof(int)*n);
    s->size = n;
	s->top = -1;
	return s; 
}

 int empty(Stack *s)//栈的探空 
{
    return s->top == -1;
}

 int top(Stack *s)//返回栈顶元素 
{
    if(empty(s)) return -1;//如果栈空返回-1 
    return s->data[s->top];//如果栈非空返回栈顶元素 
}

 void clear(Stack *s)//销毁栈
{
    if(s == NULL) return ;
    free(s->data);
    free(s);
    return ;
} 

 int push(Stack *s, int val)//入栈 
{
    if(s == NULL) return -1;//如果栈不存在返回-1 
    if(s->top+1 == s->size) return -1;//如果栈满则返回-1
	s->top += 1;
	s->data[s->top] = val;
	return 1;
}

 int pop(Stack *s)//出栈
{
    if(s == NULL) return -1;//如果栈不存在返回-1 
    if(empty(s)) return -1;//如果栈空返回-1
    printf("%d ", s->data[s->top]);
	s->top -= 1;
	return 1; 
} 

int main()
{
    int op, val, ret;
    #define MAX_N 100
 	Stack *s = init(MAX_N);
    scanf("%d", &op);
    while(op != -1)
    {
        if(op == 1)
        {
            scanf("%d", &val);
            ret = push(s, val);
            if(ret == -1)
            {
                printf("error ");
            }
        }
        else if(op == 0)
		{
            ret = pop(s);
            if(ret == -1)
            {
                printf("error ");
			}
		}
        scanf("%d", &op);
	}
	clear(s);
	return 0;
}

