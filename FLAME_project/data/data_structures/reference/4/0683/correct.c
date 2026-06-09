#include<stdio.h>
#include<string.h>
struct article{
	char s[50];
	int n;
	struct article *next;
}word[500],*p,*begin,*now;
char c[1000];
void strlower(char c[]){
	int len,i=0;
	len=strlen(c);
	for(i=0;i<len;i++){
		if(c[i]>='A'&&c[i]<='Z'){
			c[i]=c[i]-'A'+'a';
		}
	}
	return;
}
int main(){
	FILE *in;
	int i=0,j=0,k=0,len,flag=0,t=0;
	in=fopen("article.txt","r");
	while(fgets(c,1000,in)!=NULL){
		len=strlen(c);
		strlower(c);
		for(j=0;j<len;j++){
			while(c[j]>='a'&&c[j]<='z'){
				word[i].s[k]=c[j];
				k++;
				j++;
				flag=1;
			}
			if(flag==1){
				word[i].n=1;
				i++;
				k=0;
				flag=0;
			}
		}
	}
	t=i;
	begin=&word[0];
	for(i=1;i<t;i++){
		now=NULL;
		for(p=begin;p!=NULL&&strcmp(word[i].s,p->s)>=0;now=p,p=p->next);
		if(now==NULL){
			word[i].next=begin;
			begin=&word[i];
		}else if(strcmp(word[i].s,now->s)==0){
			now->n++;
		}else{
			now->next=&word[i];
			word[i].next=p;
		}
	}
	for(p=begin;p!=NULL;p=p->next){
		printf("%s %d\n",p->s,p->n);
	}
	fclose(in);
	return 0;
}

