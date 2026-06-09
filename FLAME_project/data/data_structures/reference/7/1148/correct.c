#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct link {
	int num;
	int xu;
	struct link *left;
	struct link *right;
}*p,*q;
int a[100005];
char s[100005];
void find(struct link *p,int cnt) {
	if(p==NULL)return ;
	if(p->left!=NULL) {
		find(p->left,cnt+1);
	} 
	if(p->left==NULL&&p->right==NULL) {
		printf("%d %d\n",p->num,cnt+1);
		return;
	}
	if(p->right!=NULL) {
		find(p->right,cnt+1);
	}
}
int main() {
	int n,m,l,i,j,k,cnt;
	struct link *first=NULL;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {//存入所有数据
		scanf("%d",&k);
		q=(struct link *)malloc(sizeof(struct link));
		q->num=k;
		q->xu=i;
		q->left=NULL;
		q->right=NULL;
		if(first==NULL)first=p=q;
		else {
			p=first;
			//printf("p:%d q:%d",p->num,q->num);
			while(1) {
				if(q->num<p->num) {
					if(p->left==NULL) {
						p->left=q;
						//printf("存进去：%d\n",q->num);
						break;
					} else if(p->left!=NULL) {
						p=p->left;
					}
				} else if(q->num>=p->num) {
					if(p->right==NULL) {
						p->right=q;
						//printf("存进去：%d\n",q->num);
						break;
					} else if(p->right!=NULL) {
						p=p->right;
					}
				}
			}
		}
	}
	//遍历并且输出
	cnt=0;
	find(first,cnt);
	return 0;
}
/*13
50 38 30 64 58 40 10 73 70 50 60 100 35*/

