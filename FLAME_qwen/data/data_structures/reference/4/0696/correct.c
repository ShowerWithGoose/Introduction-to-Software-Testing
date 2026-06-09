#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct word{
	char wooord[100];
	int pin;
}WORD,*PWORD;

//函数声明
void get_article(FILE*); 
int get_word(void);
void check_same(int);
void traverse(int m);


char str[500];
WORD Word[500];

int cmp(const void *a,const void *b){
	PWORD c=(PWORD)a;
	PWORD d=(PWORD)b;
	if(strcmp(c->wooord,d->wooord))return strcmp(c->wooord,d->wooord);
	else{
		return c->pin-d->pin;
	}
}

int main(){
	int m;
	FILE * fp1=fopen("article.txt","r");
	if(fp1==NULL)printf("打开失败");
	get_article(fp1);
	m=get_word();
	check_same(m);
	traverse(m);
	
	
	return 0;
}

void traverse(int m){
	int i;

	for(i=0;i<m;i++){
		if(Word[i].pin)printf("%s %d\n",Word[i].wooord,Word[i].pin);
	}
}


void check_same(m){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			if(i==j)continue;
			if(!strcmp(Word[i].wooord,Word[j].wooord)&&Word[i].pin!=0&&Word[j].pin!=0){
				Word[i].pin+=Word[j].pin;Word[j].pin=0;
			}
		}
	}
	qsort(Word,m,sizeof(WORD),cmp);
}

int get_word(void){
	int i,j,k,m;
	char temp[50];
	m=0;
	for(i=0;i<strlen(str);i++){
		if(isalpha(str[i])){
			for(j=0;j+i<strlen(str);j++){
				if(!isalpha(str[j+i]))break;
			}
			memset(temp,0,sizeof(temp));
			for(k=0;k<j;k++){
				temp[k]=str[k+i];
			}
//			puts(temp);
			i+=j;
			strcpy(Word[m].wooord,temp);
			Word[m].pin=1;
			m++;
		}
		
	}
	return m;
}

void get_article(FILE*fp1){
	char ch;
	ch=fgetc(fp1);
	int i=0;
	while(ch!=EOF){
		str[i]=ch;
		i++;
		ch=fgetc(fp1);
	}
	for(i=0;i<strlen(str);i++){
		if(isalpha(str[i]))str[i]=tolower(str[i]);
	}
	
	
}

