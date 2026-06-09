#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>

struct node{
	char word[50];
	int cnt;
};
int N;

int insert(struct node list[],int pos,char *w){//插入没有的单词 
	int i;
	if(N==1000){
		return -1;
	}
	for(i=N-1;i>=pos;i--){
		strcpy(list[i+1].word,list[i].word);
		list[i+1].cnt=list[i].cnt;
	}
	strcpy(list[pos].word,w);
	list[pos].cnt=1;
	N++;
	return 1;
}

int search(struct node list[],char *w){//查找表中有没有这个词 
	int low=0,high=N-1,mid=0;
	while(low<=high){
		mid=(high+low)/2;
		if(strcmp(w,list[mid].word)<0){
			high=mid-1;
		}
		else if(strcmp(w,list[mid].word)>0){
			low=mid+1;
		}
		else{
			list[mid].cnt++;
			return 0;
		}
	}
	return insert(list,low,w);
}

int getword(FILE *fp,char *w){
	int c;
	while(!isalpha(c=fgetc(fp))){//读掉前面所有不是字母的符号 
		if(c==EOF){
			return c;
		}
		else{
			continue;
		}
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}

int main()
{
	struct node list[1000];
	int i;
	char word[50];
	FILE *bfp;
	bfp=fopen("article.txt","r");
	
	while(getword(bfp,word)!=EOF){
		if(search(list,word)==-1){
			return -1;
		}
	}
	for(i=0;i<N;i++){
		printf("%s %d\n",list[i].word,list[i].cnt);
	}
	return 0;
 }

