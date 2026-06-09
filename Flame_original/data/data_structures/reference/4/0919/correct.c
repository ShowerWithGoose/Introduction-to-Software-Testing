#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct word{
	char s[30];
	int count;
	struct word* next;
};

int getword(FILE *in);
void searchword(char *ss);
void insertword(struct word *q,char *ss);
char ss[30];
struct word *first=NULL;
	 

int main()
{
	FILE *in;
	char *s;
	struct word* ptr;
	in = fopen("article.txt","r");
	
	first = NULL;
	while(getword(in) != 0)
	{
		searchword(ss);
	}
//	searchword(ss);
	ptr = first;
	while(ptr != NULL){
		printf("%s %d\n",ptr->s,ptr->count);
		ptr = ptr->next; 
	}
	return 0;
}

int getword(FILE *in)
{
    char ch;
    int i=0;
    
    while(!isalpha(ch=getc(in)))
	{
		if(ch == EOF)
		{
			return 0;
		}else continue;
	 } 
	do{
		ch = tolower(ch);
		ss[i++] = ch;
	} while(isalpha(ch = fgetc(in)));
	ss[i] = '\0';
	return 1; 
/*	while(1) {
		if((ch=fgetc(in)) != EOF)
		{
		if (!isalpha(ch)) break;
		ch = tolower(ch);
		ss[i++] = ch;
		}else{
			ss[i] = '\0'; 
			return 0;
		}
	}
	ss[i] = '\0';
	return 1;*/
//如果字母前为非字母字符，则会记为'\0'字符串	
}
void searchword(char* ss)
{
	struct word *p,*q;
	p = first;
	while(p != NULL)
	{
		q = p;
		if(strcmp(ss,p->s) == 0)
		{
		   p->count ++;
		   break;	
		}
		p = p->next;
	}
	insertword(q,ss);
}

void insertword(struct word *q,char *ss)
{
	struct word *p,*t;
	p = (struct word*)malloc(sizeof(struct word));
	strcpy(p->s,ss);
	p->count = 1;
	if (first == NULL)
	{
		first = p;
		t = p;
		p->next = NULL;
	}else if(strcmp(q->s,p->s)<0){
		q->next = p;
		p->next = NULL;
	}else if(strcmp(first->s,p->s)>0){
		p->next = first;
		first = p;
	}else{
		t = first;
		while(t->next != NULL)
		{
			if(strcmp(t->s,p->s)<0 && strcmp(t->next->s,p->s)>0)
			{
				p->next = t->next;
				t->next = p; 
				return;
			}
			t = t->next;
		}
	}
}
























