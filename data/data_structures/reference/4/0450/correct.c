#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char s[100];
struct word{
	char data[100];
	int cnt;
}Word[1000];
typedef struct word* wordptr;

int cmp(const void*p1, const void*p2){
	wordptr a = (wordptr)p1; wordptr b = (wordptr)p2;
	return strcmp(a->data , b->data);
}
int OK(int n);
void Deal(int n);

int main()
{
	FILE *in=fopen("article.txt","r");
	char ch;
	int s_cnt=0,word_cnt=0;
	int i;
	
	while((ch=fgetc(in))!=EOF){
		if(isupper(ch)){
			ch=tolower(ch);
		}
		if(islower(ch)){
			s[s_cnt++]=ch;
		}
		else{
			if(OK(word_cnt)){//Î´³öÏÖ¹ý 
				strcpy(Word[word_cnt].data , s);
				Word[word_cnt].cnt ++;
				word_cnt++;
			}
			else{
				Deal(word_cnt);
			}
			memset(s,0,sizeof(s));
			s_cnt=0;
		}
	}
	qsort(Word,word_cnt,sizeof(struct word),cmp);
	for(i=0;i<word_cnt;i++){
		if(Word[i].data[0])
		printf("%s %d\n",Word[i].data ,Word[i].cnt );
	}
	
	return 0;
}
int OK(int n){
	int flag=1;
	int i;
	for(i=0;i<n;i++){
		if(strcmp(Word[i].data ,s)==0){
			flag=0; break;
		}
	}
	return flag; 
}
void Deal(int n){
	int i,j;
	for(i=0;i<n;i++){
		if(strcmp(Word[i].data , s)==0){
			Word[i].cnt ++;
			return;
		}
	}
} 

