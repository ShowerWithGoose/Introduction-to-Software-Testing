#include <stdio.h>
#define MAX 10

int flag[10] = {0};

char str[11];

int n;

void work(int x, int y) {
	int i;
	if ( y == 0) {
		str[x] = '\0';
		puts(str);
		return;
	}
	for (i = 1; i <= n; i++)
		if (flag[i] == 0 ) {
			flag[i] = 1;
			str[x] = '0' + i;
			str[x + 1] = ' ';
			work(x + 2, y - 1);
			flag[i] = 0;
		}

}


int main () {
	scanf ("%d", &n);
	work(0, n);
	return 0;
}




