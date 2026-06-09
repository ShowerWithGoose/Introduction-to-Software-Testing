#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct NODE{
	char str[20];
	int n;
	struct NODE *link;
}node;

char a[100][20]; 

int main(){
	FILE *fr=fopen("article.txt","r");
	
	char tmp[20],c;
	int i=0,j=0,time=0,k=0,flag=0,temp=0;
	node *p,*r,*list=NULL,*head=NULL;
	while(fscanf(fr,"%c",&c)!=EOF){
		if(c>='A'&&c<='Z'){
			c=c-'A'+'a';
		}
		if(c<'a'||c>'z'){
			if(strlen(a[i])!=0){
				time++;
				i++;
				j=0;
			}
			continue;
		}
		if(c>='a'&&c<='z'){
			a[i][j]=c;
			j++;
		}
	}
	if(strlen(a[i])!=0){
		time++;
		i++;
		j=0;
	}
			
	for(i=0;i<time;i++){
		p=(node*)malloc(sizeof(node));
		strcpy(p->str,a[i]);
		p->n=1;
		p->link=NULL;
		if(list==NULL)
			list=p;
		else
			r->link=p;
		r=p;
		head=list;
	}//建立链表 
	
	for(i=0;i<time-1;i++){
		flag=0;
		for(j=0;j<time-1-i;j++){
			if(strcmp(list->str,list->link->str)>0){
				strcpy(tmp,list->str);
				strcpy(list->str,list->link->str);
				strcpy(list->link->str,tmp);
				temp=list->n;
				list->n=list->link->n;
				list->link->n=temp;
				flag=1;
				
				list=list->link;
			}
			else 
				list=list->link;
		}
		
		list=head;
		if(flag==0)
			break;
	}//排序 
	
	p=list->link;
	r=list;
	for(i=0;i<time-1;i++){
		if(strcmp(r->str,r->link->str)==0){
			r->n+=r->link->n;
			r->link=p->link;
			free(p);
			p=r->link;
			k++;
		}
		else{
			r=p;
			p=p->link;
		}
	}
	time-=k;//合并 
	
	for(i=0;i<time;i++){
		printf("%s %d\n",list->str,list->n);
		if(i==time-1)
			break;
		else
			list=list->link;
	}
	
	fclose(fr);
	return 0;
}

