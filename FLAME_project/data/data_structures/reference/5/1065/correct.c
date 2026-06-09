#include<stdio.h>
struct formula{
	int xi;
	int zhi;
	int flag;
};
void sort(struct formula x[],int n);
	
int main(){
	struct formula a[30],b[30];
	struct formula c[30];	
	int i,j,k;
	char sign;
	int sum_1=0,sum_2=0,sum_3=0;
	
	i=0;
	while(scanf("%d%d%c",&a[i].xi,&a[i].zhi,&sign)!=EOF){
		a[i].flag=1;
		i++;
		sum_1++;
		if(sign=='\n')
			break;
	}
	
	i=0;
	while(scanf("%d%d%c",&b[i].xi,&b[i].zhi,&sign)!=EOF){
		b[i].flag=1;
		i++;
		sum_2++;
		if(sign=='\n')
			break;
	}
	
	k=0;
	for(i=0;i<sum_1;i++){
		for(j=0;j<sum_2;j++){
			c[k].xi=a[i].xi*b[j].xi;
			c[k].zhi=a[i].zhi+b[j].zhi;
			c[k].flag=1;
			k++;
			sum_3++;
		}
	}
	
	sort(c,sum_3);
	for(i=0;i<sum_3;i++){
		for(j=i+1;j<sum_3;j++){
			if(c[i].zhi==c[j].zhi){
				c[j].xi+=c[i].xi;
				c[i].xi=0;
				c[i].flag=0;
			}
		}
	}
	
	sort(c,sum_3);
	
	for(i=0;i<sum_3;i++){
		if(c[i].flag!=0)
			printf("%d %d ",c[i].xi,c[i].zhi);
	}
	return 0;
}
void sort(struct formula x[],int n){
	int i,j;
	struct formula y;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(x[j].zhi<x[j+1].zhi){
				y=x[j];
				x[j]=x[j+1];
				x[j+1]=y;
			}
		}
	}
}

