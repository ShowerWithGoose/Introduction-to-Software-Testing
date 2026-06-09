#include <stdio.h>
#include <ctype.h>

#define MAX_QUEUE_SIZE 100

typedef enum tagTokenType
{
	PLUS = 0,
	MINUS,
	MULTIPLY,
	DIVIDE,
	NUMBER,
	END,
	INVALID
} TokenType;

typedef struct tagToken
{
	TokenType type;
	int value;
} Token;

typedef struct tagDeQue
{
	Token tokenQueue[MAX_QUEUE_SIZE];
	int frontId;
	int rearId;
} DeQue;

DeQue deque;

void push_back(DeQue* que, Token token);
void push_front(DeQue* que, Token token);
Token front(DeQue* que);
void pop_front(DeQue* que);

void init();
int parseExpression();
int parseTerm();
int parsePrimary();

int main()
{
	init();
	printf("%d\n", parseExpression());

	return 0;
}

void push_back(DeQue* que, Token token)
{
	que->tokenQueue[que->rearId++] = token;
}

void push_front(DeQue* que, Token token)
{
	que->tokenQueue[--que->frontId] = token;
}

Token front(DeQue* que)
{
	if (que->frontId != que->rearId)
		return que->tokenQueue[que->frontId];
	return (Token){ INVALID, 0 };
}

void pop_front(DeQue* que)
{
	if (que->frontId != que->rearId)
		que->frontId++;
}

void init()
{
	Token token;
	char ch;
	int num;
	int flag;

	deque.frontId = deque.rearId = 10;

	num = 0;
	flag = 0;
	ch = getchar();
	while (ch != EOF)
	{
		if (isdigit(ch))	// is a number
		{
			num = num * 10 + (ch - '0');
			flag = 1;
		}
		else
		{
			if (flag)
			{
				token.type = NUMBER;
				token.value = num;
				push_back(&deque, token);
				num = 0;
				flag = 0;
			}

			if (ch == ' ')
			{
				ch = getchar();
				continue;
			}
			else
			{
				switch (ch)
				{
				case '+':
					token.type = PLUS;
					break;
				case '-':
					token.type = MINUS;
					break;
				case '*':
					token.type = MULTIPLY;
					break;
				case '/':
					token.type = DIVIDE;
					break;
				case '=':
					token.type = END;
					break;
				default:
					break;
				}	// switch
			}	// else of ' '
			push_back(&deque, token);
			if (token.type == END)
				break;
		}	// else of digit
		ch = getchar();
	}	// while

	if (flag)	// remaining number
	{
		token.type = NUMBER;
		token.value = num;
		push_back(&deque, token);
		num = 0;
		flag = 0;
	}
}

int parseExpression()
{
	int left;
	Token token;

	left = parseTerm();	// read in and calc a term

	token = front(&deque);
	pop_front(&deque);

	while (1)
	{
		switch (token.type)
		{
		case PLUS:
			left += parseTerm();
			token = front(&deque);
			pop_front(&deque);
			break;
		case MINUS:
			left -= parseTerm();
			token = front(&deque);
			pop_front(&deque);
			break;
		case END:
		case INVALID:
			return left;
		default:
			push_front(&deque, token);
			return left;
		}
	}

	return 0;
}

int parseTerm()
{
	int left;
	int temp;
	Token token;

	left = parsePrimary();
	token = front(&deque);
	pop_front(&deque);
	while (1)
	{
		switch (token.type)
		{
		case MULTIPLY:
			left *= parsePrimary();
			token = front(&deque);
			pop_front(&deque);
			break;
		case DIVIDE:
			temp = parsePrimary();
			left /= temp;
			token = front(&deque);
			pop_front(&deque);
			break;
		case END:
			return left;
		case INVALID:
			return 0;
		default:
			push_front(&deque, token);
			return left;
		}
	}

	return 0;
}

int parsePrimary()
{
	Token token;

	token = front(&deque);
	pop_front(&deque);
	switch (token.type)
	{
	case PLUS:
		return parsePrimary();
	case MINUS:
		return -parsePrimary();
	case NUMBER:
		return token.value;
	case END:
		return 0;
	case INVALID:
		return 0;
	default:
		return 0;
	}
}



