#include <stdio.h>

#define STACK_SIZE 100

typedef enum tagtackState
{
	STACK_GOOD = 0,
	STACK_EMPTY,
	STACK_UNDERFLOW,
	STACK_OVERFLOW
} StackState;

typedef struct tagStack
{
	int container[STACK_SIZE];
	int size;
	StackState state;
} Stack;

// Stack operations.
Stack* stack_init(Stack* stack);
Stack* stack_push(Stack* stack, int value);
int stack_top(Stack* stack);
Stack* stack_pop(Stack* stack);
StackState stack_state(Stack* stack);
Stack* stack_reset(Stack* stack);
int stack_empty(Stack* stack);

// Custom operations.
void handle();

int main()
{
	handle();

	return 0;
}

Stack* stack_init(Stack* stack)
{
	stack->size = 0;
	stack->state = STACK_GOOD;
	return stack;
}

Stack* stack_push(Stack* stack, int value)
{
	if (stack->size == STACK_SIZE)
		stack->state = STACK_OVERFLOW;
	else
		stack->container[stack->size++] = value;

	return stack;
}

int stack_top(Stack* stack)
{
	if (stack->size == 0)
	{
		stack->state = STACK_EMPTY;
		return 0;
	}
	else
		return stack->container[stack->size - 1];
}

Stack* stack_pop(Stack* stack)
{
	if (stack->size == 0)
		stack->state = STACK_UNDERFLOW;
	else
		stack->size--;

	return stack;
}

StackState stack_state(Stack* stack)
{
	return stack->state;
}

Stack* stack_reset(Stack* stack)
{
	stack->state = STACK_GOOD;
	return stack;
}

int stack_empty(Stack* stack)
{
	return stack->size == 0;
}


void handle()
{
	Stack stack;
	int op;
	int val;

	stack_init(&stack);
	while (scanf("%d", &op) == 1)
	{
		if (op == 1)
		{
			// push
			scanf("%d", &val);
			if (stack_state(stack_push(&stack, val)) != STACK_GOOD)
			{
				printf("error ");
				stack_reset(&stack);
			}
		}
		else if (op == 0)
		{
			val = stack_top(&stack);
			if (stack_state(stack_pop(&stack)) != STACK_GOOD)
			{
				printf("error ");
				stack_reset(&stack);
			}
			else
				printf("%d ", val);
		}
		else
			break;
	}
}


