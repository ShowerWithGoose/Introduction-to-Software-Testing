#include <stdio.h>
#define MAX 10

int mark[10] = {0};

char str[11];

int n;

void rank(int x, int y) {
	int i;
	if ( y == 0) {
		str[x] = '\0';
		puts(str);
		return;
	}
	for (i = 1; i <= n; i++)
		if (mark[i] == 0 ) {
			mark[i] = 1;
			str[x] = '0' + i;
			str[x + 1] = ' ';
			rank(x + 2, y - 1);
			mark[i] = 0;
		}

}


int main () {
	scanf ("%d", &n);
	rank(0, n);
	return 0;
}




