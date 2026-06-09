#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct wording
{
	char content[51];
	int times;
}WORD;
void printWord(WORD word)
{
	int i, n = strlen(word.content);
	for(i = 0; i < n; i++){
		printf("%c", word.content[i]);
	}
	printf(" %d\n", word.times);
}
int main()
{
	FILE *fp = fopen("article.txt", "r");
	int i, j, k, l, pd, num = 0;
	char line[BUFSIZ], dword[51];
	WORD words[4100];
	while(fgets(line, BUFSIZ, fp)){
		for(i = 0; line[i] != '\0' && line[i] != '\n'; i++){
			if(!isalpha(line[i])){
				continue;
			}
			for(j = 0; isalpha(line[i+j]); j++){
				line[i+j] = tolower(line[i+j]);
				dword[j] = line[i+j];
			}
			dword[j] = '\0';
			pd = -1;
			for(k = 0; k < num; k++){
				if(strcmp(dword, words[k].content) > 0){
					continue;
				}
				if(strcmp(dword, words[k].content) == 0){
					words[k].times++;
					pd = 0;
					break;
				}
				if(strcmp(dword, words[k].content) < 0){
					pd = 1;
					break;
				}
			}
			if(k == num && pd != 1 && pd != -1){
				strcpy(words[k].content, dword);
				words[k].times = 1;
				num++;
			}
			if(pd){
				for(l = num; l > k; l--){
					words[l] = words[l-1];
				}
				strcpy(words[k].content, dword);
				words[k].times = 1;
				num++;
			}
			i += j;
		}
	}
	for(i = 0; i < num; i++){
		printWord(words[i]);
	}
	return 0;
}

