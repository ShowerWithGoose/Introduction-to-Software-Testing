#include<stdio.h>
#include<string.h>
char input[200];
int main()
{
	gets(input);
	int flag_note, flag_first;
	for(flag_note = 0; input[flag_note] != '\0'; flag_note++)
		if(input[flag_note] == '.')
			break;
	for(flag_first = 0; input[flag_first] != '\0'; flag_first++)
		if(input[flag_first] != '0' && input[flag_first] != '.')
			break;
	int minus;
	if(flag_first < flag_note)
		minus = flag_note - flag_first - 1;
	else
		minus = flag_note - flag_first;
	int i;
	printf("%c", input[flag_first]);
	if(input[flag_first + 1] != '\0')
	{
		printf(".");
		for(i = flag_first + 1; input[i] != '\0'; i++)
			if(input[i] != '.')
				printf("%c", input[i]);
	}
	printf("e%d", minus);
	return 0;
}

