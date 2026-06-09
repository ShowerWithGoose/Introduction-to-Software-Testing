#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Word{
	char word[100];
	int count;
};
char toolower(char c){
	if(c>=65&&c<=90) c=c+32;
	else c=c;
	return c;
}
int main(){
	int i, j, k=0, n=0, total;
	struct Word words[200];
	struct Word temp;
	char line[100][500], a[100];
	FILE *in;
	in=fopen("article.txt","r");
	for(i=0;fgets(line[i],500,in)!=NULL;i++){
		for(j=0;j<strlen(line[i]);j++){
			if(toolower(line[i][j])>=97 && toolower(line[i][j])<=122){
				a[n]=toolower(line[i][j]);
				n++;
			}
			if((toolower(line[i][j+1])<97 || toolower(line[i][j+1])>122) && strlen(a)!=0){
				strcpy(words[k].word,a);
				k++;
				n=0;
				memset(a,0,sizeof(a));
			}
		}
	}//取出所有的单词
	total=k;
	for(i=0;i<k;i++){
		words[i].count=1;
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(strlen(words[j].word)==0) break;
			if(strcmp(words[i].word,words[j].word)==0){
				words[i].count++;
				for(n=j;n<=k;n++){
					words[n]=words[n+1];
				}
				j--;
				total--;
			}
		}
	}
	for(i=0;i<total-1;i++){
		for(j=0;j<total-i-1;j++){
			if(strcmp(words[j].word,words[j+1].word)>0){
				temp=words[j];
				words[j]=words[j+1];
				words[j+1]=temp;
			}
		}
	}
	for(i=0;i<total;i++){
		printf("%s %d\n",words[i].word,words[i].count);
	} 
	fclose(in);
	return 0;
}



