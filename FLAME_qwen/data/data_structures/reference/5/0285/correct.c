// 链表存储  顺序链表即可
// 两个for循环相乘  
// 最后进行排序，以指数为关键字

#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
    long long x;
    long long pow;
}Node;

Node node1[100];
Node node2[100];
Node node3[100];


int cmp(const void* e1, const void* e2)
{
    return (*(Node*)e2).pow - (*(Node*)e1).pow;
}



int main()
{
    int i = 0;

    while(1)
    {
    scanf("%lld%lld", &node1[i].x, &node1[i].pow);

    i++;

    if(getchar() == '\n')
    {
        break;
    }
    
    
    }

    int j = 0;

    while(1)
    {
    scanf("%lld%lld", &node2[j].x, &node2[j].pow);

    j++;

    if(getchar() == '\n')
    {
        break;
    }

    
    }

    int count = 0;

    for(int m = 0; m < i; m++)
    {
        for(int n = 0; n < j; n++)
        {
            node3[count].x = node1[m].x * node2[n].x;
            node3[count++].pow = node1[m].pow + node2[n].pow;
        }
    }

    qsort(node3, count, sizeof(node3[0]), cmp);

    for(int i = 0; i < count - 1; i++)
    {
        int k = i;

        while(node3[k].pow == node3[i + 1].pow)
        {
            node3[k].x += node3[i + 1].x;
            node3[i + 1].pow = 0;
            node3[i + 1].x = 0;

            i++;
        }
    }

    for(int i = 0; i < count; i++)
    {
        if(node3[i].x != 0)
        {
        printf("%lld %lld ", node3[i].x, node3[i].pow);
        }
    }

    return 0;
}
