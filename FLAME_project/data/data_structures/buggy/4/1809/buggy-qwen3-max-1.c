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
        if(t->word!="") // @@ [This condition is always true because t->word is a char array and comparing it with a string literal using != is invalid in C; it compares addresses, not content. This leads to unnecessary check and potential confusion, but not the main bug.]
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]=""; // @@ [b is an empty string of size 1 containing only '\0', so strcpy(a,b) sets a to empty string. However, this approach fails to reset 'a' properly when a word ends at EOF without a trailing non-alpha character.]
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
                strcpy(a,b); // @@ [This resets a to empty string, but after processing last word at EOF, this block may not execute, causing last word to be missed if file doesn't end with non-alpha. However, in this test case, the file ends with ';', so this isn't the primary issue.]
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
        printf("%s ",root->word); // @@ [This prints extra words before the correct inorder output, causing the first three words "i will you" to appear incorrectly at the top. This violates the output format which should only have lexicographical list from inorder traversal.]
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ [Same as above: these debug prints are left in the code and produce wrong initial output lines.]
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ [Same as above: these debug prints are left in the code and produce wrong initial output lines.]

    }
    printf("\n"); // @@ [This prints an extra newline after the erroneous debug output, contributing to the wrong answer format.]
    inorder(root);
    return 0;
}