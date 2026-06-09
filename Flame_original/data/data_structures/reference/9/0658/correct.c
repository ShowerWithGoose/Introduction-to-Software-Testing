#include<stdio.h>
#include<malloc.h> 
#include<stdlib.h>
typedef struct Array{//THe position of every line
	int x1;int y1;int x2;int y2;
}array;

typedef struct LLN{
	struct Array pos;
	struct LLN *pNext;
}linklist;

void Createlist(linklist *Headnode,int Array[][4],int datanum){
	Headnode->pNext=(linklist *)malloc(sizeof(linklist));
	linklist *Currentnode=(linklist *)Headnode->pNext;
	for(int i=0;i<datanum;i++){
		Currentnode->pos.x1=Array[i][0];
		Currentnode->pos.y1=Array[i][1];
		Currentnode->pos.x2=Array[i][2];
		Currentnode->pos.y2=Array[i][3];
		if(i<datanum-1){
			Currentnode->pNext=(linklist *)malloc(sizeof(linklist));
			Currentnode=Currentnode->pNext; 
		}
	}
	Currentnode->pNext=NULL;
}

//int GetListLength(linklist *HeadNode){//此处HeadNode指向头结点。
//int ListLength=0;
//linklist *CurrentNode=HeadNode->pNext;
//while(CurrentNode!=NULL){
//ListLength++;
//CurrentNode=CurrentNode->pNext;
//}
//return ListLength;
//}

int compare(const void *p1,const void *p2){
	return (((int *)p1)[0]-((int *)p2)[0]);
}
int main(){
	linklist *Headnode=(linklist *)malloc(sizeof(linklist));
	Headnode->pos.x1=0;Headnode->pos.y1=0;
	Headnode->pos.x2=0;Headnode->pos.y2=0;
	Headnode->pNext=NULL;
	int n;
	scanf("%d",&n);
	int array[n+1][4];
	for(int i=0;i<n;i++){
		for(int j=0;j<=3;j++) scanf("%d",&array[i][j]);
	}
	qsort(array,n,sizeof(array[0]),compare);
	Createlist(Headnode,array,n);
//	printf("%d",GetListLength(Headnode));
	int prex1=-1,prex2=-1,prey1=-1,prey2=-1;
	linklist *startnode=Headnode->pNext;
	int count=1,maxnum=0,maxx1,maxy1;
	while(startnode!=NULL){
		linklist *currentnode;
		currentnode=startnode;
		prex1=currentnode->pos.x1;prey1=currentnode->pos.y1;
		prex2=currentnode->pos.x2;prey2=currentnode->pos.y2;
		while(currentnode!=NULL){
			if(currentnode->pos.x1==prex2&&currentnode->pos.y1==prey2) 
			{
				count++;
				prex1=currentnode->pos.x1;prey1=currentnode->pos.y1;
				prex2=currentnode->pos.x2;prey2=currentnode->pos.y2;
			}
			currentnode=currentnode->pNext;
		}
		if(count>=maxnum){
			maxnum=count;maxx1=startnode->pos.x1;maxy1=startnode->pos.y1;
		}
		count=1;
		startnode=startnode->pNext;
	}
	printf("%d %d %d",maxnum,maxx1,maxy1);
}

