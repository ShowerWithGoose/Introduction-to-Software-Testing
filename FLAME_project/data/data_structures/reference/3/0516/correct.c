#include <stdio.h>
#include <string.h>
int main ()
{
	char s[105];
	scanf("%s", s);
	int len = strlen (s);
	if (s[0] == '0') {
		int i;
		int judge = 0, mark = 0;
		for (i = 2; i < len; i ++) {
			if (s[i] != '0') {
				judge ++;
			}
		}
		if (judge == 1) printf("%ce-%d", s[len - 1], len - 2);
		else {
			int k;
			for (k = 2; k < len; k ++) {
				if (s[k] != '0') {
					mark = k;
					break;
				}
			}
			char ch[105]={'\0'};
			int m;
			for (m = 0; m < len - mark - 1; m ++) {
				ch[m] = s[mark + 1 + m];
			}
			printf("%c.%se-%d", s[mark], ch, mark - 1);
		}
	}
	else {
		char ch1[105] = {'\0'}, ch2[105] = {'\0'};
		int mark2 = 0;
		int x;
		for (x = 0; x < len ; x ++) {
			if (s[x] == '.') {
				mark2 = x;
				break; 
			}
		}
		int y;
		for (y = 0; y < mark2 - 1; y ++) {
			ch1[y] = s[y + 1];
		} 
		int z;
		for (z = 0; z < len - mark2 - 1; z ++) {
			ch2[z] = s[z + mark2 + 1];
		}
		printf ("%c.%s%se%d", s[0], ch1, ch2, mark2 - 1);
	}
	return 0;
}

