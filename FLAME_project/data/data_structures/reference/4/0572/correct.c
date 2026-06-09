#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int findletter(char *p,int i){
	int flag=0;
	while(isalpha(*(p+i))==0&&*(p+i)!='\n'&&*(p+i)!='\0'){
		i++;
	}
	if(isalpha(*(p+i))) return i;
	else return 0;
}
typedef  struct linklist{
	char word[20];
	int time;
	struct linklist *next;
}freq;
int main() {
	FILE *fp;
	char s[101];
	int i,j,flag=1;
	freq *p,*temp,*a;
	p=(freq*)malloc(sizeof(freq));
	p->next=NULL;
	if((fp=fopen("article.txt","r+"))==NULL){
		printf("error");
		exit(1);
	}
	
 	while(fgets(s,99,fp)!=NULL){
 		//printf("%s\n",s);
 		if(s[0]=='\n') continue;
		for(i=0;isalpha(s[i])==0;i++);
		
		//printf("%s",s);
		do{
			flag=1;
			a=(freq*)malloc(sizeof(freq));
			a->next=NULL;
			for(j=0;j<20;j++) a->word[j]='\0';
			for(j=0;isalpha(s[i]);j++,i++){
				if(isupper(s[i])) s[i]=s[i]+32;
				a->word[j]=s[i];
			}
			a->time=1;
			if(p->next==NULL) {
				p->next=a;
				flag=0;
			}
			else if(strcmp(a->word,p->next->word)<0) {
				a->next=p->next;
				p->next=a;
				flag=0;
			}
			else{
				for(temp=p->next;temp->next!=NULL;temp=temp->next){
					if(strcmp(a->word,temp->word)>0&&strcmp(a->word,temp->next->word)<0){
						a->next=temp->next;
						temp->next=a;
						flag=0;
						break;
					}
					else if(strcmp(a->word,temp->word)==0) {
						temp->time++;
						flag=0;
						break;
					}
				}
			}
			if(flag){
				if(strcmp(a->word,temp->word)>0) temp->next=a;
				else if(strcmp(a->word,temp->word)==0){
					temp->time++;
				}
			}
			
		}while(i=findletter(s,i)); 
		for(j=0;j<101;j++) s[j]='\0';
	}
	for(temp=p->next;temp!=NULL;temp=temp->next){
		for(i=0;isalpha(temp->word[i]);i++) printf("%c",temp->word[i]);
		printf(" %d\n",temp->time);
	}
	return 0;
}



