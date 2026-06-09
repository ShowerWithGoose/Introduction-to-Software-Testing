#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct wordfrequency{
	char word[100];
	int frequency;
	struct wordfrequency *next;
} wf;
wf* create(wf *p,char w[]){
	int i,j,k;
	p=(wf*)malloc(sizeof(wf));
	for(i=0;i<100;i++) p->word[i]='\0';
	for(i=0;i<strlen(w);i++) p->word[i]=w[i];
	p->frequency=1;
	p->next=NULL;
	return p;
}
int main(){
	FILE *fp;
	fp=fopen("article.txt","r");
	int a,b,c,d,e[10],f,g,h,i,j,k=0,l;
	wf *head,*p,*q,*r;
	head=NULL;
	char wn[100],w[100],m[100];
	for(i=0;i<100;i++) w[i]='\0';
	while(fscanf(fp,"%s",m)!=EOF){
		i=0;c=0;d=0;
		for(j=0;j<strlen(m);j++){
			if(isalpha(m[j])){
				wn[i]=tolower(m[j]);
				i++;
				c++;
			}
			else if(c>0){
				e[d]=c;
				d++;
				c=0;
			}				
		}
		if(c>0){
			e[d]=c;
			d++;
			c=0;
		}
		h=0;
		if(i>0) for(f=0;f<d;f++){
			for(g=0;g<e[f];g++) w[g]=wn[h+g];
			h+=e[f];
			if(k==0){
				head=create(head,w);
				k++;
			}
			else{
				p=head;
				if(strcmp(w,p->word)<0){
					r=create(r,w);
					head=r;
					r->next=p;
					k++;
				}
				else for(l=0;l<k;l++){
					a=strcmp(w,p->word);
					if(a>0){
						q=p;
						p=p->next;
						b=a;
					}
					if(a==0){
						p->frequency++;
						break;
					}
					if(a<0&&b>0){
						r=create(r,w);
						r->next=p;
						q->next=r;
						k++;
						break;
					}
				}
				if(l==k){
					r=create(r,w);
					q->next=r;
					k++;
				}
			}
			for(l=0;l<100;l++) w[l]='\0';
		}
	}
	for(l=0;l<k;l++){
		printf("%s %d\n",head->word,head->frequency);
		head=head->next;
	}
	fclose(fp);
}

