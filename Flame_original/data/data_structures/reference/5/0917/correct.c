#include<stdio.h>
struct mul{
	int x;
	int z;
};
int main(){
	struct mul a[100],b[100],c[300];
	int temp,sum,p,q,n,mark=0,k=1,i=1,j=1;
	char str;
	do{
		scanf("%d%d%c",&a[i].x,&a[i].z,&str);
		i++;
	}while(str!='\n');
	do{
		scanf("%d%d%c",&b[j].x,&b[j].z,&str);
		j++;
	}while(str!='\n');
	for(p=1;p<i;++p){
		for(q=1;q<j;++q){
			c[k].x=a[p].x*b[q].x;
			c[k].z=a[p].z+b[q].z;
			k++;
		}
	}//相乘 
	for(i=1;i<=k;i++){
		for(j=i+1;j<=k;j++){
			if(c[j].z>c[i].z){
				temp=c[i].z;
				c[i].z=c[j].z;
				c[j].z=temp;
				temp=c[i].x;
				c[i].x=c[j].x;
				c[j].x=temp;
			}//将指数大的交换上去 
			else if(c[j].z==c[i].z){
				c[i].x+=c[j].x;
				c[j].x=0;
			}//将指数一样的项合并 
		}
	}
	for(i=1;i<k;i++){
		if(c[i].x!=0)
			printf("%d %d ",c[i].x,c[i].z);
	}
	return 0;
}

