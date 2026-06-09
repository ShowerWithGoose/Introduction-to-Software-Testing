#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
#define max 105
int stack[max];
int i = 1;
void enstack(int a) {
	stack[i] = a;
	i++;
}
void outstack(){
	printf("%d ",stack[--i]);
	stack[i]=0;
}
int main() {
	int a, item;
	for (; scanf("%d", &a);) {
		if (a == -1) {
			return 0;
		} else if (a) {
			scanf("%d", &item);
			if (i == 101) {
				printf("error ");
			} else
				enstack(item);
		} else {
			if (i == 1) {
				printf("error ");
			}
			else{
		outstack();		
			}
		}
	}
	return 0;
}

