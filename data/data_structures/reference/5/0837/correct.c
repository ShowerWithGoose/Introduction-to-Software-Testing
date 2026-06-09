#include<stdio.h>
#include<stdlib.h>
typedef struct node_{
	int a;
	int dex;
	int mark;
}NODE;
NODE node1[1000],node2[1000],node3[1000];
int mark1=1,mark2,mark3=0;;
int cmp(void const *a,void const *b)
{
	NODE *c=(NODE *)a;
    NODE *d=(NODE *)b;
	if(c->dex>d->dex) return 1;
	else return -1;
}
int main()
{
	char tran[100000],ch;
    scanf("%d%d%c",&node1[mark1].a,&node1[mark1].dex,&ch);
	while(ch==' ')
	{
		mark1++;
		scanf("%d%d%c",&node1[mark1].a,&node1[mark1].dex,&ch);
	}
/*	for(int i=mark1;i>=1;i--)
		{
			printf("%d %d ",node1[i].a,node1[i].dex);
		}
		printf("\n");*/
	mark2=1;
	scanf("%d%d%c",&node2[mark2].a,&node2[mark2].dex,&ch);
	while(ch==' ')
	{
		mark2++;
		scanf("%d%d%c",&node2[mark2].a,&node2[mark2].dex,&ch);
	}
	for(int i=1;i<=mark1;i++)
	for(int j=1;j<=mark2;j++)
	{	
		node3[mark3].a=node1[i].a*node2[j].a;
		node3[mark3].dex=node1[i].dex+node2[j].dex;
		node3[mark3].mark=0;
		mark3++;
	}
	qsort(node3,mark3,sizeof(node3[1]),cmp);
		for(int i=0;i<mark3;i++)
		{
			if(node3[i].dex==node3[i+1].dex)
			{
				int de=1;
				int s=i;
				while(node3[s].dex==node3[s+1].dex)
				{
					node3[i].a+=node3[s+1].a;
					node3[s+1].mark=1;
	                s++;
				}	
			  i=s;
			}	
		}
		
	for(int i=mark3-1;i>=0;i--)
	{
		if(node3[i].mark==0)
		printf("%d %d ",node3[i].a,node3[i].dex);
	}
}

