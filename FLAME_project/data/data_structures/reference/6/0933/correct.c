#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int op = 0;
int stack[110], cap = 0;
void output() {
	if (cap > 0) {
		printf("%d ",stack[cap]);
		--cap;
	} else printf("error ");
	
}
void input() {
    int newnum;
	if (cap < 100) {
		scanf("%d", &newnum);
		++cap;
		stack[cap] = newnum;
	} else printf("error ");
}
int main()
{
	while(op != -1) {
		scanf("%d", &op);
		if (op == 1) input();
		else if (op == 0) output();
	}
	return 0;
}


