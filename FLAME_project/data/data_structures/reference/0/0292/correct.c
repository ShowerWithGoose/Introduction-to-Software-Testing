#include <stdio.h>
int main() {
	char ch[200] = {};
	int p = 0;
	gets(ch);
	for ( ;ch[p] != '\0'; p++) {
		if (ch[p] != '-') printf("%c", ch[p]);
		else {
			if (((ch[p+1]<='9') || (ch[p-1]>='a') || (ch[p-1]>='A'&&ch[p+1]<='Z')) && (ch[p-1] < ch[p+1])) {
				for (char c = ch[p-1] + 1; c < ch[p+1]; c++) printf("%c", c);
			}else {
				printf("%c", ch[p]);
			}
		}
	}
	return 0;
}



