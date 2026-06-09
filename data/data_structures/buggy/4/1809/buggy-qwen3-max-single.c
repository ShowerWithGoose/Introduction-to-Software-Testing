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
        if(t->word!="") // @@ [Comparing string with "" using != is invalid in C; should use strcmp or check first character]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]=""; // @@ [b is an array of size 1 containing only '\0', but used in strcpy(a,b) which may not reset 'a' properly]
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
                strcpy(a,b); // @@ [strcpy(a,b) where b is just "\0" is inefficient and error-prone; better to set a[0]='\0']
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
        printf("%s ",root->word); // @@ [This prints extra output not in expected format; problem requires only inorder output]
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ [This prints extra output not in expected format; violates output specification]
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ [This prints extra output not in expected format]

    }
    printf("\n"); // @@ [This prints an extra newline before the correct inorder output, violating output format]
    inorder(root);
    return 0;
}