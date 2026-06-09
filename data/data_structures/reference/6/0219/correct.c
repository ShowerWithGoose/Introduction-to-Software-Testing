#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define M 100
struct Node{
	struct Node* link;
	char word;
	
};
typedef struct Node Node;
typedef struct Node* Nodeptr;

int op[100],save[M];
int main(){
	char c;
	int i=0,j=0,top=-1,n;
	while (scanf("%d%c",&n,&c)&&c!='\n'){
		op[i++]=n;
	}
	op[i]=n;
	for (i=0,j=0;op[i]!=-1;i++){
		if (op[i]==1){
			if (top!=M-1){
				top++;
				save[top]=op[i+1];
			}
			else printf("error ");
		}
		if (op[i]==0){
			if (top!=-1){
				printf("%d ",save[top]);
				save[top]=0;
				top--;
			}
			else printf("error ");
			}
		}
	return 0;
}








/*int getword(FILE *fp, char*w){      
	int c;
	while(!isalpha(c=fgetc(fp))){ //这个函数只读字母
	if(c == EOF) return c; 
	else continue;
	}
	do {
		*(w++) = tolower(c);
	} while(isalpha(c=fgetc(fp))); 
	*w='\0';
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
	Nodeptr p,q;
	q=list;
	for (i=0;i<n;i++){
		p=q->link;
		free(q);
		q=p;
	}	
}             
int main(){
	char w[35];
	FILE *fp1;
	fp1=fopen("article.txt","r");
	Nodeptr list=NULL,p,q,r;
	while (getword(fp1,w)!=EOF){
		if (list==NULL){
			list=(Nodeptr)malloc(sizeof(Node));
			strcpy(list->word,w);
			list->cnt=1;
			list->link=NULL;
		}
		else {
			for (p=list;p!=NULL&&strcmp(w,p->word)>0;q=p,p=p->link){
				;
			}
			if (p!=NULL&&strcmp(w,p->word)==0){
				(p->cnt)++;
			}
			else {
				r=(Nodeptr)malloc(sizeof(Node));
				strcpy(r->word,w);
				r->cnt=1;
				r->link=NULL;
				if (p==list){
					r->link=list;
					list=r;
				}
				else{
					r->link=p;
					q->link=r;
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
}*/

