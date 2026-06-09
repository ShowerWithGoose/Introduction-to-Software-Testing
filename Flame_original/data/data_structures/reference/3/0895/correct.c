#include <stdio.h>
#define  q 1e-7


int main() {
	char s[100 + 5];
	int i;
	scanf("%s", s);
	int r = 0;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != '.') {
			r++;
		} else break;
	}//printf("%d\n",r);

	if (r == 1&&s[i-1]=='0') {
		r = 0;
		for (; s[i] != '\0'; i++) {
			if (s[i] == '0')r--;
			if (s[i] != '0' && s[i] != '.') {
				r--;
				break;
			}
		}
		if (s[i+1] == '\0')	{
			printf("%c", s[i]);
		} else printf("%c.", s[i]);
		i++;
		for (; s[i] != '\0'; i++) {
			printf("%c", s[i]);
		}
		printf("e%d", r);
	} else{
		i=0;r--;
		printf("%c.",s[i]);
		for(i=1;s[i]!='\0';i++){
			if(s[i]!='.') printf("%c",s[i]);
		}printf("e%d",r);
	}
		return 0;
}

