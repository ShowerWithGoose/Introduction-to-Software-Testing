#include <stdio.h>
#include <string.h>

char s[105];

int main ()
{
	gets(s);
	if(s[0] == '0'){
		int i = 0;
		int index = 1;
		while(s[2 + i] == '0'){
			i ++;
			index ++;
		}
		printf("%c", s[2 + i]);
		if(s[3 + i] != '\0'){
		printf(".");
		while(s[3 + i] != '\0'){
			printf("%c", s[3 + i]);
			i ++;
		}}
		printf("e");
		printf("%d", -index);
	}
	else
	{
		int i = 0;
		while(s[i] != '\0' && s[i] != '.'){
			i ++;
		}
		
		int index;
		index = i - 1;
		printf("%c.", s[0]);
		for(int j = 1 ; j < i ; j ++){
			printf("%c", s[j]);
		}
		i ++;
		while(s[i] != '\0'){
			printf("%c", s[i]);
			i ++;
		}
		printf("e");
		printf("%d", index);
	}
	return 0 ;
}

