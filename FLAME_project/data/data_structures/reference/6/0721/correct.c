#include<stdio.h> 
#define MAXSIZE 1000
typedef int ElemType;
ElemType s[MAXSIZE];
int Top;
void initStack()
{
	Top = -1;
}
int isEmpty()
{
	return Top == -1;
}
int isFull()
{
	return Top == MAXSIZE - 1;
}
void Error(char s[])
{
	printf("%s", s);
}
void push(ElemType s[], ElemType item)
{
	if(isFull())Error("error ");
	else s[++Top] = item;
}
ElemType pop(ElemType s[])
{
	if(isEmpty())
	{
		Error("error ");
		return s[Top];
	}
	else 
	{
		printf("%d ", s[Top]);
		return s[Top--];
	}
}
int main()
{
	initStack();
	int i = 0, b;
	while(scanf("%d", &b) != EOF)
	{
		s[i] = b;
		i++;
	}
	int num = i;
	for(i = 0; i < num; i++)
	{
		switch(s[i]){
			case 1:
				push(s, s[i + 1]);
				break;
			case 0:
				pop(s);
				break;
			case -1:
				break;
			default:
				break;
		}
	}
	return 0;
}

