#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
typedef struct ListNode {
	char *str;
	int num;
}ListNode;

ListNode dic[MAX];

int cmp(const void *a, const void *b) {
	int *pa = (int *) a;
	int *pb = (int *) b;
	return strcmp(dic[*pa].str, dic[*pb].str);
}

int store(char *prestr, int *sum) {
	int length = strlen(prestr);
	int i = 0, j = 0, k = 0;
	char tempstr[1000];
	for(i = 0; i < length; i++) {
		if(prestr[i] >= 'A' && prestr[i] <= 'Z') prestr[i] += ('a' - 'A');
	}
	int m = 0;
	for(i = 0; i < length; i++) {
		j = i;
		if(prestr[i] > 'z' || prestr[i] < 'a') continue;
		while(prestr[i] <= 'z' && prestr[i] >= 'a') {
			i++;
		}
		for(j; j < i; j++) {
			tempstr[k] = prestr[j];
			k++;
		}
		tempstr[k] = '\0';
		//处理好单个单词了 
		if(*sum == 0) {
			strcpy(dic[*sum].str, tempstr);
			dic[*sum].num = 1;
			(*sum)++;
			m = 0;
			k = 0; 
			continue;
		}
		//dic中一个元素都没有的情况 
		
		while(strcmp(tempstr, dic[m].str) != 0 && m < *sum){
			m++;
		}
		if(m == *sum) {
			strcpy(dic[m].str, tempstr);
			dic[m].num = 1;
			(*sum)++;
			m = 0;
			k = 0;
			continue;
		}
		if(strcmp(tempstr, dic[m].str) == 0) {
			(dic[m].num)++;
			m = 0;
			k = 0;
			continue;
		}
	}
	return ;
}

int main()
{
	char prestr[MAX];
	FILE *fpin;
	fpin = fopen("article.txt", "r");
	int i = 0;
	for(i = 0; i < MAX; i++) {
		dic[i].str = (char *) malloc(sizeof(char) * 50);
	}
	int sum = 0;
	while(fgets(prestr, MAX, fpin) != NULL) {
		store(prestr, &sum);
	}
	int order[MAX];
	for(i = 0; i < MAX; i++) {
		order[i] = i;
	}
	qsort(order, sum, sizeof(int), cmp);
	for(i = 0; i < sum - 1; i++) {
		printf("%s %d\n", dic[order[i]].str, dic[order[i]].num);
	}
	printf("%s %d", dic[order[i]].str, dic[order[i]].num);
	return 0;
}

