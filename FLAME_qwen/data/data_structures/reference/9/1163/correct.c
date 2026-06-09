#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define node struct Node
#define nodeptr struct Node*
#define length 114

struct Node
{
    int x1;
    int y1;
    int x2;
    int y2;
    struct Node *next;
}lines[length];

// void Insert(nodeptr, nodeptr);
// nodeptr new();
int read(nodeptr);
int isMatching(nodeptr,nodeptr);
void output(int,int);
int main()
{
    int max = -1,count = 1,ans = 0,n = 0;
    nodeptr ptr = lines;

    #ifdef ACU
    freopen("in.txt","r",stdin);
    #endif
    scanf("%d",&n);
    for (size_t i = 0; i < n; i++)
    {
        read(lines + i);
    }


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (isMatching(lines+i,lines+j))
            {
                (lines+i)->next = lines+j;
            }
        }
    }
    

    for (size_t i = 0; i < n; i++)
    {
        while (ptr->next != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        if (count>max)
        {
            max = count;
            ans = i;
        }
        count = 1,ptr = lines+i+1;
    }
    

    output(ans,max);
    return 0;
}


// nodeptr new()
// {
//     return (nodeptr)malloc(sizeof(node));
// }

int read(nodeptr ptr)
{
    return scanf("%d%d%d%d",&(ptr->x1),&(ptr->y1),&(ptr->x2),&(ptr->y2));
}

int isMatching(nodeptr ptr1,nodeptr ptr2)
{
    if (
        ptr1->x2 == ptr2->x1 &&
        ptr1->y2 == ptr2->y1
        )
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

void output(int ans,int max)
{
    printf("%d %d %d",max, lines[ans].x1,lines[ans].y1);
}
