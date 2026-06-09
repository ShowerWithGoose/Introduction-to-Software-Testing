#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct Node{
	struct Node* link;
	char word[35];
	int cnt;
};
typedef struct Node Node;
typedef struct Node* Nodeptr;

int getword(FILE *fp, char*s){      
	int c;
	while(!isalpha(c=fgetc(fp))){ //这个函数只读字母
	if(c == EOF) return c; 
	else continue;
	}
	do {
		*(s++) = tolower(c);
	} while(isalpha(c=fgetc(fp))); 
	*s='\0';
	return 1;
}   

int getlen(Nodeptr list){
	Nodeptr p;
	int n=0;
	for (p=list;p!=NULL;p=p->link) n++;
	return n;
}
 
void clearNode(Nodeptr list){
	int i,n;
	n=getlen(list);
	Nodeptr p,pl;
	pl=list;
	for (i=0;i<n;i++){
		p=pl->link;
		free(pl);
		pl=p;
	}	
}             
int main(){
	char s[35];
	FILE *fp1;
	fp1=fopen("article.txt","r");
	Nodeptr list=NULL,p,pl,q;
	while (getword(fp1,s)!=EOF){
		if (list==NULL){
			list=(Nodeptr)malloc(sizeof(Node));
			strcpy(list->word,s);
			list->cnt=1;
			list->link=NULL;
		}
		else {
			for (p=list;p!=NULL&&strcmp(s,p->word)>0;pl=p,p=p->link){
				;
			}
			if (p!=NULL&&strcmp(s,p->word)==0){
				(p->cnt)++;
			}
			else {
				q=(Nodeptr)malloc(sizeof(Node));
				strcpy(q->word,s);
				q->cnt=1;
				q->link=NULL;
				if (p==list){
					q->link=list;
					list=q;
				}
				else{
					q->link=p;
					pl->link=q;
				}	
			}
		}
	}
	for (p=list;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->cnt);
	}
	clearNode(list);
	fclose(fp1);
	return 0;
}

