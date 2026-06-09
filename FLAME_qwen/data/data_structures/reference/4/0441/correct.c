#include <stdio.h>
#include <string.h>

char article[1005];
int len;

typedef struct words
{
	char s[35];
	int n;
}words;

words word[102];

int compare(char *p, char *q)
{
	int cc = 0;
	while(p[cc] == q[cc] && p[cc] != '\0'){
		cc ++;
	}
	if(p[cc] == q[cc] && q[cc] == '\0'){
		return 1;
	}
	else return 0;
}

int main ()
{
	FILE *in;
	in = fopen("article.txt", "r");
	
	char c;
	while((c = fgetc(in)) != EOF){
		if(c >= 'A' && c <= 'Z'){
			c += 'a' - 'A';
		}
		article[len ++] = c;
	}
	
	int count = 0;
	for(int i = 0 ; i < len ; i ++){
		int count_ = 0;
		if(article[i] >= 'a' && article[i] <= 'z'){
			while(article[i + count_] >= 'a' && article[i + count_] <= 'z' ){
				word[count].s[count_] = article[i + count_];
				count_ ++;
			}
			count ++;
			i += count_;
		}
	}
	
	/*for(int i = 0 ; i < count ; i ++){
				printf("%s %d", word[i].s, word[i].n + 1);
				printf("\n");
			}
		printf("%s %d", word[count].s, word[count].n + 1);*/
	
	for(int j = 0 ; j < count ; j ++){
		int flag = 1;	
		for(int i = 0 ; i < count - j ; i ++){
			int cnt = 0;
			
			while(word[i].s[cnt] == word[i + 1].s[cnt] && word[i].s[cnt] != '\0'){
				cnt ++;
			}
			if(word[i].s[cnt] >= word[i + 1].s[cnt]){
				words t;
				t = word[i];
				word[i] = word[i + 1];
				word[i + 1] = t;
				flag = 0;
			}
		}
		if(flag){
			break;
		}
	}
	
	for(int i = 0 ; i < count ; i ++){
			if(word[i].s[0] == '\0'){
				for(int j = i ; j < count ; j ++){
					word[j] = word[j + 1];
				}
				count --;
			}
		}
		
	for(int i = 0 ; i < count ; i ++){
			if(compare(word[i].s, word[i + 1].s)){
				word[i].n ++;
				for(int j = i + 1 ; j < count ; j ++){
					word[j] = word[j + 1];
				}
				count --;
				i --;
			}
		}
	
	for(int i = 0 ; i < count ; i ++){
			printf("%s %d", word[i].s, word[i].n + 1);
			printf("\n");
		}
	printf("%s %d", word[count].s, word[count].n + 1);
	
	fclose(in);
	return 0 ;
}

