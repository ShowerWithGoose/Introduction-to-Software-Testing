#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TN{
	char *Word;
    int Times;
    struct TN *left;
    struct TN *right;
}TreeNode;

int getword(char *w,FILE *in);
TreeNode *BST_Insert(TreeNode *root,char *w);
void InOrderTree(TreeNode *root);
char CurrentWord[500];

int main(){
	FILE *in;
	in=fopen("article.txt","r");
	TreeNode *root=NULL;
	while(getword(CurrentWord,in)!=EOF){
		root=BST_Insert(root,CurrentWord);
	}
	InOrderTree(root);
	return 0;
}

int getword(char *w,FILE *in){
    int i=0;
    char ch;
    while((ch=fgetc(in))!=EOF){
        if(ch>='a'&&ch<='z') w[i++]=ch;
        else if(ch>='A'&&ch<='Z') w[i++]=ch-'A'+'a';
        else if(i>0) break;
    }
    w[i]='\0';
    return ch;
}

TreeNode *BST_Insert(TreeNode *root,char *w){
    if(!root){
        root=(TreeNode *)malloc(sizeof(TreeNode));
        root->Word=(char *)malloc(strlen(w)+1);
        strcpy(root->Word,w);
        root->Times=1;
        root->left=root->right=NULL;
    }
    else{
    	int d=strcmp(root->Word,w);
        if(d>0) root->left=BST_Insert(root->left,w);
        else if(d<0) root->right=BST_Insert(root->right,w);
        else root->Times++;
    }
    return root;
}

void InOrderTree(TreeNode *root){
    if(root==NULL) return;
    InOrderTree(root->left);
    printf("%s %d\n",root->Word,root->Times);
    InOrderTree(root->right);
}

