#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
#define tolower(c) 	(c>='A'&&c<='Z'?'a'-'A'+ c : c)
#define  LETTER 'a'
#define  DIGIT '0'
char type(int c)	/* return type of ASCII character */
{
if( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
return ( LETTER );
else if ( c >='0'&& c <= '9')
return ( DIGIT );
else return (c);
}
int getword(char s[], FILE *fp){
    int c,i = 0;
    while(type(c=fgetc(fp))!= LETTER){
    	c=tolower(c);
        if(c == EOF) return c;
        else continue;
    }
    c=tolower(c);
    s[i++] = c;   //find the first letter
	while((c=fgetc(fp))!=EOF){
         if(type(c)!=LETTER)
              break;   
        c=tolower(c); 
        s[i++] = c;
    }
    s[i]='\0';
    return 1;
}

struct tag_node{
	char w[2000];
	int times;
	struct tag_node *next;
}; 
typedef struct tag_node node;
int search(char *word);
void insert(char *word);
char *turn(char *word);
void put_list(node *head);
node *head=NULL;
int main()
{
	FILE *in,*out;
	in=fopen("article.txt","r");
	if(NULL==in) printf("not opened");
	char *word;
	word=(char*)malloc(sizeof(char)*max);	
	while(getword(word,in)!=-1){
		/*if(strcmp(word,"since1972")==0){
			strcpy(word,"since");
		}*/
		if(search(word)==0){
			insert(word);
		}
	}
	put_list(head);
	fclose(in);
    return 0;
}
char *turn(char *word){
	int len=strlen(word);
	int i,j;
	for(i=0;i<len;){
		if(word[i]>='A'&&word[i]<='Z'){
			word[i]+='a'-'A';
			i++;
		}
		else if(word[i]<'A'||word[i]>'Z'&&word[i]<'a'||word[i]>'z'){
			if(i==len) len--;
			else{
				for(j=i;j<len;j++){
					word[j]=word[j+1];
				}
				len--;
			}
		}
		else if(word[i]>='a'&&word[i]<='z'){
			i++;
		}
	}
	return word;
}
int search(char *word){
	node *p,*q;
	for(p=head;p!=NULL;p=p->next){
		if(strcmp(p->w,word)==0){
			p->times+=1;
			return 1;
		}
	}
	return 0;
}
void insert(char *word){
	node *p,*q,*r;
	int flag=0;
	p=(node*)malloc(sizeof(node));
	strcpy(p->w,word);
	p->times=1;
	p->next=NULL;
	if(head==NULL){
		head=p;
	}
	else{
		for(q=head;q->next!=NULL;q=q->next){
			if(strcmp(p->w,q->w)>0&&strcmp(p->w,q->next->w)<0){
				p->next=q->next;
				q->next=p;
				flag=1;
				break;
			}
		}
		if(q->next==NULL){
			if(strcmp(p->w,q->w)>0){
				p->next=q->next;
				q->next=p;
				flag=1;
			}
		}
		if(flag==0){
			p->next=head;
			head=p;
		}
		
	}
}


void put_list(node *head){
	node *p;
	for(p=head;p->next!=NULL;p=p->next){
		printf("%s %d\n",p->w,p->times);
	}
	if(p->next==NULL){
		printf("%s %d",p->w,p->times);
	} 
}




