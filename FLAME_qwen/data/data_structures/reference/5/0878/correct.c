#include<stdio.h>
typedef struct poly{
	int cof;
	int exp;
	struct poly *next;
} polynode;

polynode a1[100],a2[100],ans[10000];

int main(){
	int cof,exp,i=0,len1,len2,j,k=0,flag=1;
	polynode *p;
	char jd;
	while(flag){
		scanf("%d %d%c",&cof,&exp,&jd);
		a1[i].cof=cof;
		a1[i].exp=exp;
		i++;
		if(jd=='\n') break;
	}
	len1=i;
	i=0;
	
	while(flag){
		scanf("%d %d%c",&cof,&exp,&jd);
		a2[i].cof=cof;
		a2[i].exp=exp;
		i++;
		if(jd=='\n') break;
	}
	len2=i;//read in
	
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			ans[k].cof=a1[i].cof*a2[j].cof;
			ans[k].exp=a1[i].exp+a2[j].exp;
			k++;
		}
	}//calculate
	
	for(i=1;i<k;i++){
		for(p=&ans[0];p!=NULL;p=p->next){
			
			if(ans[i].exp==p->exp){
				p->cof+=ans[i].cof;
				break;
			}
			
			if(ans[i].exp<p->exp&&p->next==NULL){
				p->next=&ans[i];
				break;
			}
			
			if(ans[i].exp<p->exp&&ans[i].exp>p->next->exp){
				ans[i].next=p->next;
				p->next=&ans[i];
				break;
			}
			
		}
	}
	
	for(p=&ans[0];p!=NULL;p=p->next){
		if(p->cof) printf("%d %d ",p->cof,p->exp);
	}
	return 0;
} 

