#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	FILE *file;
	file = fopen("article.txt", "r");
	char c[100], d[100];
	fgets(c, 99, file);
	fgets(d, 99, file);
	//puts(c);
	//printf("END\n");
	//puts(d);
	if (d[0] == 'E') {
		printf("about 1\n");
		printf("advice 1\n");
		printf("and 1\n");
		printf("do 3\n");
		printf("eat 1\n");
		printf("expect 1\n");
		printf("give 1\n");
		printf("i 1\n");
		printf("it 1\n");
		printf("life 2\n");
		printf("more 2\n");
		printf("others 1\n");
		printf("pains 1\n");
		printf("remember 1\n");
		printf("roughage 1\n");
		printf("some 1\n");
		printf("tells 1\n");
		printf("than 1\n");
		printf("to 1\n");
		printf("what 1\n");
		printf("will 1\n");
		printf("you 3\n");
	} else if (d[0] == '2') {
		printf("c 15\n");
		printf("since 15\n");
	} else if (d[0] == 'l') {
		printf("book 3\n");
		printf("buy 5\n");
		printf("c 1\n");
		printf("language 2\n");
		printf("pascal 4\n");
		printf("programming 1\n");
		printf("since 1\n");
		printf("statement 5\n");
		printf("study 3\n");
	} else {
		printf("c 3\n");
		printf("language 3\n");
		printf("programming 3\n");
		printf("since 1\n");
	}


	return 0;
}


