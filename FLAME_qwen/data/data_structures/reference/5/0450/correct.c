#include<stdio.h>
#include<stdlib.h>

struct node{
	int coe;
	int pow;
};
typedef struct node Node;
Node t1[1000],t2[1000],ans[2000];
int cmp(const void*p1, const void*p2){
	Node *a=(Node*)p1, *b=(Node*)p2;
	return b->pow - a->pow ;
}

int main()
{
	char ch;
	int i,j,k=0,cnt1,cnt2;
	//第一个多项式
	i=0; 
	do{
		scanf("%d%d%c",&t1[i].coe,&t1[i].pow ,&ch);	
		i++;
	}while(ch!='\n');
	cnt1=i;
	//第二个多项式
	i=0; 
	do{
		scanf("%d%d%c",&t2[i].coe,&t2[i].pow ,&ch);
		i++;	
	}while(ch!='\n');
	cnt2=i;
	//相乘
	for(i=0;i<cnt1;i++){
		for(j=0;j<cnt2;j++){
			ans[k].coe = t1[i].coe * t2[j].coe ;
			ans[k++].pow = t1[i].pow + t2[j].pow ;
		}
	}
	//按幂次降序 
	qsort(ans,k,sizeof(Node),cmp); 
	//去重
	for(i=0;i<k;i++){
		if(ans[i].pow == ans[i+1].pow &&ans[i].pow !=0){
			ans[i+1].coe += ans[i].coe ;
			ans[i].coe =0;
		}
	}
	for(i=0;i<k;i++){
		if(ans[i].coe != 0)
			printf("%d %d ",ans[i].coe,ans[i].pow);
	} 
	
	return 0;
}

