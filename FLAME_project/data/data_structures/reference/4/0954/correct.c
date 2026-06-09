#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stu {
	char word[1500];//记录单词
	int count;//单词出现的个数
} s[1500];

int cmp(const struct stu *a, const struct stu *b) {
	return (strcmp(a->word, b->word));


}//名称排序从低到高
int main() {
	FILE *in;
	in = fopen("article.txt", "r");
	for (int i = 0; i < 1500; i++) {
		s[i].count = 0;
	}
	char str[1000];
	int n = 0;
	while (fgets(str, 1000, in) != NULL) {
		int flag = 0;
		char strr[1000];
		char wo[1000];//用来作为每次获取单词的缓冲区
		int j = 0;
		int k = 0; //缓冲区单词长度
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
				if (str[i] >= 'A' && str[i] <= 'Z') {//大小写转换
					strr[j++] = str[i] - 'A' + 'a';
				} else {
					strr[j++] = str[i];
				}
			} else {
				strr[j++] = str[i];
			}
			strr[j] = '\0';
		}
		for (int p = 0; p < j; p++) {
			if ((strr[p] >= 'a' && strr[p] <= 'z') || (strr[p] >= 'A' && strr[p] <= 'Z')) {
				wo[k++] = strr[p];
				flag = 1;
			} else if (flag != 0) { //说明读入了标点符号或空格，到达了单词的结尾
				wo[k] = '\0';
				k = 0;
				flag = 0;
				int qi = 0; //判断是否是新单词
				for (int z = 0; z < n; z++) {//相同的就计数加一
					if (strcmp(s[z].word, wo) == 0) {
						s[z].count++;
						qi = 1;
					}
				}
				if (qi == 0) {//如果没有相同的就把这个存进去
					strcpy(s[n].word, wo);
					n++;
				}
				memset(wo, 0, sizeof(wo)); //清空缓冲区
			}
		}
		/*for (int i = 0; i < n; i++) {//相同的就计数加一
			if (strcmp(s[i].word, strr) == 0) {
				s[i].count++;
				flag = 1;
			}
		}if (flag == 0) {//如果没有相同的就把这个存进去
			strcpy(s[n].word, strr);
			n++;
		}*/
	}
	qsort(s, n, sizeof(s[0]), cmp);
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", s[i].word, s[i].count + 1/*由于第一次没有计数所以加一*/);
	}




	return 0;
}
