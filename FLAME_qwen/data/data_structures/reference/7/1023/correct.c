// 1. 树叶节点遍历（树-基础题）
// 【问题描述】

// 从标准输入中输入一组整数，在输入过程中按照左子结点值小于根结点值、右子结点值大于等于根结点值的方式构造一棵二叉查找树，
//然后从左至右输出所有树中叶结点的值及高度（根结点的高度为1）。例如，若按照以下顺序输入一组整数：50、38、30、64、58、40、10、73、70、50、60、100、35，
//则生成下面的二叉查找树：

// image.png

// 从左到右的叶子结点包括：10、35、40、50、60、70、100，叶结点40的高度为3，其它叶结点的高度都为4。

// 【输入形式】

// 先从标准输入读取整数的个数，然后从下一行开始输入各个整数，整数之间以一个空格分隔。
// 【输出形式】

// 按照从左到右的顺序分行输出叶结点的值及高度，值和高度之间以一个空格分隔。
// 【样例输入】

// 13
// 50 38 30 64 58 40 10 73 70 50 60 100 35
// 【样例输出】

// 10 4

// 35 4

// 40 3

// 50 4

// 60 4

// 70 4

// 100 4
// 【样例说明】

// 按照从左到右的顺序输出叶结点（即没有子树的结点）的值和高度，每行输出一个。
// 【评分标准】

// 该题要求输出所有叶结点的值和高度，提交程序名为：bst.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree tree;
struct tree{
    int Num;
    tree *Left,*Right;
}*Root;
tree *Append_Tree(int Input_Num);
void Out_Tree(tree *p,int Depth);
void Dele_Tree(tree *p);
int main(){
    int Input_Sum,Input_Num;
    int i=-1;
    scanf(" %d",&Input_Sum);
    while(++i<Input_Sum){
        scanf(" %d",&Input_Num);
        Root=Append_Tree(Input_Num);
    }
    Out_Tree(Root,1);
    Dele_Tree(Root);
    return 0;
}
tree *Append_Tree(int Input_Num){
    tree *pr,*p;
    pr=(tree*)malloc(sizeof(tree));
    memset(pr,0x00,sizeof(tree));
    pr->Num=Input_Num;
    if(Root==NULL){
        Root=pr;
        return Root;
    }
    p=Root;
    while(p->Left!=NULL||p->Right!=NULL){
        if(pr->Num>=p->Num){
            if(p->Right!=NULL)p=p->Right;
            else if(p->Right==NULL)break;
        }
        else if (pr->Num<p->Num){
            if(p->Left!=NULL)p=p->Left;
            else if(p->Left==NULL)break;
        }
    }
    if(pr->Num>=p->Num)p->Right=pr;
    else if(pr->Num<p->Num)p->Left=pr;
    return Root;
}
void Out_Tree(tree *p,int Depth){
    if(p->Left==NULL&&p->Right==NULL){
        printf("%d %d\n",p->Num,Depth);
        return;
    }
    if(p->Left!=NULL)Out_Tree(p->Left,Depth+1);
    if(p->Right!=NULL)Out_Tree(p->Right,Depth+1);
    return;
}
void Dele_Tree(tree *p){
    if(p->Left==NULL&p->Right==NULL){
        free(p);
        return;
    }
    if(p->Left!=NULL)Dele_Tree(p->Left);
    else if(p->Right!=NULL)Dele_Tree(p->Right);
    free(p);
    return;
}

