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
            printf("%d ",Node[n].connect[l]); // @@ This printf always adds a space after the number, causing a trailing space at the end of the BFS output line.
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
    printf("%d ",n); // @@ This printf always adds a space after the number, causing a trailing space at the end of the DFS output line.
    Node[n].flag=1;
    for(int l=0;l<Node[n].i;l++)
        if(Node[Node[n].connect[l]].flag==0&&Node[n].connect[l]!=delete)
            ergodicDepth(Node[n].connect[l]);
}
int main()
{
    int numNode,numLine;
    scanf("%d%d",&numNode,&numLine);
    for(int j=1;j<numNode;j++) // @@ Loop should start from j=0 to also initialize Node[0].i and Node[0].flag; otherwise Node[0].flag remains uninitialized.
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
    printf("0 "); // @@ This prints a space after '0', which combined with ergodicWide's trailing spaces results in a BFS line ending with an extra space.
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
    printf("0 "); // @@ Same issue as above for the second BFS line.
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n");
    return 0;
}