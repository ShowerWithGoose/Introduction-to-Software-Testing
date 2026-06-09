#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    char *left;
    char *right;
    int data;
    int high;
} Tree;
int deep = 0;
Tree tree[1000];
void set(int p, int temp);
void put(int p);
int main()
{
    int n;
    int temp;
    for (int m = 0; m < 1000; m++)
    {
        tree[m].data = -1;
        tree[m].high = 0;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        deep = 0;
        scanf("%d", &temp);
        set(1, temp);
    }
    put(1);
    return 0;
}
void set(int p, int temp)
{
    deep++;
    if (tree[p].data == -1)
    {
        tree[p].data = temp;
        tree[p].high = deep;
    }
    else if (temp < tree[p].data)
    {
        set(2 * p, temp);
    }
    else if (temp >= tree[p].data)
    {
        set(2 * p + 1, temp);
    }
}
void put(int p)
{
    if (tree[p].data != -1)
    {
        put(2 * p);
        if (tree[2 * p].data == -1 && tree[2 * p + 1].data == -1)
        {
            printf("%d %d\n", tree[p].data, tree[p].high);
        }
        put(2 * p + 1);
    }
}
