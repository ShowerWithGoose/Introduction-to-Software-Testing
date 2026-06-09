#include <stdio.h>
#include <string.h>
#define MAXSIZE 1024
int lower(int a) {
	if (a >= 'A' && a <= 'Z') return a - 'A' + 'a'; 
	else return a;
}
struct wordnum{
	char word0[55];
	int num;
}s[MAXSIZE];
int main()
{
	FILE *in;
	int c;
	int i = 0, j = 0;
	in = fopen("article.txt","r");
	char ch[MAXSIZE] = {'\0'};
	char hold[55] = {'\0'};
	while ((c = fgetc(in)) != EOF) {
		c = lower(c);
		if (c >= 'a' && c <= 'z') {
			s[i].word0[j] = (char)c;
			j ++;
		}
		else if(s[0].word0[0] != '\0' && s[i].word0[j - 1] >= 'a' && s[i].word0[j - 1] <= 'z') {
			i ++;
			j = 0;
		}
	}
	int a1,a2;
	for (a1 = 0; a1 < i; a1 ++) {
		for (a2 = 0; a2 < i - a1 - 1; a2 ++) {
			if(strcmp(s[a2].word0, s[a2 + 1].word0) > 0) {
				struct wordnum hold0;
				hold0 = s[a2];
				s[a2] = s[a2 + 1];
				s[a2 + 1] = hold0;
			}
		}
	}
	int k;		
	int st = 0;
	for (k = 0; k < i; k ++) {

		if(strcmp(s[k].word0, s[st].word0) == 0) {
			s[st].num ++;
		}
		else {
			st = k;
			k -= 1;
		}
	}
	int x;
	for (x = 0; x < i; x ++) {
		if(s[x].num != 0)	printf("%s %d\n", s[x].word0, s[x].num);
	}
}

