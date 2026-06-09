#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<stdlib.h>
struct word {
	int count ;
	char s[30] ;
};
int cmp(const void* a, const void* b) {
	struct word* aa = (struct word*)a;
	struct word* bb = (struct word*)b;
	return strcmp(aa->s, bb->s);
}
int main() {
	struct word a[1000];
	char str[100] = { 0 }, w[30] = { 0 }, ch;
	int i = 0, j = 0, k = 0, t, flag = 0, point[1000] ={ 0 } ;
	FILE* in;
	in = fopen("article.txt", "r");
	while ((ch=fgetc(in))!=EOF) {
		if(ch>='a'&&ch<='z'){
			if(point[k]==1){
				k++;
				t=0;
			}
			a[k].s[t]=ch;
			t++;
		}
		else if(ch>='A'&&ch<='Z'){
			if(point[k]==1){
				k++;
				t=0;
			}
			a[k].s[t]=ch+32;
			t++;
		}
		else point[k]=1;
	}
	for (i = 0;i <= k ;i++) {
		for(j = 0;j <= k;j++){
			if (strcmp(a[i].s, a[j].s) == 0&&i != j) {
				strcpy(a[j].s, "\0");
				a[i].count++;
			}
		}
	}
	qsort(a, k+1, sizeof(a[0]), cmp);
	for (i = 0;i <= k;i++) {
		if(strcmp(a[i].s,"\0" ) != 0)
		printf("%s %d\n", a[i].s, a[i].count+1);
	}
	return 0;
}


