#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct node
{
    int data;
    int high;
    struct node *zuo, *you;
} Shu;
Shu *diyi;

Shu *New(Shu *root, int temp, int l) //新建节点
{
	l++;
    if (root == NULL)
    {
        root = (Shu *)malloc(sizeof(Shu));
        root->data = temp;
        root->zuo = root->you = NULL;
        diyi = root;
        root->high = l;
    }
    else if (temp < root->data)
        root->zuo = New(root->zuo, temp, l);
    else if (temp >= root->data)
        root->you = New(root->you, temp, l);
    return root;

}


void print(Shu *root)
{
	if (root)
    {
        if (!(root->zuo) && !(root->you))
        {
            printf("%d %d\n", root->data, root->high);
        }
        print(root->zuo);
        print(root->you);
    }

}                //打印叶节点

int main()
{
    Shu *root = NULL;
    int n, temp,i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) //创建树
    {
        scanf("%d", &temp);

        int l = 0;
        root = New(root, temp, l);
    }
    print(root);
    return 0;
}







