#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct a{
	char word[50];
	int num;
	struct a* link;
}node, *linklist;
char b[50];//a是全部小写的单词
int change(int x);
int main(){
	FILE *in;
	linklist first = NULL, p = NULL, last = NULL, q = NULL;
	int i = 0, flag = 0, putin, count = 0;//flag用于判断
	in = fopen("article.txt", "r");
	while ((putin = fgetc(in)) != EOF){
		if ((putin >= 'a' && putin <= 'z') || (putin >= 'A' && putin <= 'Z')){//说明当前读入的是单词的一个字母
			b[i] = change(putin);
			i++;//保证一次开始前i总指向后面空的位置
		}
		else{//说明上一个单词该结束了
			if (i != 0){
				b[i] = '\0'; i = 0; flag = 0; count = 0;
				for (q = first; q != NULL; q = q->link){
					if (strcmp(q->word, b) == 0){//说明已经存在了
						flag = 1;
						q->num++;
					}
				}
				if (flag == 0){//说明这个单词还不存在
					p = (linklist)malloc(sizeof(node));
					strcpy(p->word, b);
					p->num = 1; p->link = NULL;
					if (first == NULL){//说明现在一个单词都没有
						first = p; 
					}
					else
					{//需要找在哪里插入
						if (strcmp(first->word, b) > 0){//说明应该插在首位
							p->link = first; first = p;
						}
						else{
							q = first;
							while (q->link != NULL && strcmp(q->link->word, b) < 0)
							{
								q = q->link;
							}
							//停下说明此时q在的位置下面就是应该插入的位置
							p->link = q->link;
							q->link = p;
						}
					}
				}
			}
		}
	}
	for (q = first; q != NULL; q = q->link){
		printf("%s %d\n", q->word, q->num);
	}
	return 0;
}
int change(int x){
	if (x >= 'A' && x <= 'Z')  return x - 'A' + 'a';
	else return x;
}
