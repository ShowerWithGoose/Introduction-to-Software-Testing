#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    int deep;
    struct tree *lc, *rc;
}tree, *treep;
treep root;
int depth;

treep create(int data_temp, int deep_temp)  //创建树，其中包括数据和深度 
{
    treep temp = (treep)malloc(sizeof(tree));  //动态开存储空间 
    temp->lc = temp->rc = NULL; //让左右孩子都是空 
    temp->data=data_temp;  //赋值数据 
    temp->deep=deep_temp;  //赋值深度 
    return temp;  //函数返回 
}

treep add(treep now, int temp)  //增加数据 
{
    depth++;  //深度++ 
    if(now == NULL)  //如果现在的指针位置为空 （没有树） 
        now = create(temp, depth); //在现在的指针位置创建树 
    else if(temp < now->data)  //如果新数据小于目前数据 
        now->lc = add(now->lc, temp);  // 加在左边 
    else if(temp >= now->data) //如果新数据大于目前数据 
        now->rc = add(now->rc, temp);  // 加在右边 
    return now;  //返回当前树指针 
}

void print(treep temp)
{
    if(temp->lc)
        print(temp->lc);  //如果有左孩子，嵌套到左边 
    if(temp->rc)
        print(temp->rc);  //如果有右孩子，嵌套到右边 
	if(temp->lc == NULL&&temp->rc == NULL)  //如果是叶节点了 
        printf("%d %d\n",temp->data,temp->deep);  //打印 
}

int main()
{
    int n,temp;
    scanf("%d", &n);  //输入一共多少数据 
    scanf("%d", &temp);  //先输入第一个数据 
    root=create(temp, 1);  //创建树 
    for(int i=1; i<n; i++){  
        scanf("%d",&temp);  //遍历来依次输入 
		depth = 0;  
        add(root, temp);  //在树中增加数据 
    }
    print(root);  //打印出来 
    return 0;
}





