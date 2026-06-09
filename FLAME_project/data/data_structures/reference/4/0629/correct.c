#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024
int ischar(char a) {
	return (a>='A'&&a<='Z')||(a>='a'&&a<='z')?1:-1;
}
struct words {
	char ch[30];
	int count;
} word[5000];
void bubbleSort(struct words a[], int n) {
	int i, j, flag;
	struct words hold;
	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (strcmp(a[j].ch,a[j+1].ch)>0) {
				hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}

		}
	}
}
int getword(FILE *in,char s[200]){
	char c;
	int i = 0;
	while(!isalpha(c = fgetc(in))){
		if(c == EOF) return c;
		else continue;
	}
	do{
		s[i++] = tolower(c);
	}while(isalpha(c = fgetc(in)));
	s[i] = '\0';
	return 1;
}
char s[200];
int main() {
	FILE *in;
	int i=0,j=0,n=0,temp=0,k=0;
	in=fopen("article.txt","r");
	while(getword(in,s)!=EOF) {
		
		temp=0;
		for(i=0; i<n; i++) {
			if(strcmp(word[i].ch,s)==0) {
				word[i].count++;
				temp=1;
				break;
			}
		}
		if(temp==0) {
			strcpy(word[n].ch,s);
			word[n].count++;
			n++;
		}
		memset(s,'\0',30);
	}
	bubbleSort(word,n);
	for(i=0; i<n; i++)
		printf("%s %d\n",word[i].ch,word[i].count);
	fclose(in);
	return 0;
}


