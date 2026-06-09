#include <stdio.h>
#include <string.h>

#define isNUM(c) (c) >= '0' && (c) <= '9'

#define BUILD_STACK_STURCTUR(type, stack_name, stack_size) \
type stack_name[stack_size]; \
int top_##stack_name;

#define BUILD_STACK_FUNC_DEC(type, stack_name, stack_size) \
int size_##stack_name(); \
void clear_##stack_name(); \
void push_##stack_name(type value); \
type get_top_##stack_name(); \
type pop_##stack_name();

#define BUILD_STACK_FUNC(type, stack_name, stack_size) \
int size_##stack_name() \
{ \
	return top_##stack_name; \
} \
void clear_##stack_name() \
{ \
	top_##stack_name = 0; \
} \
void push_##stack_name(type value) \
{ \
	stack_name[top_##stack_name++] = value; \
} \
type get_top_##stack_name() \
{ \
	return stack_name[top_##stack_name - 1]; \
} \
type pop_##stack_name() \
{ \
	return stack_name[--top_##stack_name]; \
}

BUILD_STACK_STURCTUR(char, oper, 1024)
BUILD_STACK_STURCTUR(long long, nvalue, 1024)

BUILD_STACK_FUNC_DEC(char, oper, 1024);
BUILD_STACK_FUNC_DEC(long long, nvalue, 1024)
void delc(char *str, char c);
int getPrio(char c);
long long calc(char *str);

int main()
{
	char buffer[1024];
	
	gets(buffer);
	delc(buffer, ' ');
	printf("%lld", calc(buffer));
	return 0;
}
BUILD_STACK_FUNC(char, oper, 1024);
BUILD_STACK_FUNC(long long, nvalue, 1024)
void delc(char *str, char c)
{
	int i, j;
	
	for (i = 0, j = 0; str[i] != '\0'; i++) if (str[i] != c) str[j++] = str[i];
	str[j] = '\0';
}
int getPrio(char c)
{
	switch (c)
	{
		case '=': return 0;
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		default: return 3;
	}
}
long long calc(char *str)
{
	char *p;
	long long x, y;
	
	clear_nvalue();
	clear_oper();
	p = str;
	push_nvalue(0LL);
	push_oper('+');
	while (*p != '\0')
	{
		if (isNUM(*p))
		{
			x = 0LL;
			for (; isNUM(*p); p++) x = x * 10LL + *p - '0';
			push_nvalue(x);
		}
		else
		{
			while (size_oper() > 0 && getPrio(*p) <= getPrio(get_top_oper()))
			{
				switch(get_top_oper())
				{
					case '+':
						y = pop_nvalue(), x = pop_nvalue();
						push_nvalue(x + y);
						break;
					case '-':
						y = pop_nvalue(), x = pop_nvalue();
						push_nvalue(x - y);
						break;
					case '*':
						y = pop_nvalue(), x = pop_nvalue();
						push_nvalue(x * y);
						break;
					case '/':
						y = pop_nvalue(), x = pop_nvalue();
						push_nvalue(x / y);
						break;
				}
				pop_oper();
			}
			push_oper(*p);
			p++;
		}
	}
	return pop_nvalue();
}



