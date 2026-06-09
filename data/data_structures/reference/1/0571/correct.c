#include<stdio.h>
int pow(int,int);
int main(){
	int n,m=1,a=0,b=0,i,j,t[11],k,flag=0,p,q,point=0,fin;
	scanf("%d",&n);
	for(i=n;i>=1;i--){
		a+=pow(10,n-i)*i;
	}
	m=1;
	for(i=1;i<=n;i++){
		b+=i*pow(10,i-1);
	}
	for(j=a;j<=b;j++){
		flag=0;
		point=0;
		for(k=1;k<=n;k++){
			t[k]=(j/pow(10,k-1))%10;
		}
		for(k=1;k<=n;k++){
			if(t[k]==0)flag=1;
		}
		if(flag==0){
			for(p=1;p<=n;p++){
				for(q=p+1;q<=n;q++){
					if(t[p]==t[q]||t[p]>n||t[q]>n)point=1;
				}
			}
			if(point==0){
				for(k=n;k>=1;k--){
				 printf("%d ",t[k]);
				}
					printf("\n");
			}
		}
	}
	return 0;
} 
int pow(int a,int b){
	int z=1,y;
	for(y=1;y<=b;y++)z*=a;
	return z;
}



