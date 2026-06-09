#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct line{
	int left[2];
	int right[2];
	struct line *link;
};
int main()
{
	int n,i,j,flag=-1,k=0,find_max=-1;
	int num[105]={0},maxnum;//num[0]记录着第零个链表的结点数，maxnum记录着符合连接条件并含有最多结点数的链表数 
	struct line *first[105]={NULL};//由每一串链表的首指针构成的指针数组 
	struct line *p[105]={NULL};//指向对应首指针指向的链表的最后一个节点 
	struct line *q;
	
	for(j=0;j<105;j++)
		p[j]=first[j];
	//将所有的p[j]都赋值给first[j] 
	
	scanf("%d\n",&n);
	
	for(int i=0;i<n;i++){
		q=(struct line*)malloc(sizeof(struct line));
		q->link=NULL;
		scanf("%d %d %d %d",&q->left[0],&q->left[1],&q->right[0],&q->right[1]);
		flag=-1;
		maxnum=-1;
		for(j=0;j<105;j++){  //只要p[j]不是NULL说明该链表存在链结点并且此时p[j]所指为该链表的最后一个链结点。
			if(p[j]==NULL)
				continue;
			if(p[j]->right[0]==q->left[0] && p[j]->right[1]==q->left[1]){//对比最后一个结点所代表的线段的右端点坐标与新的线段的左端点坐标是否一样，若一样，则满足连接条件
				if(maxnum==-1)
					maxnum=j;//将该链表的值赋给maxnum
				else if(num[j]>num[maxnum])//如果maxnum已经有值，则对比maxnum链表的节点数与新符合条件的链表的结点数。如果新的链表的节点数更多，则将新的链表数赋值给maxnum 
					maxnum=j;
				} 
			}
		if(maxnum==-1){
			for(j=0;first[j]!=NULL;j++);
			first[j]=q;
			p[j]=q;
			flag=j;
		}
		else{
			p[maxnum]->link=q;
			p[maxnum]=q;
			flag=maxnum;
		}
		
		maxnum=-1;
		for(j=0;j<105;j++){  //只要p[j]不是NULL说明该链表存在链结点并且此时p[j]所指为该链表的最后一个链结点。
			if(first[j]==NULL)
				continue;
			else if(first[j]->left[0]==q->right[0] && first[j]->left[1]==q->right[1]){//对比最后一个结点所代表的线段的右端点坐标与新的线段的左端点坐标是否一样，若一样，则满足连接条件
				if(maxnum==-1)
					maxnum=j;//将该链表的值赋给maxnum
				else if(num[j]>num[maxnum])//如果maxnum已经有值，则对比maxnum链表的节点数与新符合条件的链表的结点数。如果新的链表的节点数更多，则将新的链表数赋值给maxnum 
					maxnum=j;
				} 
			}
		if(maxnum!=-1){
			if(flag!=-1){
				q->link=first[maxnum];
				for(p[flag]=first[maxnum];p[flag]->link!=NULL;p[flag]=p[flag]->link);
				first[maxnum]=NULL;
			}
			else{
				q->link=first[maxnum];
				first[maxnum]=q;
			}
		}
	}
	maxnum=-1;
	for(i=0;i<=104;i++){
		k=0;
		if(first[i]==NULL)
			continue;
		else{
			for(q=first[i];q!=NULL;q=q->link)
				k++;
			if(maxnum==-1){
				find_max=k;
				maxnum=i;
			}
			else{
				if(find_max<k){
					find_max=k;
					maxnum=i;
				}
			}	
		}
	}  
	printf("%d %d %d",find_max,first[maxnum]->left[0],first[maxnum]->left[1]);
	
	for(j=0;j<105;j++){
		if(first[j]==NULL)
			continue;
		for(q=first[j];q!=NULL;q=first[j]){
			first[j]=q->link;
			free(q);
		}
	}	
		
	return 0;
}


