#include<stdio.h>
#include<string.h> 
#include <stdlib.h>
struct xiang{
	long long xishu;
	long long zhishu;
};
struct xiang a[1000],b[1000],ans[10000];
int cmp(const void*a,const void*b){
	struct xiang*a1=(struct xiang*)a;
	struct xiang*b1=(struct xiang*)b;
	if(a1->zhishu<b1->zhishu){
		return 1;
	}
	else{
		return -1;
	}
}
char ch;
int main(){ 
   int i,ia,ib,j,k=0;
   i=0;
   do{
   	scanf("%lld %lld",&a[i].xishu,&a[i].zhishu);
   	i++;
   	ch=getchar();
   }while(ch!='\n');
   ia=i;
   i=0;
   do{
   	scanf("%lld %lld",&b[i].xishu,&b[i].zhishu);
   	i++;
   	ch=getchar();
   }while(ch!='\n');
   ib=i;
   for(i=0;i<=ia-1;i++){
   	for(j=0;j<=ib-1;j++){
   		ans[k].xishu=a[i].xishu*b[j].xishu;
   		ans[k].zhishu=a[i].zhishu+b[j].zhishu;
   		k++;
	   }
   }
   qsort(ans,k,sizeof(ans[0]),cmp);
   for(i=0;i<=k-1;i++){
   	j=1;
   	while(ans[i].zhishu==ans[i+j].zhishu&&i+j<=9999){
   		ans[i].xishu+=ans[i+j].xishu;
   		ans[i+j].xishu=0;
   		j++;
	   }
   }
   for(i=0;i<=k-1;i++){
   	if(ans[i].xishu!=0){
   		printf("%lld %lld ",ans[i].xishu,ans[i].zhishu);
	   }
   }
} 


