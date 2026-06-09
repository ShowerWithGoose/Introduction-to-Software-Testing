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
        if(t->word!="") @@ // Error: String comparison using != compares addresses, not contents. Should use strcmp. However, this condition is always true, so it does not affect output but is semantically incorrect.
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]="";
    char tmp; @@ // Error: Declare tmp as int instead of char to correctly handle EOF and avoid potential infinite loop when char is unsigned.
    BTNodeptr  root=NULL;
    FILE* fp=fopen("article.txt","r");
    int j=0;
    while((tmp=fgetc(fp))!=EOF) @@ // Error: Because tmp is char, this loop condition may never become false (if char is unsigned), causing an infinite loop. Also, after the loop, the last word accumulated in buffer a is not inserted into the tree.
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
    fclose(fp); @@ // Error: Missing insertion of the last word (if any) that remains in buffer a after the loop ends. Should add code to insert a if not empty before closing the file.
    if(root!=NULL)
        printf("%s ",root->word); @@ // Error: This debug print outputs extra data and violates the required output format (only word and count per line from inorder).
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); @@ // Error: Same as above – extra debug output.
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); @@ // Error: Same as above – extra debug output.

    }
    printf("\n"); @@ // Error: Extra newline from debug prints, not part of required output.
    inorder(root);
    return 0;
}