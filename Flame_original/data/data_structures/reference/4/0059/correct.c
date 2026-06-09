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
void treeprint(struct tnode *p);

int main(){
    char word[MAXWORD];
    FILE *bfp;
    struct tnode *root=NULL;
    char filename[32]="article.txt";
    
    if((bfp = fopen(filename, "r")) == NULL){//文档报错 
        fprintf(stderr, "%s  can’t open!\n",filename);
        return -1;
    }
    while( getword(bfp,word) != EOF){
        root = addtree(root, word);
	}
//    printf("%s %s" ,root->word,root->right->word);
//    if(root->right->right!=NULL){
//    	printf(" %s" ,root->right->right->word);
//	}
//    printf("\n");
    
    treeprint(root);  
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w){
    int cond;
    if( p == NULL ){
        p=(struct tnode*)malloc(sizeof(struct tnode));
        strcpy(p->word,w);
        p->count= 1;
        p->left= p->right= NULL;
    }
	else if ((cond = strcmp(w,p->word)) == 0){//串相等 
		p->count ++;
	}
    else if ( cond < 0){
    	p->left =addtree(p->left, w);
	}
    else{
		p->right = addtree(p->right, w);
	}
	
    return p;
}
             
void treeprint(struct tnode *p){//中序遍历输出 
    if(p != NULL){
        treeprint(p->left);
        printf("%s %d\n" ,p->word,p->count);
        treeprint(p->right);
    }
    return;
}

int getword(FILE *bfp,char word[]){
    int i=0;
    char temp;

    while((temp=fgetc(bfp))!=EOF){
        if(isalpha(temp)){//判断是否是英文字母 
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





