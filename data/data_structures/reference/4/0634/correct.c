#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct stu{
	char c[50];
	int count;
	struct stu *link;
};
struct stu *seek(struct stu *list,char buf[]);
int main(){
	char buf[50],s[1005],*tmp;
	FILE *in;
	in=fopen("article.txt","r");
	struct stu *list=NULL,*p,*q,*t;
	while(fgets(s,1005,in)!=NULL){
		int i=0;
		while(s[i]){
			if(isupper(s[i])){
				s[i]+='a'-'A';
			}
			if(!islower(s[i])){
				i++;
				continue;
			}
			else{
				int k=0,j;
				for(j=i;1;j++){
					if(isupper(s[j])){
						s[j]+='a'-'A';
					}
					if(islower(s[j])){
						buf[k++]=s[j];
					}
					else
						break;
				}
				i=j;
				buf[k]='\0';
				list=seek(list,buf);
			}
		}
	}
	t=list;
	while(t!=NULL){
		printf("%s %d\n",t->c,t->count);
		q=t;
		t=t->link;
		free(q);
	}
	return 0;
}
struct stu *seek(struct stu *list,char buf[]){
	struct stu *s,*t,*r,*q=NULL;
	s=list;
	while(s!=NULL){
		if(strcmp(s->c,buf)==0){
			(s->count)++;
			return list;
		}
		s=s->link;
	}
	t=(struct stu*)malloc(sizeof(struct stu));
	strcpy(t->c,buf);
	t->link=NULL;
	if(list==NULL){
		list=r=t;
		t->count=1;
		return list;
	}
	else{
		s=list;
		while(s!=NULL){
			if(strcmp(s->c,buf)>0){
				t->link=s;
				t->count=1;
				if(q!=NULL){
					q->link=t;
					return list;
				}
				return t;
			}
			else{
				if(s->link==NULL){
					break;
				}
				q=s;
				s=s->link;
			}
		}
		s->link=t;
		t->count=1;
		return list;
	}
}

