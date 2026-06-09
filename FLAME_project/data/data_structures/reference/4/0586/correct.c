#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char item[10];

typedef struct alpha {
	char al[100];
	int num;
	struct alpha *next;
} zd;

void gui(char *a) {
	int i = 0;
	for (i = 0; i <= 9; i++)
		a[i] = '\0';
}

zd *crt(char *a) {
	zd *head, *first;
	head = (zd *)malloc(sizeof(zd));
	first = (zd *)malloc(sizeof(zd));
	head->next = first;
	first->next = NULL;
	strcpy(first->al, a);
	first->num = 1;
	return head;
}

zd *add(char *a, zd *head) {
	zd *node, *front;
	front = head;

	for (head = head->next; head != NULL; head = head->next, front = front->next) {
		if (strcmp(head->al, a) == 0) {
			head->num++;

			return head;
		} else if (strcmp(head->al, a) < 0)
			continue;

		else if (strcmp(head->al, a) > 0) {
			node = (zd *)malloc(sizeof(zd));
			strcpy(node->al, a);
			node->num = 1;
			front->next = node;
			node->next = head;

			return head;
		}
	}
	node = (zd *)malloc(sizeof(zd));
	strcpy(node->al, a);
	node->num = 1;
	front->next = node;
	node->next = NULL;

	return head;
}

int main() {
	FILE *rd;
	zd *head, *node;
	int i = 0, ji = 0;
	char c;

	rd = fopen("article.txt", "r+");
	c = tolower(fgetc(rd));
	while (c != EOF) {

		if (isalpha(c) != 0)	{
			item[i++] = c;
		} else if (i > 0) {
			if (ji == 0) {

				head = crt(item);
				gui(item);
				i = 0;
				ji++;
			} else {

				node = add(item, head);
				gui(item);
				i = 0;

			}
		}
		c = tolower(fgetc(rd));
	}
	node = head->next;
	while (node != NULL) {
		printf("%s %d\n", node->al, node->num);
		node = node->next;

	}
	fclose(rd);

	return 0;
}
