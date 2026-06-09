#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
	char word[32];
	int count;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
char a[32];
char ch;
void deletesame(Nodeptr head){
	Nodeptr record=head,r,p;
    while(record!=NULL){
        r=record;
        p=record->link;
        while(p!=NULL){
            //若有相同的元素，则删除；否则两个指针继续向下走
            if(strcmp(record->word,p->word)==0){
            	record->count=record->count+p->count;
                r->link=p->link;
                free(p);
                p=r->link;
            }else{
                r=r->link;
                p=p->link;
            }
        }
        record=record->link;
    }
}
void bubble(Nodeptr head)
{
	char swap[20];
	int change;
    if(head==NULL) return;
    Nodeptr end=NULL;
    while(end!=head)
    {
        Nodeptr p=head;
        Nodeptr plink=head->link;
        while(plink!=end)
        {
            if(strcmp(p->word,plink->word)>0)
            {
            	strcpy(swap,p->word);
                strcpy(p->word,plink->word);
                strcpy(plink->word,swap);
                change=p->count;
                p->count=plink->count;
                plink->count=change;
            }
            p=p->link;
            plink=plink->link;
        }
        end=p;
    }
}
int main()
{
	memset(a,'\0',sizeof(a));
	Nodeptr p,r,head=NULL;
	int num=0,flag=1;
	FILE *in; 
	in=fopen("article.txt","r");
	while((ch=fgetc(in))!=EOF){
		if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'){
			a[num++]=tolower(ch);
			flag=0;
		}
		else if(!isalpha(ch)&&flag==0){
			flag++;
			r=(Nodeptr)malloc(sizeof(Node));
            r->count=1;
            r->link=NULL;
            memset(r->word,'\0',32);
            strcpy(r->word,a);
            memset(a,'\0',sizeof(a));
            num=0;
        if (head==NULL)
            head=p=r;
        else{
            p->link=r;          
            p=p->link;
                }
            }
		}
	
	fclose(in);
	deletesame(head);
	bubble(head);
	p=head;
	while(p!=NULL){
		printf("%s %d\n",p->word,p->count);
		p=p->link;
	}
}



