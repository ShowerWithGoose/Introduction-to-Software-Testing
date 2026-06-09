#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

#define max 1000

typedef struct node
{
	int data;
	int high;
	int flag;//0代表不是叶结点，1代表是叶结点 
}BTree;
BTree tree[max+10];
int deep=0; 

void createTree(int pos,int temp)
{
	deep++;
	if(tree[pos].data ==-1)//该结点为空
	{
		tree[pos].data =temp;
		tree[pos].high =deep;
	 } 
	else if(temp<tree[pos].data )//分左右
	{
		tree[pos].flag = 0;
		createTree(pos*2,temp); 
	 } 
	 else if(temp>=tree[pos].data )
	 {
	 	tree[pos].flag =0;
	 	createTree(pos*2+1,temp);
	 }
}

void LDR(int pos)
{
	if(tree[pos].data !=-1)
	{
		LDR(2*pos);
		if(tree[2*pos].data ==-1&&tree[2*pos+1].data ==-1)
		{
			printf("%d %d\n",tree[pos].data ,tree[pos].high );
		}
		LDR(2*pos+1);
	}
}



int main(int argc, const char * argv[])
{
	int i,n,temp;
	for(i=0;i<max+9;i++)
	{
		tree[i].data =-1;
		tree[i].high =0;
		tree[i].flag =1;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d", &temp);
		deep=0;
		createTree(1,temp);
	}
	LDR(1);
	return 0;
}

