#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct mode{
	struct mode *former;
	char a[20];
	int d;
	struct mode *next;
}art;
int main(){
	art *lll=NULL,*p=NULL,*q=NULL,*r=NULL;
	int i=0,j=0,k=0;
	char c,e[20];
	for(i=0;i<20;i++){
		e[i]='\0';
	}
	freopen("article.txt","r",stdin);
	while((c=getchar())!=EOF){
		if(c<='z'&&c>='a'){
			e[j]=c;
			j++;
		}else{
			if(c<='Z'&&c>='A'){
				e[j]=c-'A'+'a';
				j++;
			}else{
				if(j!=0){
					if(lll==NULL){
				p=(art*)malloc(sizeof(art));
			    strcpy(p->a,e);
				p->d=1;
				p->former=NULL;
				p->next=NULL;
				lll=p;
			}else{
				for(q=lll;q!=NULL;q=q->next){
					k=strcmp(q->a,e);
					if(k<0){
						continue;
					}else{
						break;
					}
				}if(k==0){
					(q->d)++;
				}else{
					if(k>0){
						r=(art*)malloc(sizeof(art));
						strcpy(r->a,e);
						r->d=1;
						if(q==lll){
							r->former=NULL;
							r->next=q;
							q->former=r;
							lll=r;
						}else{
							r->former=q->former;
						    r->next=q;
						    (q->former)->next=r;
						    q->former=r;
						}
					}else{
						if(q==NULL){
							r=(art*)malloc(sizeof(art));
						    strcpy(r->a,e);
						    r->d=1;
						    r->former=p;
						    r->next=NULL;
						    p->next=r;
						    p=r;
						}
					}
				}
			}
			for(j=0;j<20;j++){
			e[j]='\0';
		}j=0;
				}
			}
		}
	}
    for(q=lll;q!=NULL;q=q->next){
		printf("%s %d\n",q->a,q->d);
	}
	return 0;
}

