#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 1000
typedef struct node
{
    int data;
    int high;//deep
    int leaf_or_not;
} Tree;
Tree tree[maxn+10];
int deep=0;

void build(int pos,int temp);
void LDR(int pos);

int main()
{
    for(int i=0;i<maxn+9;i++){
        tree[i].data=-1;
        tree[i].high=0;
        tree[i].leaf_or_not=1;
    }//初始化
    int n,temp;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&temp);
        deep=0;//每次重置deep为0
        build(1,temp);
    }
    LDR(1);
    return 0;
}

void build(int pos,int temp)
{
    deep++;
    if(tree[pos].data==-1){//如果这个结点之前没存数据，就存在这里
        tree[pos].data=temp;
        tree[pos].high=deep;
    }
    else if(temp<tree[pos].data){//分左右
        tree[pos].leaf_or_not=0;//说明有孩子，标记一下子
        build(2*pos,temp);//去左边找 2*pos为pos的左孩子
    }
    else if(temp>=tree[pos].data){
        tree[pos].leaf_or_not=0;
        build(2*pos+1,temp);//去右边找 2*pos+1为pos的右孩子
    }
}

void LDR(int pos)
{
    if(tree[pos].data!=-1){
        LDR(2*pos);
        if(tree[2*pos].data==-1&&tree[2*pos+1].data==-1){
            printf("%d %d\n",tree[pos].data,tree[pos].high);
        }
        LDR(2*pos+1);
    }
}

