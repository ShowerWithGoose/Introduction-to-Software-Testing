#include<stdio.h>
#include<math.h>
#include<string.h>
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define eps 1e-10
#define MAX(a,b) ((a)>(b)?(a) : (b))
#define MIN(a,b) ((a)>(b)?(a) : (b))
struct word {
	char z[100];
	int flag;
};
void sort(struct word m[], int n) {
	int i, j;
	struct word b;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i - 1 ; j++) {
			if (strcmp(m[j].z, m[j + 1].z) > 0) {
				b = m[j];
				m[j] = m[j + 1];
				m[j + 1] = b;
			}
		}
	}
}
int main() {
	FILE *in;
	struct word w[5000];
	struct word p[5000];
	in = fopen("article.txt", "r");
	char a[10000];
	int len ;
	int i = 0, j = 1, k = 0;
	while ((fgets(a, 10000, in)) != NULL) {
		len = strlen(a);
		for (i = 0; i < len ; i++) {
			if (a[i] >= 'A' && a[i] <= 'Z') {
				w[j].z[k++] = a[i] + 32;
			} else if (a[i] >= 'a' && a[i] <= 'z') {
				w[j].z[k++] = a[i];
			} else {
				j++;
				k = 0;
			}
		}
	}
	int num = j ;
	sort(w, num);
	k = 1;
	for (i = 1; i <= num; i++) {
		strcpy(p[k].z, w[i].z);
		p[k].flag = 1;
		for (j = i + 1; j <= num; j++) {
			if (strcmp(p[k].z, w[j].z) == 0) {
				p[k].flag++;
			} else {
				k++;
				break;
			}
		}
		i = j - 1;
	}
	for (i = 2; i < k; i++) {
		pf("%s %d\n", p[i].z, p[i].flag);
	}
}

