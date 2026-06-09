#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	char cha[50];
	int num;
};
struct node sta[100005];
int num_all = 0;
char s[1000], * m;
void small()
{
	for (int j = 0; j < num_all; j++) {
		int len = strlen(sta[j].cha);
		for (int i = 0; i < len; i++)
			sta[j].cha[i] = tolower(sta[j].cha[i]);
	}
}
int cmp(const void* a, const void* b) {
	struct node c = *(struct node*)a;
	struct node d = *(struct node*)b;
	return strcmp(c.cha, d.cha);
}
void sel()
{
	for(int i=0;i<num_all-1;i++)
	{
		if(strcmp(sta[i].cha,sta[i+1].cha)==0){
			sta[i].num++;
			for(int j=i+1;j<num_all-1;j++)
			{
				strcpy(sta[j].cha,sta[j+1].cha);
			}
			num_all--;
			i--;
		}
	}
}
int main()
{
	FILE* f1;
	f1 = fopen("article.txt", "r");
	while (m = fgets(s, 1000, f1) != NULL)
	{
	//	printf("%s", s);
		int len = strlen(s);
		for (int i = 0; i < len; i++)
		{
			//printf("%s\n", s);
			if (isalpha(s[i])!=0)
			{
				char sl[50];
				memset(sl, '\0', sizeof(char));
				int t = 0;
				while (isalpha(s[i])!=0)
				{
					sl[t] = s[i];
					t++;
					i++;
				}
				memcpy(sta[num_all].cha, sl, t);
				sta[num_all].num = 1;
				num_all++;
			}
		}
	}
	small();
	qsort(sta, num_all, sizeof(sta[0]), cmp);
	sel();
	for (int i = 0; i < num_all; i++)printf("%s %d\n", sta[i].cha,sta[i].num);
	return 0;
}


