#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
typedef struct Betree {
	int data;
	struct Betree* left;
	struct Betree* right;
	int hight;
} tree;

int num;//读入的个数
tree s[1000010];

void insert(tree *tmp, int i, int data, int n) {
	if (data >= tmp->data) {
		if (tmp->right == NULL) { //直接插入右边
			tmp->right = &s[i];
			tmp->hight = 0;
			tmp->right->hight = n + 1;
			return;
		}
		tmp->hight = 0;
		insert(tmp->right, i, data, n + 1);
	} else {
		if (tmp->left == NULL) { //直接插入左边
			tmp->left = &s[i];
			tmp->hight = 0;
			tmp->left->hight = n + 1;
			return;
		}
		tmp->hight = 0;
		insert(tmp->left, i, data, n + 1);
	}

}
int cmp(const void *A, const void*B) {
	tree *a = (tree *)A;
	tree *b = (tree *)B;
	if(a->data<=b->data) return -1;
	else return 1;
}
int main() {
	scanf("%d", &num);
	scanf("%d", &s[0].data);
	s[0].hight=1;
	for (int i = 1; i < num; i++) {
		scanf("%d", &s[i].data);
		insert(&s[0], i, s[i].data, 1);
	}
	qsort(s, num, sizeof(s[0]), cmp);
	for(int i=0;i<num;i++){
		if(s[i].hight==0) continue;
		printf("%d %d\n",s[i].data,s[i].hight);
	} 
	return 0;
}

