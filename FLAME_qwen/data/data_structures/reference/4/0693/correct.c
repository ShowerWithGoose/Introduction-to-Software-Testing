#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
	char word[35];
	int count;
	struct node*link;
};
struct node*Wordlist=NULL;
int getWord(FILE*bfp,char*w);
char w[35];
int main(){
	FILE *bfp;
	bfp=fopen("article.txt","r");
	struct node *p,*q,*r;
	p=q=r=NULL;
	while(getWord(bfp,w)!=EOF){
	
	    for(p=Wordlist;p!=NULL;q=p,p=p->link){
	    	if(strcmp(w,p->word)==0){
	    		p->count++;
	    		break;
			}
			
			
			else if(strcmp(w,p->word)<0){
			   r=(struct node*)malloc(sizeof(struct node));
			   strcpy(r->word,w);
			   r->count=1;
			   if(p==Wordlist){
			   	  q=Wordlist;
			   	  r->link=q;
			   	  Wordlist=r;
			   	
			   	  
			   	  break;
			   }
			   else{
			   	r->link=p;
			   q->link=r;
			   break;
			   }
			  
			}
		}
		
		if(p==NULL){
			r=(struct node*)malloc(sizeof(struct node));
			strcpy(r->word,w);
			r->count=1;
			if(p==Wordlist){
			   	  q=Wordlist;
			   	  r->link=q;
			   	  Wordlist=r;
			
			   }
			   else{
			   	r->link=p;
			   q->link=r;
			   }
		
		}
	
			
	}
	
	for(p=Wordlist;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->count);
	}
	
	return 0;
}


int getWord(FILE*bfp,char w[]){
	int i=0;
	char c;
	while((c=fgetc(bfp))!=EOF){
	if((c>=65&&c<=90)||(c>=97&&c<=122)){
		w[i]=tolower(c);
		i++;
	}
	else if(i>0){
		w[i]='\0';
		return 0;
	}	
	}
	
}


