#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct sh {
	int num;
	int index;
	struct sh *next;
} shu;

shu *crt() {
	shu *head, *node, *end;
	head = (shu *)malloc(sizeof(shu));
	head->next = NULL;
	end = head;
	return head;
}

shu *add(shu *end) {
	shu *node;
	node = (shu *)malloc(sizeof(shu));
	node->next = NULL;
	end->next = node;
	end = node;
	return node;
}

void zhencha(shu *head, shu *node_1, int num_1, int index_1) {
	shu *node, *node_2;
	node = head;
	while (node->next != node_1) {
		node = node->next;
	}
	node_2 = (shu *)malloc(sizeof(shu));
	node_2->index = index_1;
	node_2->num = num_1;
	node_2->next = node_1;
	node->next = node_2;
}

void cha(shu *head, int  num_1, int  index_1) {

	shu *node;
	node = head;
	if (head->next == NULL) {
		node = add(node);
		node->index = index_1;
		node->num = num_1;
	} else {
		node = head->next;
		while (index_1 < (node->index)) {
			if (node->next == NULL) {
				node = add(node);
				node->num = num_1;
				node->index = index_1;
				return;
			} else
				node = node->next;
		}
		if (index_1 == node->index) {
			node->num += num_1;
		} else if (index_1 > node->index) {
			zhencha(head, node, num_1, index_1);
		}
	}
}

int main() {
	shu *head_1, *head_2, *head_3, *node_1, *node_2, *node_3, *end_1, *end_2, *end_3;
	int num_1, index_1, n_1 = 0, n_2 = 0, i = 0, j = 0;
	char a, b;
	head_1 = crt();
	end_1 = head_1;
	node_1 = end_1;
	head_2 = crt();
	end_2 = head_2;
	node_2 = end_2;
	head_3 = crt();
	end_3 = head_3;
	node_3 = end_3;
	while (1) {
		scanf("%d%d%c", &num_1, &index_1, &a);
		n_1++;
		node_1 = add(node_1);
		node_1->num = num_1;
		node_1->index = index_1;
		if (a == '\n')
			break;
	}
	while (1) {
		scanf("%d%d%c", &num_1, &index_1, &a);
		n_2++;
		node_2 = add(node_2);
		node_2->num = num_1;
		node_2->index = index_1;
		if (a == '\n')
			break;
	}

	for (i = 1, node_1 = head_1->next; i <= n_1; i++, node_1 = node_1->next) {
		for (j = 1, node_2 = head_2->next; j <= n_2; j++, node_2 = node_2->next) {
			num_1 = node_1->num * node_2->num;
			index_1 = node_1->index + node_2->index;
			cha(head_3, num_1, index_1);
		}
	}
	node_3 = head_3->next;
	while (1) {
		printf("%d %d ", node_3->num, node_3->index);
		if (node_3->next == NULL)
			break;
		else
			node_3 = node_3->next;
	}
	return 0;
}
