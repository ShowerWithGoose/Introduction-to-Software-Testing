#include<stdio.h>
#include<string.h>
typedef struct {
		char word[15];
		int num;
}word_num;
word_num temp;
void sort(word_num wn[], int k){
	int i, j;
	for(i = 0; i < k; i++){
		for(j = i; j < k; j++){
			if(strcmp(wn[i].word, wn[j].word) > 0){
				temp = wn[i];
				wn[i] = wn[j];
				wn[j] = temp;
			}
		}
	}
}
int main(){
	FILE *in;
	in = fopen("article.txt","r");
	int i, j, k = 0,l = 0;
	char s[2][50], word0[1000][50];
	word_num wn[500];
	int m = 0, n = 0;
	while(fscanf(in, "%c", &word0[m][n]) != EOF){
		if((word0[m][n] >= 'A' && word0[m][n] <= 'Z')||(word0[m][n] >= 'a' && word0[m][n] <= 'z')) n++;
		else if(n>0){
			word0[m][n] = '\0';
			m++;
			n = 0;
		}
	}
//	printf("%s", word0[1]);
	while(sscanf(word0[l++], "%s", s[0]) != EOF){
		int flag = 1;
		for(i = 0; s[0][i] != '\0'; i++)
			if(s[0][i] >= 'A' && s[0][i] <= 'Z') s[0][i] = s[0][i] + 'a' - 'A';
		for(i = 0, j = 0; s[0][i] != '\0'; i++)
			if(s[0][i] >= 'a' && s[0][i] <= 'z') s[1][j++] = s[0][i];
		s[1][j] = '\0';
		for(j = 0; j < k; j++)
			if(strcmp((wn[j]).word, s[1]) == 0){
				(wn[j]).num++;
				flag = 0;
				break; 
			}
		if(flag == 1 && s[1][0] >= 'a' && s[1][0] <= 'z'){
			strcpy((wn[k]).word, s[1]);
			(wn[k]).num = 1;
			k++;
		}
	}
	sort(wn, k);
	for(i = 0; i < k; i++){
		printf("%s %d",wn[i].word, wn[i].num);
		printf("\n");
	}
	fclose(in);
	return 0;
}

