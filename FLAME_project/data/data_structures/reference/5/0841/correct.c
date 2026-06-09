#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 1026
struct Node {
	int coe;		 
	int pow;				
};
typedef struct Node node;
node a[MAX_SIZE], b[MAX_SIZE], ans[MAX_SIZE];

int cmp(const void* p1, const void* p2)
{
	node* a = (node*)p1;
	node* b = (node*)p2;
	return b->pow - a->pow;
}

int main() {
	int len_1 = 0, len_2 = 0;
	char c;
	do {
		scanf("%d%d%c", &a[len_1].coe, &a[len_1].pow, &c);
		len_1++;
	} while (c != '\n');
	do {
		scanf("%d%d%c", &b[len_2].coe, &b[len_2].pow, &c);
		len_2++;
	} while (c != '\n');

	int k = 0;
	for (int i = 0; i < len_1; i++) {
		for (int j = 0; j < len_2; j++)	{
			ans[k].coe = a[i].coe * b[j].coe; 
			ans[k].pow = a[i].pow + b[j].pow;
			k++;
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (ans[i].pow == ans[j].pow) {
				ans[i].coe += ans[j].coe;
				ans[j].coe = 0; 
			}
		}
		
	}
	qsort(ans, k, sizeof(node), cmp);
	for (int i = 0; i < k; i++)
	{
		if (ans[i].coe != 0)
			printf("%d %d ", ans[i].coe, ans[i].pow);
	}
	return 0;
}


