#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct M {
int xi;
int zhi;	
};

int cmp(const void *a,const void *b){
	struct M *one=(struct M *)a;
	struct M *two=(struct M *)b;
	return -1*((one->zhi)-(two->zhi));//字符串返回strcmp，此时为从小到大 
}
int main(){
	struct M p1[1000],p2[1000],p3[1000],temp;
int n,m,q;int i=0,j=0,tp1,tp2,count=0,sum=0;char ch;
scanf("%d %d",&p1[0].xi,&p1[0].zhi);
	while(getchar()!='\n'){i++;
		scanf("%d %d",&p1[i].xi,&p1[i].zhi);
	}tp1=i;
	i=0;
scanf("%d %d",&p2[0].xi,&p2[0].zhi);
	while(getchar()!='\n'){i++;
		scanf("%d %d",&p2[i].xi,&p2[i].zhi);
	}tp2=i;

int max,min,k=0;
if(tp1>=tp2) {
max=tp1;	min=tp2;
}
else {
max=tp2;   min=tp1;	
}
for(i=0;i<=max;i++){
	for(j=0;j<=min;j++){
	p3[k].xi=p1[i].xi*p2[j].xi;
	p3[k].zhi=p1[i].zhi+p2[j].zhi;	
	k++;
	}
}
qsort(p3,k,sizeof(p3[0]),cmp); 

int flag=0;
for(i=0;i<k;i++){
	temp=p3[i+1];
	if(temp.zhi==p3[i].zhi){
		p3[i+1].xi+=p3[i].xi;
		flag=1;
	}
	if(flag==1){
		int t,tk=k;
		for(t=i;t<tk-1;t++){
			p3[t]=p3[t+1];
		}
		tk--;
		k=tk;i--;
	}flag=0;
}
for(i=0;i<=k;i++){
	if(p3[i].xi!=0)printf("%d %d ",p3[i].xi,p3[i].zhi);
} 

	return 0;
}




