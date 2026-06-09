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
        if(t->word!="") // @@ [This condition is always true because t->word is an array, not a pointer; comparing array to string literal is invalid and meaningless. It should be removed.]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]=""; // @@ [b is an array of size 1 containing only '\0', so strcpy(a,b) sets a[0]='\0', but this is error-prone and unnecessary. Better to use a[0]='\0' directly.]
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
                strcpy(a,b); // @@ [This resets a by copying an empty string, but it's fragile. Also, after the loop ends, the last word may not be processed if file doesn't end with non-alpha.]
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
        printf("%s ",root->word); // @@ [This prints extra words before the inorder output, causing wrong answer. These debug prints must be removed.]
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ [This prints extra words before the inorder output, causing wrong answer. These debug prints must be removed.]
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ [This prints extra words before the inorder output, causing wrong answer. These debug prints must be removed.]

    }
    printf("\n"); // @@ [This prints an extra newline before the correct output, contributing to wrong format.]
    inorder(root);
    return 0;
}