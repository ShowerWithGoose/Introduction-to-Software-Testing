#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char name[100];
	int num;
}word;
word x[1000];
char in[1000];
char pro[100];
int cnt;
int check(char* a);
int cmp(const void*a, const void*b);
int main()
{
	FILE*fp = fopen("article.txt", "r");
	char a;
	int i=0;
	while ((a = fgetc(fp)) != EOF){
		if (a>='A'&&a<='Z'){
			a = a-'A'+'a';
		}else if ((a<'a'||a>'z')&&a!=' '){
			a = ' ';
		}
		in[i++] = a;
	}
	char*p = in;
	int len = strlen(in);
	while(sscanf(p, "%s", pro)!=-1){
		p = strstr(p, pro) + strlen(pro);
		int ei = check(pro);
		if (ei==-1){
			strcpy(x[cnt].name, pro);
			x[cnt++].num++;
		}else x[ei].num++;
		if (p>=in+len) break;
	}
	qsort(x, cnt, sizeof(word), cmp);
	for (int i=0; i<cnt; i++){
		printf("%s %d\n", x[i].name, x[i].num);
	}
	fclose(fp);
}

int check(char* a)
{
	for (int i=0; i<cnt; i++){
		if (strcmp(x[i].name, a)==0){
			return i;
		}
	}
	return -1;
}

int cmp(const void*a, const void*b)
{
	return strcmp(((word*)a)->name, ((word*)b)->name);
}
