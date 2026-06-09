#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	char word[200];
	int num;
}; 
typedef struct node node;
node text[1005];
main(){
	FILE *in;
	if((in = fopen("article.txt", "r"))==NULL){
		printf("Can&rsquo;t open in.txt!");
		return;
	}
	char c;
	int i=0,j=0;
	while((c=fgetc(in))!=EOF){
		
		if(isupper(c)!=0){
			c=tolower(c); 
			text[i].word[j++]=c;
		//	printf("%c",c);
		}
		else if(islower(c)!=0){
			text[i].word[j++]=c;
		//	printf("%c",c);
		}
		else
		{
			j=0;
			text[i++].num=1;
		//	printf(" ");
		}
	}
	int len=i;
	char art[200];
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(strcmp(text[i].word,text[j].word)>0){
				strcpy(art,text[i].word);
				strcpy(text[i].word,text[j].word);
				strcpy(text[j].word,art);
			}
		}
	}
	for(i=0;i<len;i++){
		for(j=i+1;j<len;j++){
			if(strcmp(text[i].word,text[j].word)==0)
			{
				text[j].word[0]='\0';
				text[i].num++;
			}
		}
	}
	//printf("\n");
	for(i=0;i<len;i++){
		if(islower(text[i].word[0]))
		printf("%s %d\n",text[i].word,text[i].num);
	}

}

