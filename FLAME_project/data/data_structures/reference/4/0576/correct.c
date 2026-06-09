#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100000
#define MAX1 1000
struct list{
	char word[MAX1];
	int  cnt;
	int flag;
}n[MAX];
char num[MAX];

int cmp(const void*a,const void*b){
	return strcmp((*(struct list*)a).word,(*(struct list*)b).word);
}
int judge(char);

int main (){
	FILE *in;
	int  len,i,j=-1,k=0,flag=0;
	in=fopen("article.txt","r");
	while(fgets(num,MAX1,in)!=NULL){
		len=strlen(num);
		for(i=0;i<len;i++){
			if(judge(num[i])&&!flag){
				j++;
				k=0;
				n[j].word[k++]=num[i];
				flag=1;
			}
			else if(judge(num[i])&&flag){
				n[j].word[k++]=num[i];
			}
			else if((!judge(num[i]))&&flag){
				flag=0;
				n[j].word[k]='\0';
				n[j].cnt =1;
				n[j].flag =1;
			}
		}
		n[j].word[k]='\0';
		n[j].cnt =1;
		n[j].flag =1;
		flag=0;
	}
	
	for(i=0;i<j+1;i++){
		if(n[i].flag){
			len=strlen(n[i].word );
			for(k=0;k<len;k++){
				if(judge(n[i].word[k])==2)
					n[i].word[k]='a'+n[i].word[k]-'A';
			}
		}
			
	}
	
	for(i=0;i<j+1;i++){
		if(n[i].flag ){
			for(k=i+1;k<j+1;k++){
				if(strcmp(n[i].word,n[k].word)==0){
					n[i].cnt++;
					n[k].flag=0;
				}
			}
		}
	}
	

	
	qsort(n,j+1,sizeof(n[0]),cmp);
	
	for(i=0;i<j+1;i++){
		if(n[i].flag )
			printf("%s %d\n",n[i].word ,n[i].cnt );
	}
}

int judge(char num){
	if(num>='A'&&num<='Z')
		return 2;
	else if(num>='a'&&num<='z')
		return 1;
	return 0;
}

