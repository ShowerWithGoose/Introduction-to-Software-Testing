//1.链表结构体存储左右节点
//2.输入扫描，如果左节点等于前面某一条线段的右节点，进行连接，并且，头结点的count++;
//3.如果右节点等于左节点，就更换头节点，并且转移count++并进行转移
//4所以开始应该有一个结构体数组，先组建节点，然后遍历O(n^2)
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int left_x;
	int left_y;
	int right_x;
	int right_y;
	int count;
	struct node* front;
	struct node* next;
} Link;
Link *para[10005];
int main() {
	int n,max=0,res_x=0,res_y=0,flag=0;
	Link *p;
	scanf("%d",&n);//all number
	for(int i=0; i<n; i++) {
		para[i]=(Link *)malloc(sizeof(Link));
		scanf("%d%d%d%d",&para[i]->left_x,&para[i]->left_y,&para[i]->right_x,&para[i]->right_y);
		para[i]->count=1;
		para[i]->front=para[i]->next=NULL;//initial
	} //create node
	int i,j;
	for( i=0; i<n; i++) { //scan all front(n-1) element,
		for( j=0; j<n; j++ ) { //search from its behind
			flag=0;
			if(i==j)
			continue;
			if(para[i]->left_x==para[j]->right_x&&para[i]->left_y==para[j]->right_y&&para[j]->next==NULL) { //compensate it int the front
				para[j]->next=para[i];//j becomes first
				para[i]->front=para[j];
				int temp;
				temp=para[i]->count;//reserve length of i 
				p=para[j];
				while(p->front!=NULL) {
					p=p->front;
				}
				p->count+=temp;//将长度相加 
				flag=1;
			}//front number
			else if(para[j]->left_x==para[i]->right_x&&para[j]->left_y==para[i]->right_y&&para[i]->next==NULL) {
				para[i]->next=para[j];
				para[j]->front=para[i];
				int temp;
				temp=para[j]->count;
				p=para[i];
				while(p->front!=NULL) {
					p=p->front;
				}
				p->count+=temp;
				flag=1;
			}
			if(flag==1&&p->count>max) {
				max=p->count;
				res_x=p->left_x;
				res_y=p->left_y;
			}
		}
	}
	printf("%d %d %d",max,res_x,res_y);
	for(int i=0; i<n; i++) {
		free(para[i]);
	}
	return 0;
}


