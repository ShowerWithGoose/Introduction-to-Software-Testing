#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node* linklist;
typedef struct node Linklist;
struct node{
	char s[25] ;
	int cnt;
	linklist link;
};
void listsort(linklist list)
{
	linklist r1,r2;
	r1=list;
	while(r1->link){
		r2=list;
		while(r2->link){
			if(strcmp(r2->s,r2->link->s)>0){
				char temp1[25];
				int temp2;
				strcpy(temp1,r2->link->s);
				temp2=r2->link->cnt;
				r2->link->cnt=r2->cnt;
				r2->cnt=temp2;
				strcpy(r2->link->s,r2->s);
				strcpy(r2->s,temp1);
			}
			r2=r2->link;
		}
		r1=r1->link;
	}
}
linklist find(linklist list,linklist q){
	linklist p=list;
	while(strcmp(q->s,p->s)!=0)
	{
		if(p->link==NULL) return p->link;
		else p=p->link;
	}
	return p;
}
char s1[500005];
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	linklist p,q,list=NULL;
	int i;
	int k1=0;
	while(fgets(s1,500005,in)){
		int k=strlen(s1);
		int i;
		char s2[25]={0};
		for(i=0;i<k;i++){
			if(islower(s1[i])){
					s2[k1]=s1[i];
					k1++;
			}
			else if(isupper(s1[i])){
				s2[k1]=tolower(s1[i]);
				k1++;
			}
			if(!islower(s1[i+1])&&!isupper(s1[i+1])&&k1!=0){
				p=(linklist)malloc(sizeof(Linklist));
				p->cnt=1;
				strcpy(p->s,s2);
				p->link=NULL;
				k1=0;
				memset(s2,0,sizeof(s2));
				if(list==NULL){
					list=p;
					q=p;
				}
				else if(find(list,p)){
					linklist q1=find(list,p);
					q1->cnt++;
				}
				else{
					 q->link=p;
					 q=p;
				}
			}
		}
	}	
	listsort(list);
	while(list){
		printf("%s %d\n",list->s,list->cnt);
		list=list->link;
	}
	return 0;
}




