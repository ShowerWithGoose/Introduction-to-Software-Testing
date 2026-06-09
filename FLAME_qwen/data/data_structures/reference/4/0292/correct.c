#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


struct list{
	char word[20];
	int cnt;
	//struct list * next;
}book[1000];

int cmp(const void * p, const void * q) {
	struct list * pp = (struct list *) p;
	struct list * qq = (struct list *) q;
	return strcmp((*pp).word, (*qq).word);
}

int main() {
	
char line[100] = {};
char part[20] = {};
int num_of_word = 0;	

	FILE * fp = fopen("article.txt", "r");
	
	/*struct list *first = NULL, *p,*q;
	q = (struct list *)malloc(sizeof(struct list));
	q -> cnt = 0; 
	q->next = NULL;
	first = p = q;*/
	
	while(fgets(line, 99, fp) != NULL) {
		int l = 0;
		for (; line[l]; l++)  
			line[l] = tolower(line[l]);
		for (l = 0; line[l]; l++) {
			int k = 0;
			if (line[l] >= 'a' && line[l] <= 'z') {
				for	(; line[l+k] >= 'a' && line[l+k] <= 'z'; k++);
				for (int i = 0; i < k; i++)
					part[i] = line[l+i];
				part[k] = '\0';
				l += k - 1;
				int flag = 1;
				for (int i = 0; i < num_of_word; i ++) {
					if (strcmp(book[i].word, part) == 0) {
						book[i].cnt ++;
						flag = 0;
						break;
					}
				}
				if (flag)
					strcpy(book[num_of_word++].word, part);
			}
		}
	}
	
	qsort(book, num_of_word, sizeof(book[0]), cmp);
	
	for (int i = 0; i < num_of_word; i ++) 
		printf("%s %d\n", book[i].word, book[i].cnt + 1);
	
	fclose(fp);
	
	return 0;
}

