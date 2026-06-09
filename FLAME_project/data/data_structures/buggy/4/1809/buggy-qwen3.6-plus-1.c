#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct node
{
    char word[50];
    int num;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, char *tword)
{
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        strcpy(p->word,tword);
        p->num=1;
        p->left = p->right = NULL;
    }
    else if( strcmp(p->word,tword)>0)
        p->left = insertBST(p->left, tword);
    else if( strcmp(p->word,tword)<0)
        p->right = insertBST(p->right,tword);
    else
        (p->num)++; //树中存在该元素
    return p;
}
void  inorder(BTNodeptr t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        if(t->word!="") // @@ [Error: Comparing a char array with a string literal using != compares memory addresses, not content. This condition is always true for valid nodes. It should be removed or replaced with strlen check if necessary, but since empty words shouldn't be inserted, the check is redundant and incorrect here.]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]="";
    char tmp;
    BTNodeptr  root=NULL;
    FILE* fp=fopen("article.txt","r");
    int j=0;
    while((tmp=fgetc(fp))!=EOF)
    {
        if(!((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z')))
        {
            if(a[0]!='\0')
            {
                a[j]='\0';
                root=insertBST(root,a);
                strcpy(a,b);
                j=0;
            }
        }
        else if(tmp>='a'&&tmp<='z')
            a[j++]=tmp;
        else if(tmp>='A'&&tmp<='Z')
        {
            a[j]=tmp+'a'-'A';
            j++;
        }
    }
    fclose(fp);
    if(root!=NULL) // @@ [Error: These lines manually print specific nodes from the tree structure, which violates the requirement to output ONLY the sorted word frequencies. This produces extra output at the beginning ("i will you ") that causes the Wrong Answer.]
        printf("%s ",root->word);
    if(root->right!=NULL) // @@ [Error: Part of the incorrect manual printing logic that outputs extra data not required by the problem statement.]
    {
        printf("%s ",root->right->word);
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word);

    }
    printf("\n"); // @@ [Error: Prints an extra newline and is part of the block producing incorrect initial output.]
    inorder(root);
    return 0;
}