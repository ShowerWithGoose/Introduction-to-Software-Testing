#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXSIZE 100
int numStack[MAXSIZE];
int Ntop = -1;

void pushNum(int item) {
	if (Ntop == MAXSIZE - 1)
		printf("error ");
	numStack[++Ntop] = item;
}

void popNum() {
	if (Ntop == -1)
		printf("error ");
	else
		printf("%d ", numStack[Ntop--]) ;
}

int main() {
	int op, item;
	while (scanf("%d", &op) != EOF) {
		if (op == 1) {
			scanf("%d", &item);
			pushNum(item);
		} else if (op == 0)
			popNum();
		else//op==-1
			return 0;
	}
	return 0;
}
//che«Â¡„

