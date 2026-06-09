#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree{
    int data;
    int deep;
    struct tree *lc, *rc;
}tree, *treep;
treep p;
int hight;

treep create(int data_temp, int deep_temp)  //创建树，其中包括数据和深度 
{
    treep data = (treep)malloc(sizeof(tree));  //动态开存储空间 
    data->lc = data->rc = NULL; //让左右孩子都是空 
    data->data=data_temp;  //赋值数据 
    data->deep=deep_temp;  //赋值深度 
    return data;  //函数返回 
}

treep add(treep now, int data)  //增加数据 
{
    hight++;  //深度++ 
    if(now == NULL)  //如果现在的指针位置为空 （没有树） 
        now = create(data, hight); //在现在的指针位置创建树 
    else if(data < now->data)  //如果新数据小于目前数据 
        now->lc = add(now->lc, data);  // 加在左边 
    else if(data >= now->data) //如果新数据大于目前数据 
        now->rc = add(now->rc, data);  // 加在右边 
    return now;  //返回当前树指针 
}

void print(treep data)
{
    if(data->lc)
        print(data->lc);  //如果有左孩子，嵌套到左边 
    if(data->rc)
        print(data->rc);  //如果有右孩子，嵌套到右边 
	if(data->lc == NULL&&data->rc == NULL)  //如果是叶节点了 
        printf("%d %d\n",data->data,data->deep);  //打印 
}

int main()
{
    int n,data;
    scanf("%d", &n);  //输入一共多少数据 
    scanf("%d", &data);  //先输入第一个数据 
    p=create(data, 1);  //创建树 
    for(int i=1; i<n; i++){  
        scanf("%d",&data);  //遍历来依次输入 
		hight = 0;  
        add(p, data);  //在树中增加数据 
    }
    print(p);  //打印出来 
    return 0;
}





