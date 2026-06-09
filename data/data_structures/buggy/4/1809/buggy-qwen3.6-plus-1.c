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
        if(t->word!="") // @@ C语言中不能使用!=直接比较字符串内容，该写法比较的是指针地址而非字符串值，恒为真，应改为if(t->word[0] != '\0')或直接删除
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]="";
    char tmp; // @@ fgetc返回值为int类型，使用char接收可能导致无法正确判断EOF（尤其当char为无符号时），应改为int tmp
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
    if(root!=NULL)
        printf("%s ",root->word); // @@ 多余的调试输出代码，不符合题目要求的词频统计输出格式，会导致输出错误
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ 多余的调试输出代码，不符合题目要求的词频统计输出格式
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ 多余的调试输出代码，不符合题目要求的词频统计输出格式

    }
    printf("\n"); // @@ 多余的调试输出代码，会破坏题目要求的标准输出格式
    inorder(root);
    return 0;
}