#include <stdio.h>
#include <stdlib.h>
int re=0,i,j,k,i1,i2,i3=0;
struct node{
	int num;
	int index;
};
typedef struct node NODE;
NODE s1[3000]={0,0},s2[3000]={0,0},result[50000]={0,0};

void dele_same(NODE *s){
	int i,j;
	for(i=0;i<i3;i++){
		for(j=i+1;j<i3;j++){
			if(s[j].index==-1)
			  continue;
			if(s[i].index==s[j].index){
				s[i].num=s[i].num+s[j].num;
				s[j].index=-1;
				re++;
			}
		}
		
	}
	return;
}

void sort(NODE *s){
	int i,j;
	NODE cmp;
	for(i=0;i<i3;i++){
		for(j=i+1;j<i3;j++){
			if(s[i].index<s[j].index){//降序
				cmp=s[i];
				s[i]=s[j];
				s[j]=cmp;
			}
		}
	}
	return;
}

int main(){
	char ch;
	for(i1=0;;i1++){
		scanf("%d%d%c",&s1[i1].num,&s1[i1].index,&ch);
		if(ch=='\n')
		  break;
	}
	for(i2=0;;i2++){
		scanf("%d%d%c",&s2[i2].num,&s2[i2].index,&ch);
				if(ch=='\n')
				  break;	
	}
	for(j=0;j<=i1;j++){//计算结果数组
		for(k=0;k<=i2;k++){
			result[i3].num=s1[j].num*s2[k].num;
			result[i3].index=s1[j].index+s2[k].index;
			i3++;
		}
	}
	dele_same(result);//去重，重复项指数记为-1
	sort(result);//降序排序
	for(i=0;i<i3-re;i++){
		printf("%d %d ",result[i].num,result[i].index);
	}
	
	return 0;
}
//

