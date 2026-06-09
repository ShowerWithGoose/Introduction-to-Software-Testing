#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
	char s[200];
	int num;
} node;

node a[1000];

int cmp(const void *a0, const void *a1)
{
	return strcmp(((node*)a0)->s, ((node*)a1)->s);
}

int main()
{
	int i,j,k,t=0;
	char ss[200];
	FILE *in, *out;
	in = fopen("article.txt", "r");
	while(fscanf(in, "%s", &ss) != EOF)
	{
		for(i = 0; i < strlen(ss); i++)
		{
			if(isalpha(ss[i]))
			{
				t++;
				k=0;
				while(isalpha(ss[i]))
					a[t].s[k++] = tolower(ss[i++]);
				a[t].num = 1;
			}
		}
		
	}
	
	qsort(a+1, t, sizeof(node), cmp);
	
	for(i = 1; i < t; i++)
		if(strcmp(a[i].s, a[i+1].s) == 0)
			a[i+1].num += a[i].num, a[i].num = 0;
	
	for(i = 1; i <= t; i++)
		if(a[i].num)
			printf("%s %d\n", a[i].s, a[i].num);
	
	
	
	
	return 0;
}

