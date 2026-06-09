#include <stdio.h>
#include <string.h>

#define BUILD_STACK_STRUCT(stack_type, type, max_size) \
typedef struct \
{ \
    type stack[max_size]; \
    unsigned int top; \
}stack_type;

#define BUILD_STACK_FUNC_DEF(stack_type, type, max_size) \
void init_##stack_type(stack_type *stack); \
unsigned int size_##stack_type(const stack_type *stack); \
type top_##stack_type(const stack_type *stack); \
type pop_##stack_type(stack_type *stack); \
void push_##stack_type(stack_type *stack, type value);

#define BUILD_STACK_FUNC(stack_type, type, max_size) \
void init_##stack_type(stack_type *stack) \
{ \
    stack->top = 0; \
} \
unsigned int size_##stack_type(const stack_type *stack) \
{ \
    return stack->top; \
} \
type top_##stack_type(const stack_type *stack) \
{ \
    return stack->stack[stack->top - 1]; \
} \
type pop_##stack_type(stack_type *stack) \
{ \
    return stack->stack[--stack->top]; \
} \
void push_##stack_type(stack_type *stack, type value) \
{ \
    stack->stack[stack->top++] = value; \
}

#define STACK_INIT(stack_type, stack_addr) init_##stack_type(stack_addr)
#define STACK_SIZE(stack_type, stack_addr) size_##stack_type(stack_addr)
#define STACK_TOP(stack_type, stack_addr) top_##stack_type(stack_addr)
#define STACK_POP(stack_type, stack_addr) pop_##stack_type(stack_addr)
#define STACK_PUSH(stack_type, stack_addr, value) push_##stack_type(stack_addr, value)

BUILD_STACK_STRUCT(mstack, int, 100)

BUILD_STACK_FUNC_DEF(mstack, int, 100)

mstack base_stack;

int main()
{
	int cmd, x;
	
	STACK_INIT(mstack, &base_stack);
	while (scanf("%d", &cmd) != EOF && cmd != -1)
	{
		if (cmd == 1)
		{
			if (STACK_SIZE(mstack, &base_stack) == 100) printf("error ");
			else scanf("%d", &x), STACK_PUSH(mstack, &base_stack, x);
		}
		else
		{
			if (STACK_SIZE(mstack, &base_stack) == 0) printf("error ");
			else printf("%d ", STACK_POP(mstack, &base_stack));
		}
	}
	return 0;
}

BUILD_STACK_FUNC(mstack, int, 1024)

