#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD  10000
struct tnode {
    char word[MAXWORD];
    int count;
    struct tnode *left,*right;
} BTNode, *BTNodeptr;
int getword(FILE *bfp,char *w);
struct tnode *addtree(struct tnode *p,char *w);
void treeprint( struct tnode *p);

int main()
{
    char word[MAXWORD];
    FILE *bfp;
    struct tnode *root=NULL; 
    
    if((bfp = fopen("article.txt", "r")) == NULL){ 
        fprintf(stderr, "%s  can¡¯t open!\n","article.txt");
        return -1;
    }
    while( getword(bfp,word) != EOF)
        root = addtree(root, word);
    
   

    
    treeprint(root);  
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w) 
{
    int cond;
    if( p == NULL )
    {
        p=(struct tnode*)malloc(sizeof(struct tnode));
        strcpy(p->word,w);
        p->count= 1;
        p->left= p->right= NULL;
    }
    else if ((cond = strcmp(w,p->word)) == 0)
         p->count ++;    
    else if ( cond < 0)  
         p->left =addtree(p->left, w);
    else 
         p->right = addtree(p->right, w);
    return (p);
}
             
void treeprint(struct tnode *p)
{
    if(p != NULL)
    {
        treeprint(p->left);
        printf("%s %d\n" ,p->word,p->count);
        treeprint(p->right);
    }
}

int getword(FILE *bfp,char word[])
{
    int i=0;
    char temp;

    while((temp=fgetc(bfp))!=EOF){
        if(isalpha(temp)){
            word[i]=tolower(temp);
            i++;
        }
        else if(i>0){
            word[i]='\0';
            return 0;
        }
    }
    return EOF;
}




