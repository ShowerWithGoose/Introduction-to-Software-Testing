#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct words{
	char word[20];
	int times;
	struct words *next;
};
struct words *read_passage(FILE *in);
struct words *create_words(struct words *previous,char word[]);
void release(struct words *head);
int search(char word[],struct words *line);
void array(struct words *line);

int main(){
struct words *word_line, *pi;
FILE *in;
in = fopen("article.txt","r");
word_line = read_passage(in);
pi = word_line->next;
array(pi);
while(1){
	printf("%s",pi->word);
	printf(" %d\n",pi->times);
	if(pi->next == NULL)break;
	pi = pi->next;
}

fclose(in);
release(word_line);
return 0;
} 

void array(struct words *line){
	struct words *pi_1, *pi_2;
	char temp[20];
	pi_1 = line;
	while(pi_1->next != NULL){
		pi_2 = pi_1->next;
		while(1){
			if(strcmp(pi_1->word,pi_2->word)>0){
				strcpy(temp,pi_1->word);
				strcpy(pi_1->word,pi_2->word);
				strcpy(pi_2->word,temp);
				pi_1->times ^= pi_2->times;
				pi_2->times ^= pi_1->times;
				pi_1->times ^= pi_2->times;
			}
			if(pi_2->next == NULL)break;
			pi_2 = pi_2->next;
		}
		pi_1 = pi_1->next;
	}
	
}

struct words *read_passage(FILE *in){
	char c, word[20];
	struct words *line, *pi;
	line = (struct words *)malloc(sizeof(struct words));
	line->word[0] = '0';
	line->next = NULL;
	pi = line;
	while(1){
		for(int i=0;;i++){
			c=fgetc(in);
			if(c == EOF)return line;
			if(c<64){
				word[i] = '\0';
				break;
			}
			word[i] = (c>='a'&&c<='z'?c:c-'A'+'a');
		}
		if(search(word,line) == 1)continue;
		else if(word[0]!='\0')pi = create_words(pi,word);
	}
	
};

int search(char word[],struct words *line){
	struct words *pi;
	pi = line;
	while(1){
		if(strcmp(word,pi->word)==0){
			(pi->times)++;
			return 1;
		}
		if(pi->next==NULL)break;
		pi = pi->next;
	}
	return 0;
}

struct words *create_words(struct words *previous,char word[]){
	struct words *pi;
	pi = (struct words *)malloc(sizeof(struct words));
	strcpy(pi->word,word);
	previous->next = pi;
	pi->times = 1;
	pi->next = NULL;
	return pi;
};

void release(struct words *head){
	struct words *pi;
	while(head->next != NULL){
		pi = head;
		head = head->next;
		free(pi);
	}
	free(head);
}

