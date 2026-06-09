#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
//int范围：2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}
struct infor{
	int a,n;
}mul1[107],mul2[107],ans[10007],temp;

int main(){
	int count1=0,count2=0;
	while(scanf("%d%d",&mul1[count1].a,&mul1[count1].n)!=EOF){
		count1++;
		if(getchar()=='\n') break;
	}
	while(scanf("%d%d",&mul2[count2].a,&mul2[count2].n)!=EOF){
		count2++;
		if(getchar()=='\n') break;
	}//数据的读入 不会 qwq 到网上找找怎么做
	
	/*for(;count1<5;count1++){
		scanf("%d%d",&mul1[count1].a,&mul1[count1].n);
	}
	for(;count2<4;count2++){
		scanf("%d%d",&mul2[count2].a,&mul2[count2].n);
	}*/
	int k=0;
	for(int i=0;i<count1;i++){
		for(int j=0;j<count2;j++){
		ans[k].a=mul1[i].a*mul2[j].a;
		ans[k].n=mul1[i].n+mul2[j].n;
		k++;
		}
	}//多项式乘法
	
	for(int i=0;i<k;i++){
		for(int j=0;j<k-i-1;j++){
			if(ans[j].n<ans[j+1].n){
				temp=ans[j];
				ans[j]=ans[j+1];
				ans[j+1]=temp;
			}
		}
	}//降幂排序    输入法显示江米让人有点想吃江米条了 真的 虽然我还不饿
	
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(ans[j].n<ans[i].n) break;
			else{
				ans[i].a+=ans[j].a;
				ans[j].a=-1;
			}
		}
	}//合并同类项
	
	for(int i=0;i<k;i++){
		if(ans[i].a<=0) continue;
		printf("%d %d ",ans[i].a,ans[i].n);
	}//输出
	return 0;	
}




