#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char line[99999];
char oword[40];

typedef struct myNOTElist{
	int num;//´ÊÆµ 
	char word[40];//ÄÚÈÝ 
	struct myNOTElist * next;
}List,*pList;

pList nbooks = NULL;

void Insert(pList p)
{
	pList temp;
	
	temp = (pList)malloc(sizeof(List));
	temp->num = 1;
	strcpy(temp->word, oword);
	temp->next = NULL;
	
	if (p == NULL){
		temp->next = nbooks;
		nbooks = temp;
	}
	else if(nbooks == NULL)  nbooks = temp;
	else {
		temp->next = p->next;
		p->next = temp;
	}
	return;
}

void FORwords(void)
{
	pList p,q;
	p = nbooks;
	q = NULL;
	while(p != NULL){
		if(strcmp(p->word,oword) == 0){
			p->num++;
			return;
		}
		else if(strcmp(oword, p->word) < 0) break;
		
		q=p,p=p->next;
	}
	Insert(q);
	return;
}

int main(void)
{
	pList p = nbooks;
	FILE *inp;
	inp = fopen("article.txt","r");
	
	int i,k;
	while(fgets(line,99999,inp)!=NULL){
		for(i=0,k=0;line[i]!='\0';i++){
			k=0;
			while(isalpha(line[i+k])) oword[k]=tolower(line[i+k]),k++;
			if(k!=0){
				oword[k]='\0';
				FORwords();
				if(line[i+k]=='\0') break;
				i = i+k;
			}
		}
	}
	
	p=nbooks;
	while(p!= NULL)
	{
		printf("%s %d\n", p->word, p->num);
		p=p->next;
	}
	
	fclose(inp);
	return 0;
}



