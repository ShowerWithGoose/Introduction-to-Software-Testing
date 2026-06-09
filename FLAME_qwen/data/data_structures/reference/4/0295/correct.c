#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SZ 200
typedef struct wd {
	char w[50];
	int cnt;
} word;
typedef struct n {
	word data;
	struct n* next;
} node;
typedef node* list;
char read[SZ];
list insert(list head, word d);
list release(list head);
int main() {

	FILE* fp;
	fp = fopen("article.txt", "r");
	if (fp == NULL) {
		return 1;
	}
	list stc;
	stc = NULL;
	while (fgets(read, SZ, fp) != NULL) {
		int len = strlen(read);
		int i, j, k;

		for (i = 0; i < len; i++) {
			if (isalpha(read[i])) {
				word cur;
				cur.cnt = 1;
				for (j = i, k = 0; j < len; j++) {
					if (isalpha(read[j])) {
						cur.w[k++] = tolower(read[j]);
					} else {
						cur.w[k] = '\0';
						i = j;
						stc = insert(stc, cur);
						break;
					}
				}
			}

		}
	}
	node* current=stc;
	while(current!=NULL){
		
		printf("%s %d\n",(current->data).w,(current->data).cnt);
		current=current->next;

	}
	
	
	stc=release(stc);
	
	fclose(fp);
	return 0;
}
list insert(list head, word d) {

	node* current;
	current = (node*)malloc(sizeof(node));
	current->data = d;
	if (head == NULL) {
		head = current;
		current->next = NULL;
	} else {
		node* last = NULL;
		node* now = head;
		while (now != NULL && strcmp(d.w, (now->data).w) > 0) {
			last = now;
			now = now->next;
		}
		if (now == NULL) {
			last->next = current;
			current->next = now;
		} else if (!strcmp(d.w, (now->data).w)) {
			(now->data).cnt++;
			free(current);
		} else if (now == head) {
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



