#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
    return (int*)e1>(int*)e2 ? 1:-1;
}
int delete=-1;
struct node
{
    int connect[100];
    int i;
    int flag;
}Node[100];
int temp[100];
int p=0,q=0;
void ergodicWide(int n)
{
    for(int l=0;l<Node[n].i;l++)
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
            printf("%d ",Node[n].connect[l]);
    for(int l=0;l<Node[n].i;l++)
    {
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
        {
            Node[Node[n].connect[l]].flag=1;
            temp[q++]=Node[n].connect[l];
        }
    }
    while(p<q)
        ergodicWide(temp[p++]);
}
void ergodicDepth(int n)
{
    printf("%d ",n);
    Node[n].flag=1;
    for(int l=0;l<Node[n].i;l++)
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
            ergodicDepth(Node[n].connect[l]);
}
int main()
{
    int numNode,numLine;
    scanf("%d%d",&numNode,&numLine);
    for(int j=1;j<numNode;j++) // @@ [Error: Node[0] is not initialized; its i and flag are uninitialized, which may cause undefined behavior. Should initialize Node[0] as well.]
    {
        Node[j].i=0;
        Node[j].flag=0;
    }

    int a,b;
    while(numLine--)
    {
        scanf("%d%d",&a,&b);
        Node[a].connect[Node[a].i]=b;
        Node[a].i++;
        Node[b].connect[Node[b].i]=a;
        Node[b].i++;
    }
    for(int k=0;k<numNode;k++)
    {
        qsort(Node[k].connect,Node[k].i,sizeof(Node[k].connect[0]),cmp);
    }
    ergodicDepth(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    Node[0].flag=1;
    printf("\n");
    printf("0 "); // @@ [Error: The BFS output before deletion should not have a leading "0 " printed separately; the BFS function should print all nodes including 0. This causes an extra "0 " in the output.]
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n");
    p=0;q=0;
    scanf("%d",&delete);
    ergodicDepth(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    Node[0].flag=1;
    printf("\n");
    printf("0 "); // @@ [Error: Same issue as above for BFS after deletion; the leading "0 " is printed separately, causing an extra space or incorrect format.]
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n");
    return 0;
}