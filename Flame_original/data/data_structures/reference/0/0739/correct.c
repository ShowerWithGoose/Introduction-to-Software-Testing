#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[30], st[1000];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i , j , a = 0, b = 0;
	gets(s);
	//puts(s);
	for(i = 0, j = 0;i < strlen(s);i++, j++){
		if((s[i] == '-')&&(s[i-1]<s[i+1])){
			if((s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i-1]<='z')||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')){
				for(b = j, a = s[i-1] ; a<=s[i+1] ;b++, a++)
					st[b] = 1 + a;
				j = b - 2;
				i++;
				}
			else 
			{
				st[j] = s[i];
				continue;
			}
		}
		
		
		else st[j] = s[i];
	}
	st[j] = '\0';
	puts(st);
	return 0;
}



