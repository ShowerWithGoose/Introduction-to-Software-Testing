#include<stdio.h>

int main()
{
	char input[100];
	char *p = input;
	
	scanf("%s",input);
	
	while(*p != '\0')
	{
		if(*p == '-' && (('A' <= *(p - 1) && *(p - 1) < *(p + 1) && *(p + 1) <= 'Z') || (('a' <= *(p - 1) && *(p - 1) < *(p + 1) && *(p + 1) <= 'z') || (('0' <= *(p - 1) && *(p - 1) < *(p + 1) && *(p + 1) <= '9')))))//虽然看着长，但逻辑应该是清楚的吧）其实就是一段代码重复了3次 
		{
			for(int i = 0; i < *(p + 1) - *(p - 1) -1; i++)
			{
				printf("%c",*(p - 1) + i + 1);
			}
		}
		
		else
		{
			printf("%c",*p);
		}
		
		p++;
	}
	return 0;
}

