#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int Data;
    struct node *Left, *Right;
}Node;

Node* BstInsert(int Data, Node* CurrentNode);
void InPrintBst(Node* CurrentNode, int High);

int main()
{
    Node* root = NULL;
    int n, Data;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &Data);
        root = BstInsert(Data, root);//一定要有赋值步骤
    }
    //printf("$$%d$$", root->Left->Data);
    InPrintBst(root, 1);
    return 0;
}

Node* BstInsert(int Data, Node* CurrentNode)
{
    if (CurrentNode == NULL){
        CurrentNode = (Node*)malloc(sizeof(Node));
        CurrentNode->Data = Data;CurrentNode->Left = CurrentNode->Right = NULL;
    }
    else if (Data < CurrentNode->Data){
        CurrentNode->Left = BstInsert(Data, CurrentNode->Left);
    }
    else {
        CurrentNode->Right = BstInsert(Data, CurrentNode->Right);
    }

    return CurrentNode;
}

void InPrintBst(Node* CurrentNode, int High)
{
    if (CurrentNode != NULL){
        if (CurrentNode->Left != NULL)
            InPrintBst(CurrentNode->Left, High + 1);
        if (CurrentNode->Left == NULL && CurrentNode->Right == NULL)
            printf("%d %d\n", CurrentNode->Data, High);
        if (CurrentNode->Right != NULL)
        InPrintBst(CurrentNode->Right, High + 1);
    }
}



