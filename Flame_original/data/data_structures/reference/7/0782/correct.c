#include <stdio.h>

#include <math.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    int data;
    int level;
    struct node *lc, *rc;
} tr;
tr *first;
void print(tr *root)
{
    if (root)
    {
        if (!(root->lc) && !(root->rc)) //保证是末端 
        {
            printf("%d %d\n", root->data, root->level);
        }
        print(root->lc);
        print(root->rc);//控制输出方向 
    }
}          



tr *New(tr *root, int temp, int len)
{
    len++;
    if (root == NULL)
    {
        root = (tr *)malloc(sizeof(tr));
        root->data = temp;
        root->lc = root->rc = NULL;
        first = root;
        root->level = len;
    }//设立初始位置 
    else if (temp < root->data)
        root->lc = New(root->lc, temp, len);
    else if (temp >= root->data)
        root->rc = New(root->rc, temp, len);//按大小左右排列 
    return root;
}
int main()
{
    tr *root = NULL;
    int n, temp;
    int p=0;
    scanf("%d", &n);
    for (; p < n; p++) //创建树
    {
        scanf("%d", &temp);

        int len = 0;
        root = New(root, temp, len);
    }
    print(root);
    return 0;
}






