#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define arynum(x) (sizeof(x)/sizeof(x[0]))
#define uint unsigned int
#define uchar unsigned char

struct word{
	char cont[30];
	int ans;
	struct word *next;
}tst,*pmin;

char s[10000];

int main(){
	int i,j,k,n=0,num=0;
	struct word *p,*list;
	if(freopen("article.txt","r+",stdin)==NULL) printf("-1");
	tst.ans =1;
	tst.next =NULL;
	list=p=(struct word*)malloc(sizeof(tst));
	p->next =NULL;
	
	while(gets(s)!=NULL){
		num=strlen(s);
		for(i=0;i<num;i++){
			if(isalpha(s[i])){
				s[i]=tolower(s[i]);
			}
			else s[i]='0';
		}
		
		for(i=0;i<num;){
			if(!islower(s[i])){
				i++;
				continue;
			}
			else{
				for(j=0;islower(s[i+j]);j++)
					tst.cont[j]=s[i+j];
				tst.cont[j]='\0';
				i+=j;
				p=list;
				while(p->next!=NULL){
					if(strcmp(tst.cont , p->cont )==0){
						p->ans++;
						goto ld;
					}
					p=p->next ;
				}
				*p=tst;
				p->next =(struct word*)malloc(sizeof(tst));
				n++;
				p=p->next ;
				p->next =NULL;
			}
			ld:k++;
		}
	}
	
	p=list;
	for(i=0;i<n-1;i++)	p=p->next ;
	p->next =list;
	
	
	p=list;
	pmin=list;
	for(i=0;i<n;){
		while(strcmp(pmin->cont ,"zzz")==0 )	
		pmin=pmin->next ;
		kd:if(strcmp(pmin->cont ,p->cont )>0){
			pmin=p;
			for(j=0;j<n;j++){
				if(strcmp(pmin->cont ,p->cont )<=0){
					p=p->next ;
				}
				else if(strcmp(pmin->cont ,p->cont )>=0){
					
					goto kd;
				}
			}
			printf("%s %d\n",pmin->cont ,p->ans );	i++;
			strcpy(pmin->cont,"zzz") ;
		}
		else if(strcmp(p->cont ,"zzz")==0)	p=p->next ;
		else{
			pmin=pmin->next;
			goto kd;	
		} 	
	}
	
	return 0;
} 







