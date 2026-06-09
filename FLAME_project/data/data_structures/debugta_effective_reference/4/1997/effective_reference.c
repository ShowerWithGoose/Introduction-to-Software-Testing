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
void searchword(char *Word);
void insertword(struct word *tail,char *Word);
char Word[30];
struct word *list=NULL;
	 

int main()
{
	FILE *in;
	char *s;
	struct word* ptr;
	in = fopen("article.txt","r");
	
	list = NULL;
	while(getword(in) != 0)
	{
		searchword(Word);
	}
//	searchword(ss);
	ptr = list;
	while(ptr != NULL){
		printf("%s %d\n",ptr->s,ptr->count);
		ptr = ptr->next; 
	}
	return 0;
}

int getword(FILE *in)
{
    char ch;
    int shu=0;
    
    while(!isalpha(ch=getc(in)))
	{
		if(ch == EOF)
		{
			return 0;
		}else continue;
	 } 
	do{
		ch = tolower(ch);
		Word[shu++] = ch;
	} while(isalpha(ch = fgetc(in)));
	Word[shu] = '\0';
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
void searchword(char* Word)
{
	struct word *newnode,*tail;
	newnode = list;
	while(newnode != NULL)
	{
		tail = newnode;
		if(strcmp(Word,newnode->s) == 0)
		{
		   newnode->count ++;
		   break;	
		}
		newnode = newnode->next;
	}
	insertword(tail,Word);
}

void insertword(struct word *tail,char *Word)
{
	struct word *newnode,*first;
	newnode = (struct word*)malloc(sizeof(struct word));
	strcpy(newnode->s,Word);
	newnode->count = 1;
	if (list == NULL)
	{
		list = newnode;
		first = newnode;
		newnode->next = NULL;
	}else if(strcmp(tail->s,newnode->s)<0){
		tail->next = newnode;
		newnode->next = NULL;
	}else if(strcmp(list->s,newnode->s)>0){
		newnode->next = list;
		list = newnode;
	}else{
		first = list;
		while(first->next != NULL)
		{
			if(strcmp(first->s,newnode->s)<0 && strcmp(first->next->s,newnode->s)>0)
			{
				newnode->next = first->next;
				first->next = newnode; 
				return;
			}
			first = first->next;
		}
	}
}
























