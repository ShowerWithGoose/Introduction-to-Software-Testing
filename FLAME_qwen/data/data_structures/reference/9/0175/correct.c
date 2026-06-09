#include<string.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
struct add{
	int x1;
	int y1;
	int x2;
	int y2; 
}op[100],temp;
int t,a[100],b[100],num[100];
int main(){
	int n=0,i=0,j=0,k=0,cmp=1,flag,max;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&op[i].x1,&op[i].y1,&op[i].x2,&op[i].y2);
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(op[i].x1>op[j].x1){
				temp=op[j];
				op[j]=op[i];
				op[i]=temp;
			}
		}
	}
    i=0;
	for(;i<n;i++){
		for(j=i+1;j<n;j++){
			if(op[i].x2==op[j].x1&&op[i].y2==op[j].y1){
				cmp++;
				if(cmp==2){
				    t=i;
			    }
				i=j;
			}
		}
		if(cmp>=2){
		k++;
		a[k]=op[t].x1;b[k]=op[t].y1;num[k]=cmp;	i=t;
		}
		cmp=1;
	}
	if(k==1) printf("%d %d %d",num[k],a[k],b[k]);
	else{   max=num[1];j=1; 
		for(i=1;i<=k;i++){
			if(num[i]>max){
				 j=i;
				 max=num[i];
			}
		}
		printf("%d %d %d",num[j],a[j],b[j]);
	}
	return 0;
} 

