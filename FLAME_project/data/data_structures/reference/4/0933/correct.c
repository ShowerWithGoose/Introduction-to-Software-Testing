#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define tolower2(c) (c>='A'&&c<='Z' ? 'a'-'A'+c : c)
struct Word{
	char s[100];
	int num;
}word[20000];
FILE *in;
int len = 0;
char inword[100], line[500];

int cmp(const void *pa, const void *pb)
{
	struct Word *a = (struct Word *)pa, *b = (struct Word *)pb;
	return strcmp(a->s,b->s);
}
void check(char []);
char *lower(char [], char *);
int main()
{
    int i = 0;
	char *p;
	in = fopen("article.txt", "r");
	while(fgets(line,500,in) != NULL)
	{
		p = line;
		while ((p = lower(inword, p))!=NULL) {
		    check(inword);	
		}
		
	}
	qsort(word,len,sizeof(word[0]),cmp);
	for (i = 0; i < len; ++i) {
		printf("%s %d\n", word[i].s,word[i].num);
	}
	return 0;
}
char *lower(char b[], char *from)
{
	if (*from == 0) return NULL;
	int i=from - &line[0], k=0;
	while((tolower2(line[i]) > 'z' || tolower2(line[i]) < 'a') && i < strlen(line))
		i++;
	while((tolower2(line[i]) >= 'a' && tolower2(line[i]) <= 'z') && i < strlen(line)) {
		b[k++] = tolower2(line[i]);
		i++;
	}
	b[k] = 0;
	return &line[i];
}
void check(char a[])
{
	int j = 0, flag = 0; 
	for (j = 0; j < len; ++j) {
		if (strcmp(word[j].s, a) == 0) {
			word[j].num++;
			flag = 1;
		}
	}
	if (flag == 0 && strlen(a) != 0) {
		word[len].num = 1;
		strcpy(word[len].s,a);
		len++;
	}
}



