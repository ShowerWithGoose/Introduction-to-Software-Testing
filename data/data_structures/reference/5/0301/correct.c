#include<stdio.h>
#include<stdlib.h>
struct link{
	int mult;
	int squ;
}; 
int cmp(const void *a,const void *b){
	struct link *aa=(struct link*)a;
	struct link *bb=(struct link*)b;
	if(aa->squ>bb->squ)
	return -1;
	return 1;
}
struct link sum[10000];
int main(){
	int x1[100],y1[100],x2[100],y2[100],i=0,j=0;
	char s;
	for(i=0;i<100&&s!='\n';i++){
		scanf("%d",&x1[i]);
		scanf("%d",&y1[i]);
		s=getchar();
	}
	int sum1=i;
	s='0';
	for(j=0;j<100&&s!='\n';j++){
		scanf("%d",&x2[j]);
		scanf("%d",&y2[j]);
		s=getchar();
	}
	int sum2=j;
	int flag=0;
	for(i=0;i<sum1;i++){
		for(j=0;j<sum2;j++){
			sum[flag].mult=x1[i]*x2[j];
			sum[flag].squ=y1[i]+y2[j];
			flag++;
		}
	}
	qsort(sum,flag,sizeof(sum[0]),cmp);
	struct link res[10000];
	int flag1=0;
	res[0].mult=sum[0].mult;
	res[0].squ=sum[0].squ;
	for(i=1;i<flag;i++){
		if(res[flag1].squ==sum[i].squ){
			res[flag1].mult+=sum[i].mult;
		}
		else{
			flag1++;
			res[flag1].mult=sum[i].mult;
			res[flag1].squ=sum[i].squ;
		}
	}
	for(i=0;i<=flag1;i++){
		printf("%d %d ",res[i].mult,res[i].squ);
	}
	return 0;
}

