#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct word{
	char ch[10000];
	int n;
}s[10086];
	char c;
	char op[114514];
	int tmp,i;
int comword(const void *p1,const void *p2);
void addword();
void print();
int main(){
	FILE*fp0=fopen("article.txt","r");
	tmp=0;
	while((c=fgetc(fp0))!=EOF){
	    op[tmp]=c;
	    tmp++;
	}
	tmp=0;
    addword();
	qsort(s,tmp,sizeof(s[0]),comword);
	for(i=0;i<tmp;i++) if(strlen(s[i].ch ))s[i].n =1;
	for(i=0;i<tmp;i++){
		if(strcmp(s[i].ch,s[i+1].ch)==0){
			s[i+1].n +=s[i].n ;
			s[i].n =0;
		}
	}
	print();
	return 0;
}
int comword(const void *p1,const void *p2){
	struct word*a=(struct word*)p1;
	struct word*b=(struct word*)p2; 
	return strcmp(a->ch,b->ch);
}
void addword(){
	int word_pos=0;
	int j=0;
	int len=strlen(op);
	for(j=0;j<len;j++){
		if(!isalpha(op[j])){
			tmp++;
			word_pos=0;
		}
		else if(isalpha(op[j])){
			s[tmp].ch[word_pos]=tolower(op[j]);
			word_pos++;
		}
	}
}
void print(){
	for(i=0;i<tmp;i++)
	 if (s[i].n !=0)
	 printf("%s %d\n",s[i].ch ,s[i].n );
}

