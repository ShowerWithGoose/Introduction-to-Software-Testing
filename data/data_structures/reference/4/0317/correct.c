#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct word{
	int word_num;
	char each_word[20];
	struct word *link;
};
int main()
{
	struct word *p,*q,*r,*list=NULL,*ps,*qf;
	char temp_word[20];
	char text[100];
	FILE *fp1;
	int i,j;
	
	fp1=fopen("article.txt","r");
	
	while(fgets(text,100,fp1)!=NULL){
		for(i=0;text[i]!='\0';i++){
			if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z')){
				for(j=0;(text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z');j++,i++){
					if(text[i]>='A' && text[i]<='Z')
						text[i]=text[i]-'A'+'a';
					temp_word[j]=text[i];//此时text[i]是单词后的第一个字符
				}
				temp_word[j]='\0';
				i--;
				if(list==NULL){
					q=(struct word*)malloc(sizeof(struct word));
					q->link=NULL;
					strcpy(q->each_word,temp_word);
					q->word_num=1;
					list=p=q;
				}
				else{
					for(ps=list;ps!=NULL && strcmp(ps->each_word,temp_word)<0;qf=ps,ps=ps->link);
					if(ps==NULL){
						q=(struct word*)malloc(sizeof(struct word));
						q->link=NULL;
						strcpy(q->each_word,temp_word);
						q->word_num=1;
						qf->link=q;
						continue;
					}
					else if(strcmp(ps->each_word,temp_word)==0){
						ps->word_num++;
						continue;
					}
					else if(strcmp(ps->each_word,temp_word)>0){
						if(ps!=list){
							q=(struct word*)malloc(sizeof(struct word));
							q->link=ps;
							qf->link=q;
							q->word_num=1;
							strcpy(q->each_word,temp_word);
							continue;
						}
						else{
							q=(struct word*)malloc(sizeof(struct word));
							q->link=ps;
							list=q;
							q->word_num=1;
							strcpy(q->each_word,temp_word);
							continue;
						}
					}
				}
			}
		}
	}
	
	for(r=list;r!=NULL;r=list){
		printf("%s %d\n",r->each_word,r->word_num);
		list=r->link;
		free(r);
	}
	
	fclose(fp1);

	return 0;
}


