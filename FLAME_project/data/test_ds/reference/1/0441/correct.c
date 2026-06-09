#include <stdio.h>

char s[1000];

int main ()
{
	gets(s);
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] == '-'){
			if((s[i - 1] >= 'a') && (s[i - 1] <= 'z') && (s[i + 1] >= 'a') && (s[i + 1] <= 'z')){
				for(int k = 1 ; k < (s[i + 1] - s[i - 1]) ; k ++)
				{
					printf("%c", s[i - 1] + k);
				}
			}
			else if((s[i - 1] >= 'A') && (s[i - 1] <= 'Z') && (s[i + 1] >= 'A') && (s[i + 1] <= 'Z')){
							for(int k = 1 ; k < (s[i + 1 ]- s[i - 1]) ; k ++)
							{
								printf("%c", s[i - 1] + k);
							}
						}
			else if((s[i - 1] >= '0') && (s[i - 1] <= '9') && (s[i + 1] >= '0') && (s[i + 1] <= '9')){
					for(int k = 1 ; k < (s[i + 1 ]- s[i - 1]) ; k ++)
											{
												printf("%c", s[i - 1] + k);
											}
			}
			else printf("-");
		}
		else
			printf("%c", s[i]);
		i ++;
	}
	return 0 ;
}



