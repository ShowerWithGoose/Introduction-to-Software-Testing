#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
	char word[20];
	int cnt;
	struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;
int main()
{
	FILE *in;
	if((in=fopen("article.txt","r"))==NULL){
		printf("NOT FIND THE FILE");
		return 0;
	}
	Nodeptr q,p=NULL,p0=NULL,list=NULL;
	char c;
	char s[20];
	int i=0,flag=0;
	while((c=fgetc(in))!=EOF){
		if(isalpha(c)!=0){
			i=0;
			do{
				s[i]=tolower(c);
				i++;
				c=fgetc(in);
			}while(isalpha(c)!=0);
			s[i]='\0';
			if(list==NULL){
				q=(Nodeptr)malloc(sizeof(Node));
				strcpy(q->word,s);
				q->cnt=1;
				list=q;
			}
			else{
				for(p=list;p!=NULL;p0=p,p=p->link){
					if(strcmp(p->word,s)==0){
						p->cnt++;
						break;
					}
					if(strcmp(p->word,s)>0){
						q=(Nodeptr)malloc(sizeof(Node));
						strcpy(q->word,s);
						q->cnt=1;
						q->link=p;
						if(p0==NULL) list=q;
						else p0->link=q;
						break;
					}
				}
				if(p==NULL){
					q=(Nodeptr)malloc(sizeof(Node));
					strcpy(q->word,s);
					q->cnt=1;
					p0->link=q;
				}
			}
			memset(s,0,sizeof(s));
			p0=NULL;
		}
	}
	for(p=list;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->cnt);
	}
	fclose(in);
	return 0;
}


