#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX 1000

char str[100],word[100];
int i,j,k;
FILE *in;
typedef struct Link{
	char elem[100];
	int deg;
	struct Link* next;
}link;
link* p = NULL;

void Tolower();
link* initLink();
link* insert(char word[],link* p);
link* check(char word[],link* p);
int main(){
	in=fopen("article.txt","r");
	p = initLink();
	while(fscanf(in,"%s",str)!=EOF){
		Tolower();
	}
	fclose(in);
	link* temp = p;
	while(temp != NULL){
		printf("%s %d\n",temp->elem,temp->deg);
		temp = temp->next;
	}
	return 0;
}

void Tolower(){
	int cont = 0;
	while(str[cont] != '\0'){
		j = 0;
		for(i = cont; str[i] != '\0'; i++, cont++){
			if((str[i] >= 'a'&& str[i] <= 'z')|| (str[i] >= 'A'&& str[i] <= 'Z')){
				word[j] = tolower(str[i]);
				j++;
			}
			else{
				if(!j) 
					continue;
				word[j] = '\0';
				p = check(word,p);
				j = 0;
				break;
			}
		}
	}
	if(j){
		word[j] = '\0';
		p = check(word,p);
	}
	return ;
}

link* initLink(){
	link* p = NULL;
	link* temp = (link*)malloc(sizeof(link));
	fscanf(in,"%s",str);
	Tolower(); 
	strcpy(temp->elem,word);
	temp->deg = 1;
	temp->next = NULL;
	p = temp;
	return p;
}


link* check(char word[],link* p){
	if(p == NULL){
		p = (link*)malloc(sizeof(link));
		strcpy(p->elem, word);
		p->deg = 1;
		p->next = NULL;
		return p;
	}
	link* temp = p;
	while(temp != NULL){
		if(strcmp(temp->elem,word) == 0){
			temp->deg++;
			return p;
		}
	temp = temp->next;
	}	
	p = insert(word,p);
	return p;
	
}

link* insert(char word[],link* p){
	link* temp = p;
	if(strcmp(p->elem,word) > 0){
		link* a = (link*)malloc(sizeof(link));	
		strcpy(a->elem,word);
		a->deg = 1;
		a->next = p;
		p = a;
		return p;
	}
	while(temp->next != NULL){
		if(strcmp(temp->next->elem,word) > 0){
			link* a = (link*)malloc(sizeof(link));	
			strcpy(a->elem,word);
			a->deg = 1;
			a->next = temp->next;
			temp->next = a;
			return p;
		}
		temp = temp->next;
	}
	link* a = (link*)malloc(sizeof(link));
	a->next = NULL;
	strcpy(a->elem,word);
	a->deg = 1;
	temp->next = a;
	return p;
}




