#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct words{
	char word[15];
	int seq;
	int count;
}words,*pwords; 
int cmp_www(const void*p1, const void*p2){
	int ans;
	pwords word1= (pwords) p1;
	pwords word2= (pwords) p2;
	ans= strcmp(word1->word,word2->word);
	if(0==ans){
		ans=word1->seq-word2->seq;
	}
	return ans;
}
int main(){
	FILE *in;
	in = fopen ("article.txt","r");
	words Word[500];
	char store[500];
	int i=0,j=0,c=0;
	while((c=fgetc(in))!=EOF){
		if(c>='A'&&c<='Z'){
			c=c-'A'+'a';
		}
		if(c>='a'&&c<='z'){
			store[i]=c;
			i++;
		}else if(c==' '||c=='.'||c==';'||c==')'||c=='\n'||c=='-'||c==','||(c>='0'&&c<='9')){
			store[i]='\0';
			strcpy(Word[j].word,store);
			Word[j].seq=j ;//printf("%s  %s %d\n",Word[j].word,store,i);
			if(strlen(Word[j].word)>0){
			Word[j].count=1;}
			i=0;
			j++;
		}
	}
    if(store[i]>='a'&&store[i]<='z'){
    	strcpy(Word[j].word,store);
    	j++;
	}
	qsort(Word,j,sizeof(words),cmp_www);
	i=0;
	while(i<j){
		if(strcmp(Word[i].word,Word[i+1].word)==0&&i+1<j){
			Word[i+1].count+=Word[i].count;
			Word[i].count=0;
			i++;
		}else{
			i++;
		}
	}
	i=0;
	while(i<j){
		if(Word[i].count!=0){
			printf("%s %d\n",Word[i].word,Word[i].count);
			i++;
		}else{
			i++;
		}
	}
	return 0;
}



