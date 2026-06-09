#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct list{
	int xishu;
	int zhishu;
}list1[20000],list2[20000],list[20000];

int main(){
	int i=0,j=0,k=0,l1,l2,l3;
	long long a,b;
	for(i=0;;i++){
		scanf("%d%d",&list1[i].xishu,&list1[i].zhishu);
		l1=i+1;
		if(getchar()=='\n')
			break;
	}
	for(i=0;;i++){
		scanf("%d%d",&list2[i].xishu,&list2[i].zhishu);
		l2=i+1;
		if(getchar()=='\n')
			break;
	}
	for(i=0,k=0;i<l1;i++){
		for(j=0;j<l2;j++,k++){
			list[k].xishu=list1[i].xishu*list2[j].xishu;
			list[k].zhishu=list1[i].zhishu+list2[j].zhishu;
		}
	}
	l3=k;
	for(i=0;i<l3;i++){
		for(j=i+1;j<l3;j++){
			if(list[i].zhishu<list[j].zhishu){
				a=list[i].xishu;
				list[i].xishu=list[j].xishu;
				list[j].xishu=a;
				
				b=list[i].zhishu;
				list[i].zhishu=list[j].zhishu;
				list[j].zhishu=b;
			}
			if(list[i].zhishu==list[j].zhishu){
				list[i].xishu=list[i].xishu+list[j].xishu;
				list[j].xishu=0;
				list[j].zhishu=0;
			}
		}
	}
	for(i=0;list[i].xishu!=0;i++){
		printf("%d %d ",list[i].xishu,list[i].zhishu);
	}
return 0;
}


