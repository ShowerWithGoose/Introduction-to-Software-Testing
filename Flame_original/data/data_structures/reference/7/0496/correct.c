#include <stdio.h>
struct tree
{
    int data;
    int high;
    int lt;
}tree[1000];
int deep=0;

void build(int pos,int temp);
void LDR(int pos);

int main()
{
    for(int i=0;i<1000;i++){
        tree[i].data=-1;
        tree[i].high=0;
        tree[i].lt=1;
    }
    int n,temp;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&temp);
        deep=0;
        build(1,temp);
    }
    LDR(1);
    return 0;
}

void build(int pos,int temp)
{
    deep++;
    if(tree[pos].data==-1){
        tree[pos].data=temp;
        tree[pos].high=deep;
    }
    else if(temp<tree[pos].data){
        tree[pos].lt=0;
        build(2*pos,temp);
    }
    else if(temp>=tree[pos].data){
        tree[pos].lt=0;
        build(2*pos+1,temp);
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

