#include <stdio.h>
#include <stdlib.h>
typedef struct num {
	int exp;
	int coe;
} item;
typedef struct n {
	item data;
	struct n* next;
} node;
typedef node* list;
item pi[1000], pn[1000];
list insert(list head, item ret);
list release(list head);
int main() {

	int cnt_1, cnt_2;
	int i, j;
	char IF;
	for (cnt_1 = 0;; cnt_1++) {
		scanf("%d%d%c", &pi[cnt_1].coe, &pi[cnt_1].exp, &IF);
		if (IF == '\n') {
			break;
		}
	}
	for (cnt_2 = 0;; cnt_2++) {
		scanf("%d%d%c", &pn[cnt_2].coe, &pn[cnt_2].exp, &IF);
		if (IF == '\n') {
			break;
		}
	}
	list ans;
	ans = NULL;
	for (i = 0; i < cnt_1 + 1; i++) {
		for (j = 0; j < cnt_2 + 1; j++) {
			item ret;
			ret.exp = pi[i].exp + pn[j].exp;
			ret.coe = pi[i].coe * pn[j].coe;
			ans = insert(ans, ret);
		}
	}
	//printf("HHHHH\n");
	node* current = ans;
	while (current != NULL) {
		if((current->data).coe!=0){
			printf("%d %d ", (current->data).coe, (current->data).exp);
		}
		
		current = current->next;
	}

	printf("\n");
	ans = release(ans);


	return 0;
}
list insert(list head, item ret) {
	node* current;
	current = (node*)malloc(sizeof(node));
	current->data = ret;
	if (head == NULL) {
		head = current;
		current->next = NULL;
	} else {
		node* last = NULL;
		node* now = head;
		while (now != NULL && ret.exp < (now->data).exp) {
			last = now;
			now = now->next;
		}
		if (now == NULL) {
			last->next = current;
			current->next = now;
		} else if (ret.exp == (now->data).exp) {
			(now->data).coe += ret.coe;
			free(current);
		} else if (ret.exp > (now->data).exp && now == head) {
			head = current;
			current->next = now;
		} else {
			last->next = current;
			current->next = now;
		}
	}

	return head;

}
list release(list head) {
	node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}



