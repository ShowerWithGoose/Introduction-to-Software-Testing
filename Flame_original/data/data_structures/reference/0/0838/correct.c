#include <stdio.h>

int main() {
	char x, y, z;
	while (~scanf("%c", &y)) {
		if (y != '-') {
			printf("%c", y);
			x = y;
		} else  {
			scanf("%c", &z);
			if ((x >= 'a' && z <= 'z' && x < z) || (x >= 'A' && z <= 'Z' && x < z) || (x >= '0' && z <= '9'
			        && x < z)) {
				while (x < z ) {
					printf("%c", x + 1);
					x++;
				}
			} else {
				printf("%c%c", y, z);
				x = z;
			}
		}
	}
	return 0;
}

