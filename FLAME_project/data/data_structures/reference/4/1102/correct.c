#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct word{
	char name[50];
	int num;
	struct word *next;
};
struct word *list=NULL;

int putin(FILE *fp,char c[])
{
    int i=0;
    char x;

    while((x=fgetc(fp))!=EOF){
        if(isalpha(x)){
            c[i]=tolower(x);
            i++;
        }
        else if(i>0){
            c[i]='\0';
            return 0;
        }
    }
    return EOF;
}

int insert(struct word  *p, char *w)
{
    struct word  *q;

    q = (struct word * )malloc(sizeof(struct word));
    if(q == NULL) return -1;
    strcpy(q->name, w);
    q->num = 1;
    q->next = NULL;
    if(list == NULL) 
        list = q;
    else if (p == NULL){
        q->next = list;
        list = q;
    }
    else {
        q->next = p->next;
        p->next = q;
    }
    return 0;
}

int find(char *c)
{
    struct word *p,*q=NULL; 
    for(p=list;p!=NULL;q=p,p=p->next){
        if(strcmp(c,p->name) < 0)
            break;
        else if(strcmp(c,p->name)== 0){
            p->num++;
            return 0 ;
        }
    }
    return insert(q,c);
}

int main(){
	FILE *fp;
	int i,j,k;
	char c[50];
	struct word *p; 
	
    fp = fopen("article.txt", "r");
    
    while(putin(fp,c)!=EOF){
       find(c);
	}
	
	for(p=list;p!=NULL;p=p->next){
		printf("%s %d\n",p->name,p->num);
	} 
	return 0;
}

