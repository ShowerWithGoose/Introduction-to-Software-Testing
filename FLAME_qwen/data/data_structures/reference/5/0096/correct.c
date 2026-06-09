#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct daf{
	int xi;
	int zhi;
}x1[999],x2[999],x3[999];

int main(){
	int n,m,i,n1,n2,j,k;
	char ch;
	i=0;
	while(scanf("%d %d",&n,&m)!=0){
		x1[i].xi=n;
		x1[i++].zhi=m;
		ch=getchar();
		if(ch=='\n'){
			break;
		}
	}
	n1=i;
	i=0;
	while(scanf("%d %d",&n,&m)!=0){
		x2[i].xi=n;
		x2[i++].zhi=m;
		ch=getchar();
		if(ch=='\n'){
			break;
		}
	}
	n2=i;
	/*for(i=0;i<n1;i++){
		printf("%d\n",x1[i].xi);
	}
	for(i=0;i<n2;i++){
		printf("%d\n",x2[i].xi);
	}*/
	k=0;
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			x3[k].xi=x1[i].xi*x2[j].xi;
			x3[k++].zhi=x1[i].zhi+x2[j].zhi;
		}
	}
	for(i=0;i<k;i++){
		if(x3[i].xi!=0){
//			printf("%d %d ",x3[i].xi,x3[i].zhi);
		}
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(x3[i].zhi==x3[j].zhi){
				x3[i].xi+=x3[j].xi;
				x3[j].xi=0;
			}
		}
	}
	for(i=0;i<k;i++){
		for(j=i+1;j<k;j++){
			if(x3[i].zhi<x3[j].zhi){
				n=x3[i].zhi;
				x3[i].zhi=x3[j].zhi;
				x3[j].zhi=n;
				n=x3[i].xi;
				x3[i].xi=x3[j].xi;
				x3[j].xi=n;
			}
		}
	}
	for(i=0;i<k;i++){
		if(x3[i].xi!=0){
			printf("%d %d ",x3[i].xi,x3[i].zhi);
		}
	}
	
}

