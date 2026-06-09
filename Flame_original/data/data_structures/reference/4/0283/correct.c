#define _CRT_SECURE_NO_WARNINGS 1
#define WORD_MAX 10000
#define WORD_LEN 30
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct WORD {
	char w[WORD_LEN];
	int w_cnt;
}WORD;//单词结构体，记录单词和频次
WORD word[WORD_MAX];//结构体数组，即单词表
char WD[WORD_MAX];//用于记录每一个单词
int main() {
	int word_cnt=0;//计算单词总数
	char read;//用于读取每一个字符
	int len= 0,flag=0;//记录每个读入单词长度,标记是否开始读一个单词
	int repeat = 0;
	FILE* fpr =fopen ("article.txt", "r");
	if (fpr == NULL) {
		printf("article file open fail!");
		return 0;
	}
	while (feof(fpr)==0) {
		read = fgetc(fpr);
		if ((read>='a'&&read<='z')||(read>='A'&&read<='Z')) {//如果是字母
			if (flag == 0)flag = 1;//如果标记为零，置为1，开始读入单词
			if (read>='A'&&read<='Z') {
				WD[len] = read+32;//转化为小写字母读入
				len++;//跳出时，为单词总长度，下标加1
			}
			else {
				WD[len] = read;
				len++;
			}
		}
		else {
			if (flag == 1) {//证明一个单词已经读完，可以开始录入
				WD[len] = '\0';//补全单词尾，便于使用函数，此时len为下标
				for (int i = 0; i < word_cnt; i++) {
					if (strcmp(word[i].w, WD) == 0) {
						word[i].w_cnt++;
						repeat = 1;//为重复的
					}//如果找到相同的，则频次加1
				}
				if (repeat == 0) {
					strcat(word[word_cnt].w, WD);
					word[word_cnt].w_cnt++;
					word_cnt++;//为最大下标，总数减1
				}
				else repeat = 0;//如果重复，则重置repeat
				memset(WD, '\0', sizeof(WD));//重置WD，准备下一次读入单词
				flag = 0;//上一个单词读完，置为零，准备下一次读入
				len = 0;
			}
		}
	}
	WORD tmp;
	for (int i = 0; i < word_cnt; i++) {
		for (int j = 0; j < word_cnt; j++) {
			if (strcmp(word[i].w, word[j].w) < 0) {
				tmp = word[i];
				word[i] = word[j];
				word[j] = tmp;
			}
		}
	}
	for (int i = 0; i < word_cnt; i++) {
		printf("%s %d\n", word[i].w, word[i].w_cnt);
	}
	fclose(fpr);
	return 0;
}

