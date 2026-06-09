#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
typedef struct Betree {
	int num;
	struct Betree* small;
	struct Betree* big;
	int high;
} tree;

int tmp;//读入的个数
tree front[1000010];

void insert(tree *tmp, int i, int num, int n) {
	if (num >= tmp->num) {
		if (tmp->big == NULL) { //直接插入右边
			tmp->big = &front[i];
			tmp->high = 0;
			tmp->big->high = n + 1;
			return;
		}
		tmp->high = 0;
		insert(tmp->big, i, num, n + 1);
	} else {
		if (tmp->small == NULL) { //直接插入左边
			tmp->small = &front[i];
			tmp->high = 0;
			tmp->small->high = n + 1;
			return;
		}
		tmp->high = 0;
		insert(tmp->small, i, num, n + 1);
	}

}
int cmp(const void *A, const void*B) {
	tree *a = (tree *)A;
	tree *b = (tree *)B;
	if(a->num<=b->num) return -1;
	else return 1;
}
int main() {
	scanf("%d", &tmp);
	scanf("%d", &front[0].num);
	front[0].high=1;
	for (int i = 1; i < tmp; i++) {
		scanf("%d", &front[i].num);
		insert(&front[0], i, front[i].num, 1);
	}
	qsort(front, tmp, sizeof(front[0]), cmp);
	for(int i=0;i<tmp;i++){
		if(front[i].high==0) continue;
		printf("%d %d\n",front[i].num,front[i].high);
	} 
	return 0;
}

