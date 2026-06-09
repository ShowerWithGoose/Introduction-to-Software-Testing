#include<stdio.h>
long long  m[100];
long long  a1[100];
long long  a2[100];
long long  k1[100];
long long  k2[100];
long long  a3[100];
long long  k3[100];
char s1[1000],s2[1000];
int i,j,t1,t2;
int d;
long long temp;
int n;
int main(){
	gets(s1);
	gets(s2);
	j=1;
	for(i=0;i<strlen(s1);i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			m[j]=m[j]*10+(int)(s1[i]-'0');
		}
		else{
			j++;
		}
	} 
	t1=j;
	j++;
	for(i=0;i<strlen(s2);i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			m[j]=m[j]*10+(int)(s2[i]-'0');
		}
		else{
			j++;
		}
	} 
	for(i=1,d=1;i<=t1;i=i+2,d++){
		a1[d]=m[i];
		k1[d]=m[i+1];
	}
	for(i=t1+1,d=1;i<=j;i=i+2,d++){
		a2[d]=m[i];
		k2[d]=m[i+1];
	}
	t2=(j-t1)/2;
	t1=t1/2;
	d=1;
	for(i=1;i<=t1;i++){
		for(j=1;j<=t2;j++){
			k3[d]=k1[i]+k2[j];
			a3[d]=a1[i]*a2[j];
			d++;
		}
	}
	for(i=1;i<d;i++){
		for(j=i+1;j<=d;j++){
			if(k3[i]==k3[j]){
				a3[i]=a3[i]+a3[j];
				k3[j]=-1;
			}
		}
	}
	for(i=1;i<d;i++){
		for(j=1;j<=d;j++){
			if(k3[i]>k3[j]){
				temp=k3[i];
				k3[i]=k3[j];
				k3[j]=temp;
				temp=a3[i];
				a3[i]=a3[j];
				a3[j]=temp;
			}
		}
	}
	for(i=1;i<=d;i++){
		if(k3[i]!=-1){
			if(!(a3[i]==0&&k3[i]==0)) printf("%lld %lld ",a3[i],k3[i]);
		}
	}
	
	return 0;	
}

