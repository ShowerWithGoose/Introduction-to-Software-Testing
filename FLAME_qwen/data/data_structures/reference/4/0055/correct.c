#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

# define MAXW  50

struct node {
	char word[MAXW];
	int js;
	struct node *link;
} ;
struct node *dclist = NULL;

int getW(FILE *bfp,char *w);
int searchW(char *w);
int insertW( struct node *p, char *w);

int main() {
	char wjname[32]= {"article.txt"};
	char word[MAXW];
	FILE *bfp;
	struct node *p;

	if((bfp = fopen(wjname, "r")) == NULL) {
		fprintf(stderr, "%s  can¡¯t open!\n",wjname);
		return -1;
	}

	while( getW(bfp,word) != EOF)
		if(searchW(word) == -1) {
			fprintf(stderr, "Memory is full!\n");
			return -1;
		}

	for(p=dclist; p != NULL; p=p->link)  {
		printf("%s %d\n", p->word, p->js);
	}

	return 0;
}

int insertW(struct node  *p, char *w) {
	struct node  *q;

	q = (struct node * )malloc(sizeof(struct node));
	if(q == NULL)
		return -1;
	strcpy(q->word, w);
	q->js = 1;
	q->link = NULL;
	if(dclist == NULL)
		dclist = q;
	else if (p == NULL) {
		q->link = dclist;
		dclist = q;
	} else {
		q->link = p->link;
		p->link = q;
	}
	return 0;
}

int searchW(char *w) {
	struct  node *p, *q=NULL;
	for(p=dclist; p != NULL; q=p,p=p->link) {
		if(strcmp(w, p->word) < 0)
			break;
		else if(strcmp(w, p->word) == 0) {
			p->js++;
			return 0 ;
		}
	}
	return insertW(q, w);
}

int getW(FILE *bfp,char word[]) {
	int i=0;
	char temp;

	while((temp=fgetc(bfp))!=EOF) {
		if(isalpha(temp)) {
			word[i]=tolower(temp);
			i++;
		} else if(i>0) {
			word[i]='\0';
			return 0;
		}
	}
	return EOF;
}

