#include <stdio.h>
#include <stdlib.h>


typedef struct _Elem
{
    int coe;
    int pow;
}Elem;

typedef struct _Node
{
    Elem data;
    struct _Node *link;
}Node, *NodePtr;

NodePtr CreateNode(Elem item){
    NodePtr p;
    p = (NodePtr)malloc(sizeof(Node));
    p->data = item;
    p->link = NULL;
    return p;
}

NodePtr InsertNode(NodePtr list, NodePtr q, Elem item){
    NodePtr r;
    r = CreateNode(item);
    r->link = q->link;
    q->link = r;

    return list;
}

void getSequenceList(NodePtr list){
    char c;
    Elem item;
    NodePtr r = list;//临时
    do
    {
        scanf("%d%d%c",&item.coe, &item.pow, &c);
        list = InsertNode(list, r, item);
        r = r->link;
    } while (c != '\n');
}

NodePtr createHead(NodePtr list){
    Elem item;
    item.coe = 0;
    item.pow = 0;

    list = CreateNode(item); // @@ [Function createHead is supposed to return a new head node, but it does not return anything, leading to undefined behavior. Missing 'return list;']
}

void InsertSortList(NodePtr list, Elem item){
    NodePtr q, p;
    q = list;
    p = list->link;
    for ( ;p!=NULL && p->data.pow > item.pow
          ;q=q->link,p=p->link)
    ;
    if (p == NULL)
    {
        list = InsertNode(list, q, item);
    }
    else if (p->data.pow == item.pow)
    {
        p->data.coe += item.coe;
    }
    else
    {
        list = InsertNode(list, q, item);
    }
}

NodePtr multiList(NodePtr list1, NodePtr q, NodePtr list2, NodePtr list_res){
    NodePtr res = list_res->link;
    Elem item;
    for (NodePtr r = list2->link; r != NULL; r = r->link)
    {
        item.coe = q->data.coe * r->data.coe;
        item.pow = q->data.pow + r->data.pow;
        InsertSortList(list_res, item);
    }
    return list_res;
}

int main()
{
    NodePtr lists[5];//0和1表示输入
    //2表示每次乘出来的临时结果
    //3表示最终结果
    for (int i = 0; i < 3; i++)
    {
        lists[i] = createHead(lists[i]); // @@ [createHead does not return a value, so lists[i] is assigned an undefined value, causing potential crashes or incorrect behavior]
    }
    
    getSequenceList(lists[0]);
    getSequenceList(lists[1]);

    for (NodePtr r = lists[0]->link; r != NULL; r = r->link)
    {    
        lists[2] = multiList(lists[0], r, lists[1], lists[2]);
    }
    
    for (NodePtr r = lists[2]->link; r != NULL; r = r->link)
    {
        if (r->data.coe != 0)
        {
            printf("%d %d ",r->data.coe,r->data.pow);
        }
    }
    
    return 0;
}