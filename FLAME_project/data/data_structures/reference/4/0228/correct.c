#include <stdio.h>
#include <stdlib.h>

struct _node{
    char word[100];
    int line;
}node[1000];
int cmp ( const void *p1 , const void *p2 )
        {    struct _node *a=(struct _node *)p1;
             struct _node *b=(struct _node *)p2;
             return strcmp(a->word,b->word);
        }
int main()
{   FILE *fp;
    fp=fopen("article.txt","r");
    int i=0,j=0;
    char ch;
    while((ch=fgetc(fp))!=EOF){
        if(isalpha(ch)){
            node[i].word[j]=tolower(ch);
            j++;
        }
        else if(strlen(node[i].word)!=0){
            node[i].line=1;
            i++;
            j=0;
        }
    }
    qsort(node,i,sizeof(node[0]),cmp);
    for(j=0;j<i;j++){
        if(strcmp(node[j].word,node[j+1].word)==0){
            node[j+1].line+=node[j].line;
        }
        else if(node[j].line!=0){
            printf("%s %d\n",node[j].word,node[j].line);
        }
    }
    return 0;
}

