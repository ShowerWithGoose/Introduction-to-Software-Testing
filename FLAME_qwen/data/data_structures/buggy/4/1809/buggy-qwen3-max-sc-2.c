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
        if(t->word!="") // @@ [Comparing a char array with a string literal using != is invalid in C; this condition is always true and meaningless. Should be removed or replaced with proper check like strlen(t->word) > 0, but unnecessary since all inserted words are valid.]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]=""; // @@ [b is an array of size 1 containing only '\0', so strcpy(a,b) sets a to empty string, which is okay, but inefficient and confusing. However, the real issue is below.]
    char tmp; // @@ [tmp should be declared as int to properly handle EOF, because fgetc returns int. Using char may cause premature loop termination or infinite loop on platforms where char is unsigned.]
    BTNodeptr  root=NULL;
    FILE* fp=fopen("article.txt","r");
    int j=0;
    while((tmp=fgetc(fp))!=EOF) // @@ [fgetc returns int, but tmp is char. This can cause incorrect EOF detection, leading to missing last word or infinite loop.]
    {
        if(!((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z')))
        {
            if(a[0]!='\0')
            {
                a[j]='\0';
                root=insertBST(root,a);
                strcpy(a,b); // @@ [This sets a to empty string, but b is "", so it works, though unclear. However, after processing last word at EOF, this block may not trigger if file doesn't end with non-alpha, causing last word to be missed.]
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
        printf("%s ",root->word); // @@ [This prints extra debug output not required by problem spec, violating output format. Should be removed.]
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ [This prints extra debug output not required by problem spec, violating output format. Should be removed.]
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ [This prints extra debug output not required by problem spec, violating output format. Should be removed.]

    }
    printf("\n"); // @@ [This prints an extra newline before the correct inorder output, violating output format (extra blank line).]
    inorder(root);
    return 0;
}