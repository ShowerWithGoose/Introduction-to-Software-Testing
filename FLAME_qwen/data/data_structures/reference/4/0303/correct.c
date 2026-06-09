#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char data;
	int count;
	struct Node *children[26];
} *root;

struct Node * newNode(char c);

void init(){
	root = newNode(0);
}

struct Node * newNode(char c){
	struct Node *p = malloc(sizeof(struct Node));
	p->data = c;
	for(int i=0; i<26; i++){
		p->children[i] = NULL;
	}
	p->count = 0;
	return p;
};

void addWord(char *s){
	int n = strlen(s);
	struct Node *p = root;
	for(int i=0; i<n; i++){
		if(p->children[s[i]-'a'] == NULL){
			p->children[s[i]-'a'] = newNode(s[i]);
		}
		p = p->children[s[i]-'a'];
	}
	p->count++;
}

char word[100];
void print(struct Node *node, int depth){
	word[depth] = node->data;
	if(node->count> 0){
		word[depth+1] = '\0';
		printf("%s %d\n", word+1, node->count);
	}
	
	for(int i=0; i<26; i++){
		if(node->children[i] != NULL){
			print(node->children[i], depth+1);
		}
	}
}

char utol(char c){
	if(c>='A' && c<='Z')
		return c-'A'+'a';
	return c;
}


int main(){
	init();
	
	FILE *in;
	in = fopen("article.txt", "r");
	
	char s[100];
	int n=0;
	char c;
	while((c = fgetc(in)) != EOF){
		c = utol(c);
		if(c>='a' && c<='z')
			s[n++] = c;
		else if(n!=0){
			s[n] = '\0';
			n = 0;
			addWord(s);
		}
	}
	if(n!=0){
		s[n] = '\0';
		n = 0;
		addWord(s);
	}
	
	print(root, 0);
	
	
	return 0;
}

