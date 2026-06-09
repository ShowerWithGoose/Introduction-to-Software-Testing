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
        if(t->word!="") // @@ [This comparison is invalid in C; comparing string literals with != does not compare content. It should be removed or replaced with proper logic. Also, the condition is unnecessary since empty words shouldn't be inserted.]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]=""; // @@ [b is an array of size 1 containing only '\0', so strcpy(a,b) sets a to empty string, but this is error-prone and unnecessary. Better to use a[0]='\0'.]
    char tmp;
    BTNodeptr  root=NULL;
    FILE* fp=fopen("article.txt","r"); // @@ [No check if file opened successfully; if "article.txt" doesn't exist, fp is NULL and fgetc causes undefined behavior.]
    int j=0;
    while((tmp=fgetc(fp))!=EOF) // @@ [tmp should be declared as int, not char, because EOF is outside the range of char. This can cause infinite loops or missed EOF on some systems.]
    {
        if(!((tmp>='a'&&tmp<='z')||(tmp>='A'&&tmp<='Z')))
        {
            if(a[0]!='\0')
            {
                a[j]='\0';
                root=insertBST(root,a);
                strcpy(a,b); // @@ [Using strcpy with b[1]=""; is fragile. Better: a[0] = '\0';]
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
        printf("%s ",root->word); // @@ [This prints extra output not in expected format; problem requires only inorder traversal output.]
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ [Same as above: extra debug-like output violates output format specification.]
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ [Same as above: extra output not allowed.]

    }
    printf("\n"); // @@ [This prints an extra newline before the correct inorder output, violating output format.]
    inorder(root);
    return 0;
}