#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max 32
struct word {
	char str[max];
	int count;
	struct word*next;
};
int main() {
	FILE*in;
	in=fopen("article.txt","r");
	struct word*word_list,*p=NULL;
	p=word_list=(struct word*)malloc(sizeof(struct word));
	word_list->next=NULL;
	char c;
	int i=0;
	char str[max]={0};
	while((c=fgetc(in))!=EOF) {
		if(c<='z'&&c>='a') {
			str[i]=c;
			i++;
		} else if(c<='Z'&&c>='A') {
			str[i]=c-'A'+'a';
			i++;
		} else {
			if(i!=0) {
				str[i]='\0';
				int k=0;
				p=word_list;
				while(p->next!=NULL) {

					if(strcmp(p->str,str)==0) {
						p->count++;
						k=1;
					} else if(strcmp(p->str,str)<0&&strcmp(p->next->str,str)>0) {
						struct word*tmp=(struct word*)malloc(sizeof(struct word));
						tmp->next=NULL;
						tmp->count=1;
						strcpy(tmp->str,str);
						tmp->next=p->next;
						p->next=tmp;
						k=1;
					}
					p=p->next;
				}
				if(k==0) {
					if(strcmp(p->str,str)==0) {
						p->count++;
					} else {
						struct word*tmp=(struct word*)malloc(sizeof(struct word));
						tmp->next=NULL;
						tmp->count=1;
						strcpy(tmp->str,str);
						p->next=tmp;
					}
				}
			}
			i=0;
		}
	}
	fclose(in);
	p=word_list;
	p=p->next;
	free(word_list);
	word_list=p;
	while(p!=NULL) {
		printf("%s %d\n",p->str,p->count);
		p=p->next;
		free(word_list);
		word_list=p;
	}
	return 0;
}

