#include<stdio.h>
#include<stdlib.h>
struct X{
	long long a,x;
}m1[1000],m2[1000],m3[1000][1000],m4[1000000];;
int main(){
	int i=0,j=0;
	char c;
	while(1){
		scanf("%d%d",&m1[i].a,&m1[i].x);
		c=getchar();
		if(c=='\n'){
			break;
		}
		i++;
	}
	while(1){
		scanf("%d%d",&m2[j].a,&m2[j].x);
		c=getchar();
		if(c=='\n'){
			break;
		}
		j++;
	}
	int k,I,J;
	I=i+1;
	J=j+1;
	for(i=0;i<I;i++){
		for(j=0;j<J;j++){
			m3[i][j].a=(m1[i].a)*(m2[j].a);
			m3[i][j].x=m1[i].x+m2[j].x;
		}
	}
	int max=0,site1,site2;
	for(k=0;k<I*J;k++){
		max=0;
		for(i=0;i<I;i++){
			for(j=0;j<J;j++){
				if(m3[i][j].x>=max){
					max=m3[i][j].x;
					site1=i;
					site2=j;
				}
			}
		}
		m4[k].x=max;
		m4[k].a=m3[site1][site2].a;
		m3[site1][site2].x=-1;
	}
	int ans;
	for(i=0;i<I*J-1;i++){
		if(m4[i].x!=m4[i+1].x){
			if(m4[i].a!=0)printf("%lld %lld ",m4[i].a,m4[i].x);
		}else{
			while(m4[i].x==m4[i+1].x){
				m4[i+1].a+=m4[i].a;
				i++;
			}
			if(m4[i].a!=0)printf("%lld %lld ",m4[i].a,m4[i].x);
		}
	}
	printf("%lld %lld ",m4[i].a,m4[i].x);
	return 0;
}

