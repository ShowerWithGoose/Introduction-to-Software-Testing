#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h> 
struct line{
	char word[20];
	int num;
};
struct line rem[100];
int cmp(const void *a,const void *b){
	struct line *aa=(struct line*)a;
	struct line *bb=(struct line*)b;
	return strcmp(aa->word,bb->word);
	return -1;
}
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int flag=0,i,j,flag1;
	char c;
	for(i=0;i<100;i++){
		rem[i].num=1;
	}
	while((c=fgetc(in))!=EOF){
		i=0;
		if(isalpha(c)>0){
			rem[flag].word[i]=tolower(c);
			i++;
		}
		else
		continue;
		while(isalpha(c=fgetc(in))>0){
			rem[flag].word[i]=tolower(c);
			i++;
		}
		rem[flag].word[i]='\0';
		flag++;
	}
	qsort(rem,flag,sizeof(rem[0]),cmp);
	for(i=0;i<flag;i++){
		for(j=i+1;j<flag;j++){
			if(strcmp(rem[i].word,rem[j].word)==0&&rem[i].num!=0){
				rem[i].num++;
				rem[j].num=0;
			}
		}
	}
	for(i=0;i<flag;i++){
		if(rem[i].num!=0){
			printf("%s %d\n",rem[i].word,rem[i].num);
		}
	}
	fclose(in);
	return 0;
}



