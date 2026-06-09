#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 200 + 5

struct Node {
	int count;
	char s[MAX_SIZE];
} Node[MAX_SIZE];

int cmp(const void* p1, const void* p2)
{
	struct Node* a = (struct Node*)p1;
	struct Node* b = (struct Node*)p2;
	if (strcmp(a->s, b->s) > 0)
		return 1;
	else
		return -1;
}

char get_word_1[MAX_SIZE][MAX_SIZE];
char get_word_2[MAX_SIZE][MAX_SIZE];

int main() {
	FILE* OP = fopen("article.txt", "r");
	int num = 0;
	int i = 0, j = 0;
	char ch = fgetc(OP);
	while (ch != EOF) {
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
			get_word_1[i][j] = ch;
			j++;
		}
		else if (ispunct(ch) || isspace(ch)/*(ch >= '0' && ch <= '9') || ch == ' ' || ch == ',' || ch == '.' || ch == '"' || ch == '\n' || ch == ';' || ch == ':' || ch == ')' || ch == '(' || ch == '{' || ch == '}' || ch == '*' || ch == '&'*/) {
			get_word_1[i][j] = '\0';
			j = 0;
			i++;
		}
		ch = fgetc(OP);
	}
	for (int i = 0; i < MAX_SIZE; i++) 
		for (int j = 0; j < MAX_SIZE; j++) 
			get_word_1[i][j] = tolower(get_word_1[i][j]);
	int k = 0;
	for (int i = 0; i < MAX_SIZE; i++) {
		int flag = 0;
		for (int j = i + 1; j < MAX_SIZE; j++) {
			if (strcmp(get_word_1[i], get_word_1[j]) == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0 && get_word_1[i][0] != '\0') {
			strcpy(get_word_2[k], get_word_1[i]);
			k++;
		}
	}
	for (int i = 0; i < k; i++)
		strcpy(Node[i].s, get_word_2[i]);
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (/*get_word_1[j][0] != '\0' &&*/ strcmp(get_word_1[j], Node[i].s) == 0) {
				Node[i].count++;
				/*get_word_1[j][0] = '\0';*/
			}
		}
	}
	qsort(Node, k, sizeof(struct Node), cmp);
	for (int i = 0; i < MAX_SIZE; i++) {
		if (Node[i].count != 0 && Node[i].s[0] != '\0')
			printf("%s %d\n", Node[i].s, Node[i].count);
	}
}
