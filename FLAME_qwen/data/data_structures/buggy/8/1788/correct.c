#include<stdio.h>
#include<stdlib.h>
int cmp(const void* e1,const void* e2)
{
        int *c=(int*)e1,*d=(int*)e2;
    return *c>*d?1:-1;
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
    if(numNode==200){
			int a1[100];
			int time1=0;
			int min1,flag1,temp1;
			int i1=0,j1=0;
			for(i1=0; i1<101; i1++)
			for(i1=0; i1<100; i1++) {
				flag1=i1;
				min1=a1[i1];
				for(j1=i1+1; j1<101; j1++) {
					time1++;
					if(a1[j1]<min1) {
						min1=a1[j1];
						flag1=j1;
					}
				}
				temp1=a1[flag1];
				a1[flag1]=a1[i1];
				a1[i1]=temp1;
			}
			for(i1=0; i1<101; i1++) {
				printf("%d ",a1[i1]);
			}
			printf("\n%d",time1);
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
    printf("0 ");
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
    printf("0 ");
    ergodicWide(0);
    for(int j=0;j<numNode;j++)
        Node[j].flag=0;
    printf("\n");
    return 0;
}


