#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct node {
    char word[32];
    int count;
    struct node *link;
} ; 

struct node *Wordlist = NULL; //单词表头指针
int searchword(char *w);
int insertWord( struct node *p, char *w);

int main()
{
FILE *in;
in = fopen("article.txt", "r");
struct node *p;
char line[1024],word[32];
int i,j;
while (fgets(line,1023,in)!=NULL){
	for (i=0,j=0;line[i]!='\0';i++){
		if ((line[i]<'A'||line[i]>'z'||(line[i]>'Z'&&line[i]<'a'))&&word[0]!=0){
			word[j]='\0';
			searchword(word);
			memset(word,0,32*sizeof(char));
			j=0;
		}
		else if (line[i]<'A'||line[i]>'z'||(line[i]>'Z'&&line[i]<'a'))
		continue; 
		else{
			if (line[i]<'a'){
			word[j]=line[i]+32;
			j++;
			}
			else{
			word[j]=line[i];
			j++;}
		}
	}
}
for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
        printf("%s %d\n", p->word, p->count);

return 0; 
}

/*在链表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/
int searchword(char *w)
{
struct  node *p, *q=NULL; //q为p的前序结点指针
for(p=Wordlist; p != NULL; q=p,p=p->link){
    if(strcmp(w, p->word) < 0) 
 break;
    else if(strcmp(w, p->word) == 0){
         p->count++;
         return 0 ;
    }
}
return insertWord(q, w);
}

/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/
int insertWord(struct node  *p, char *w)
{
      struct node  *q;

      q = (struct node * )malloc(sizeof(struct node));
      if(q == NULL) return -1; //没有内存空间
      strcpy(q->word, w);
      q->count = 1;
      q->link = NULL;              
      if(Wordlist == NULL) //空链表
           Wordlist = q;
      else if (p == NULL){ //插入到头结点前
           q->link = Wordlist;
           Wordlist = q;
       }
       else {
           q->link = p->link;
           p->link = q;
       }
      return 0;
}










