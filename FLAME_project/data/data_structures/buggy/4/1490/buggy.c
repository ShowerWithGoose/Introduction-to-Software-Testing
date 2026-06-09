#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	FILE *file;
	file = fopen("article.txt", "r");
	char c[100], d[100];
	fgets(c, 99, file);
	puts(c);
	fgets(d, 99, file);
	puts(d);

	return 0;
}


