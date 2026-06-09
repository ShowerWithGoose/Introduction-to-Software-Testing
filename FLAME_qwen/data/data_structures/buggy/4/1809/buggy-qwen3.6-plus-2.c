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
        if(t->word!="") // @@ [Error] Invalid string comparison in C. The `!=` operator compares memory addresses, not string contents. This condition should be removed or replaced with `strcmp(t->word, "") != 0`.
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]="";
    char tmp; // @@ [Error] `fgetc` returns an `int`. Declaring `tmp` as `char` may cause the `EOF` comparison to fail (especially if `char` is unsigned), resulting in an infinite loop. It should be `int tmp;`.
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
    if(root!=NULL) // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.
        printf("%s ",root->word); // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.
    if(root->right!=NULL) // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.
    {
        printf("%s ",root->right->word); // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.
        if(root->right->right!=NULL) // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.
            printf("%s ",root->right->right->word); // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.

    }
    printf("\n"); // @@ [Error] Unnecessary debug output that violates the specified output format. Should be removed.
    inorder(root);
    return 0;
}