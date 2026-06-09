#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(A,B) ((A>B)?A:B)
#define MIN(A,B) ((A>B)?B:A)
typedef struct Node
{   
    struct Node *left,*right;
    int height,num;
    char *s; 
}BT;

BT* NewNode(char s[])
{
    BT* node =( BT* ) malloc (sizeof(BT));
    node->s =(char *) malloc (strlen(s)+1);
    strcpy(node->s,s);
    node->left=NULL;node->right=NULL;
    node->height=1;
    node->num=1;
    return node;
}

int com(char s1[],char s2[])
{
    return strcmp(s1,s2);
}

int hi(BT* node)
{
    if(node==NULL) return 0;
    return node->height;
}

void push_up(BT *node)
{
	node->height=1+MAX(hi(node->left),hi(node->right));
	return;
}

int get_bal(BT* node)
{
    if(node==NULL) return 0;
    return hi(node->left)-hi(node->right);
}

BT* ll_rotate(BT* y)
{
    BT* x=y->left;
    y->left=x->right;
    x->right=y;
    push_up(y);
    push_up(x);
    return x;
}

BT* rr_rotate(BT* y)
{
    BT* x=y->right;
    y->right=x->left;
    x->left=y;
    push_up(y);
    push_up(x);
    return x;
}

BT* AVL(BT* node)
{
    int bal=get_bal(node);
    if(bal>1)
    {
        if(get_bal(node->left)<0) node->left=rr_rotate(node->left);
        return ll_rotate(node);
    }
    else if(bal<-1)
    {
        if(get_bal(node->right)>0) node->right=ll_rotate(node->right);
        return rr_rotate(node);
    }
    push_up(node);
    return node;
}

BT* insert(BT* node,char s[])
{
    if(node==NULL) return NewNode(s);
    if(com(s,node->s)<0) node->left=insert(node->left,s);
    else if(com(s,node->s)>0) node->right= insert(node->right,s);
    else 
    {
        node->num++;
        return node;
    }
    node=AVL(node);
    return node;
}


void dfs_free(BT *node)
{
	if(node==NULL) return;
	dfs_free(node->left);dfs_free(node->right);
	node->left=NULL;node->right=NULL; 
 	free(node);
	return;
}

void dfs(BT *node)
{
    if(node==NULL) return;
    dfs(node->left);
    printf("%s %d\n",node->s,node->num);
    dfs(node->right);
    return;
}

int main()
{
    BT  *root=NULL;
    FILE *IN;
    char s[300];
    IN=fopen("article.txt","r");
    while(fscanf(IN,"%s",s)!=EOF)
    {
        int len=strlen(s),j=0,i,pos=-1;
        for( i=0;i<=len;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                if(pos==-1) pos=j;
                s[j]=s[i];
                j++;
            }
            else if(s[i]>='A'&&s[i]<='Z')
            {
                if(pos==-1) pos=j;
                s[j]=s[i]-'A'+'a';
                j++;
            }
            else if(pos!=-1) 
            {
                s[j]='\0';
                j++;
                //printf("**%s\n",s+pos);
                root=insert(root,s+pos);
                pos=-1;
            }
        }
        
        //printf("%s\n",s);
        //fgetc(IN);
        
    }
    dfs(root);
    dfs_free(root);
    return 0;
}
