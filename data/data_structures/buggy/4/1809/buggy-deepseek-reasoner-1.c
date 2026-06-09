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
        if(t->word!="") // @@ 错误：不能直接用!=比较C字符串，应使用strcmp(t->word,"")!=0
            printf("%s %d\n",t->word,t->num);       /* 访问T指结点  */
        inorder(t->right);
    }
}

int main()
{
    char a[50]="";
    char b[1]="";
    char tmp; // @@ 错误：fgetc()返回int，应声明为int tmp，否则无法正确检测EOF
    BTNodeptr  root=NULL;
    FILE* fp=fopen("article.txt","r");
    int j=0;
    while((tmp=fgetc(fp))!=EOF) // @@ 错误：tmp为char导致EOF比较可能失败，应使用int类型
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
    fclose(fp); // @@ 错误：缺少对文件末尾可能存在的最后一个单词的处理（应在关闭文件前检查并插入）
    if(root!=NULL)
        printf("%s ",root->word); // @@ 错误：多余输出，不符合输出格式要求
    if(root->right!=NULL)
    {
        printf("%s ",root->right->word); // @@ 错误：多余输出，不符合输出格式要求
        if(root->right->right!=NULL)
            printf("%s ",root->right->right->word); // @@ 错误：多余输出，且可能访问空指针

    }
    printf("\n"); // @@ 错误：多余输出，不符合输出格式要求
    inorder(root);
    return 0;
}