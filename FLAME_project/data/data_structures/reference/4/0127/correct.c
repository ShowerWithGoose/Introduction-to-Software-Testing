# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
struct node {
    char word[50];
    int count;
    struct node *link;
};
struct node *list = NULL;
int getWord(FILE *fp,char *w);
int searchWord(char *w);
int insertWord( struct node *p, char *w);

int main()
{
    char word[50];
    FILE *fp;
    struct node *p;
    fp = fopen("article.txt", "r");
    while( getWord(fp,word) != EOF)
    	searchWord(word);
    for(p=list; p != NULL; p=p->link)
    printf("%s %d\n", p->word, p->count);
    return 0;
}
int insertWord(struct node  *p, char *w)
{
    struct node  *q;

    q = (struct node *)malloc(sizeof(struct node));
    strcpy(q->word, w);
    q->count = 1;
    q->link = NULL;
    if(list == NULL)
        list = q;
    else if(p == NULL)
    {
	    q->link = list;
        list = q;
    }
    else
	 {
        q->link = p->link;
        p->link = q;
    }
    return 0;
}
int searchWord(char *w)
{
    struct  node *p, *q=NULL;
    for(p=list; p != NULL; q=p,p=p->link){
        if(strcmp(w, p->word) < 0)
            break;
        else if(strcmp(w, p->word) == 0){
            p->count++;
            return 0 ;
        }
    }
    return insertWord(q, w);
}
int getWord(FILE *fp,char word[])
{
    int i=0;
    char temp;
    while((temp=fgetc(fp))!=EOF){
        if(isalpha(temp)){
            word[i]=tolower(temp);
            i++;
        }
        else if(i>0)
		{
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}



