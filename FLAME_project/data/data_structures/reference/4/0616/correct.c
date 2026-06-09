#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char b[2000][200];
int main() {
	char a[5000],q[200];
	int i=0,j=0,k=0,m;
	FILE *fp1;
	fp1=fopen("article.txt","r");
	while(fgets(a,5000,fp1)/*gets(a)!=NULL*/) {
		for(i=0; i<strlen(a); i++) {
			if(a[i]>='a'&&a[i]<='z') {
				b[j][k]=a[i];
				k++;
			} else if(a[i]>='A'&&a[i]<='Z') {
				b[j][k]=a[i]+32;//strlwr();
				k++;
			}
			//else if(a[i]==' '||a[i]==';'||a[i]==','||a[i]=='.'||a[i]=='!'||a[i]=='?'||a[i]==':'){
			//	k=0;j++;
			//	if(a[i+1]==' ')
			//	i++;
			//}
			if(isalpha(a[i])!=0&&isalpha(a[i+1])==0) {
				k=0;
				j++;
			}
		}
	}
	struct node {
		int cishu;
		char ci[200];
		struct node*next;
	};
	struct node *p,*r,*list=NULL,*p1=NULL,*p2=NULL,*p3=NULL,*p4=NULL;
	for(i=0; i<j; i++) {
		p=(struct node*)malloc(sizeof(struct node));
		strcpy(p->ci,b[i]);
		p->cishu=1;
		p->next=NULL;
		if(list==NULL) {
			list=p;
		} else {
			r->next=p;
		}
		r=p;
	}
	p1=list;

	while(p1!=NULL) {
		p3=p1;
		p2=p1->next;
		while(p2!=NULL) {
			if(strcmp(p1->ci,p2->ci)>0) {
				strcpy(q,p1->ci);
				strcpy(p1->ci,p2->ci);
				strcpy(p2->ci,q);
				m=p1->cishu;
				p1->cishu=p2->cishu;
				p2->cishu=m;
				p3=p2;
				p2=p2->next;
			} else if(strcmp(p1->ci,p2->ci)==0) {
				p1->cishu++;
				p3->next=p2->next;
				p2=p2->next;
			} else {
				p3=p2;
				p2=p2->next;
			}
		}
		p1=p1->next;
	}
	p4=list;
	while(p4!=NULL) {
		printf("%s %d\n",p4->ci,p4->cishu);
		p4=p4->next;
	}
	fclose(fp1);
	return 0;
}

