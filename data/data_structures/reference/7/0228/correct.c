#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int high;//deep
    int leaf;
} Tree;
Tree tree[1010];
int deep=0;

void buildtree(int pos,int temp);
void print(int pos);

int main()
{
    for(int i=0;i<1009;i++){
        tree[i].data=-1;
        tree[i].high=0;
        tree[i].leaf=1;
    }//初始化
    int n,temp;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&temp);
        deep=0;//每次重置deep为0
        buildtree(1,temp);
    }
    print(1);
    return 0;
}

void buildtree(int a,int temp)
{
    deep++;
    if(tree[a].data==-1){//如果这个结点之前没存数据，就存在这里
        tree[a].data=temp;
        tree[a].high=deep;
    }
    else if(temp<tree[a].data){//分左右
        tree[a].leaf=0;//说明有孩子，标记一下子
        buildtree(2*a,temp);//去左边找 2*pos为pos的左孩子
    }
    else if(temp>=tree[a].data){
        tree[a].leaf=0;
        buildtree(2*a+1,temp);//去右边找 2*pos+1为pos的右孩子
    }
}

void print(int pos)
{
    if(tree[pos].data!=-1){
        print(2*pos);
        if(tree[2*pos].data==-1&&tree[2*pos+1].data==-1){
            printf("%d %d\n",tree[pos].data,tree[pos].high);
        }
        print(2*pos+1);
    }
}

