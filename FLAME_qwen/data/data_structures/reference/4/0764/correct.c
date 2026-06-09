#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
	char word[32];
	int count;
	struct node *link;
}lnode,*linklist;
linklist first=NULL;
int searchword(char *w);
int insertword(linklist p,char *w);
int main(){
	FILE *in;
	char f,word[32]={"\0"};
	int i=0;
	in=fopen("article.txt","r");
	linklist p;
    while(~fscanf(in,"%c",&f)){
    	if(tolower(f)>='a'&&tolower(f)<='z'){
    		word[i]=tolower(f);
    		i++;
	    }
	    else{
	    	if(word[0]!='\0'){
	    	searchword(word);
	    	for(int j=0;j<i;j++)
	    		word[j]='\0';
	    	i=0;
			}
		}
	}
	for(p=first;p!=NULL;p=p->link){
		printf("%s %d\n",p->word,p->count);
	}	
	fclose(in);
	    return 0;
}
int searchword(char *w){
	linklist p,q=NULL;
	for(p=first;p!=NULL;q=p,p=p->link){
		if(strcmp(w,p->word)<0)
		break;
		else if(strcmp(w,p->word)==0){
			p->count++;
			return 0;
		}
	}
	return insertword(q,w);
}
int insertword(linklist p,char *w){
	linklist q;
	q=(linklist)malloc(sizeof(lnode));
	strcpy(q->word,w);
	q->count=1;
	q->link=NULL;
	if(first==NULL)
		first=q;
		else if(p==NULL){
			q->link=first;
			first=q;
		}
		else{
			q->link=p->link;
			p->link=q;
		}
		return 0;
}

