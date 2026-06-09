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
        if(t->word!="") // @@ [Comparing a char array with a string literal using != is invalid in C; this condition is always true and meaningless. It should be removed.]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]=""; // @@ [b is initialized as an empty string but has size 1, so it holds only '\0'. Using strcpy(a, b) sets a to empty, but this is unnecessarily complex and error-prone.]
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
                strcpy(a,b); // @@ [This resets a to an empty string, but b is just "\0". A simpler and safer approach is to set a[0] = '\0';]
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
    if(root!=NULL)
        printf("%s ",root->word); // @@ [This prints extra output not required by the problem; the problem only requires the inorder traversal output.]
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ [Same as above: extra debug-style output that violates the specified output format.]
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ [Same issue: extra output not part of the required lexicographical frequency list.]

    }
    printf("\n"); // @@ [This prints an extra newline before the correct output, which may cause formatting mismatch.]
    inorder(root);
    return 0;
}