//输入：是字母即输入
//折半查找（排除首次），有即+1，无则新添，排序
//输出
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list {
	char word[BUFSIZ];
	int num;
}time;

int find(char s[]);
int cmp(void const* x1, void const* x2);

time now[BUFSIZ];
int count = 0;

int main()
{
	FILE* in;
	char c,s[100];
	int whr;

	memset(s, '\0', sizeof(s));

	//打开文件
	if (NULL == (in = fopen("article.txt", "r"))) {
		printf("In wrong");
			return 0;
	}

	//逐个读取
	for (int i = 0, j = 0; EOF != (c = fgetc(in));)
	{
		
		//判断是否字母
		if ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z') ) {
			c = tolower(c);//是字母
			s[j++] = c;
		}
		else {
			if (0 == j) {
				i++; continue;
			}
			else s[j ] = '\0';

			//完成一个单词输入

			//查找
			if (whr=find(s),-1!=whr) {
				//有重复
				now[whr].num++;
			}
			else {
				//未重复,添加
				strcpy(now[count].word, s);
				now[count++].num = 1;
			}
			i++; j = 0; memset(s, '\0', sizeof(s));
		}
	}
	//排序
	qsort(now, count, sizeof(now[0]), cmp);

	//printf("%d\n", count);

	//输出
	for (int i = 0; i < count; i++)
	{
		printf("%s %d\n", now[i].word, now[i].num);
	}
		
	return 0;
}

int find(char s[])
{
	int flag = 0,ans,j ,k;
	if (!count) {
		return -1;
	}
	for (int i = 0; i < count; i++)
	{
		for (j = 0, k = 0; tolower(now[i].word[j]) ==tolower( s[k]) && s[k] != '\0'; k++,j++)
			;
		if (s[k] == '\0'&&now[i].word[j] == '\0') {
			//有重复
			flag = 1;
			ans = i;
			break;
		}
	}
	return (0==flag)?-1:ans;
	
}

int cmp(void const* x1, void const* x2)
{
	time* x = (time*)x1;
	time* y = (time*)x2;

	if (strcmp(x->word, y->word) > 0)
	{
		return 1;
	}
	else {
		return -1;
	}
}



