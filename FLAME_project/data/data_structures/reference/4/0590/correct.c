#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	char word[100];
	int count;
	struct node*link;
};
typedef  struct node *Nodeptr;
typedef  struct node Node;
Nodeptr head=NULL;
char s[100];char c;
int getword(FILE*in,char*s){
    int i=0;memset(s,0,100);
    while(1){
        c=fgetc(in);
       if(c>='A'&&c<='Z'){
        s[i]=c-'A'+'a';
i++;    }
    else if(c>='a'&&c<='z'){
        s[i]=c;i++;
    }else{
    break;}
}
if(c==EOF){
    return c;
}
if(s[0]=='\0'){
    return getword(in,s);
}return 0;
}
int Searchword(char*s){Nodeptr p, q=NULL;
for(p=head; p != NULL; q=p,p=p->link){
    if(strcmp(s, p->word) < 0){
 break;
	}

    else if(strcmp(s, p->word) == 0){
         p->count++;
         return 0 ;
    }
}
return insertWord(q,s);
}
int insertWord(Nodeptr p,char*s){Nodeptr q=NULL;
      q = (Nodeptr)malloc(sizeof(Node));
      strcpy(q->word, s);
      q->count = 1;
      q->link = NULL;
      if(head == NULL)
           head=q;
      else if (p == NULL){
           q->link=head;
           head=q;
       }
       else {
           q->link = p->link;
           p->link = q;
       }
      return 0;
}

int main(){Nodeptr p=NULL;
FILE *in;
in = fopen("article.txt", "r");
while(getword(in,s)!=EOF){
Searchword(s);
}
for(p=head;p!=NULL;p=p->link){
    printf("%s %d\n",p->word,p->count);
}
fclose(in);
return 0;}

