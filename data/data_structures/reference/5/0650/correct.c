#include<stdio.h>
#include<string.h>
int a1[1001],a2[1001],b1[1001],b2[1001],c1[1001],c2[1001];
int main(){
	int i,j,k,m=0,n=0,s,t;
	i=0;
	char c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&a1[i],&a2[i],&c);
		++i;
		++m;
	}
	i=0;
	c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&b1[i],&b2[i],&c);
		++i;
		++n;
	}
	k=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			c1[k]=a1[i]*b1[j];
			c2[k]=a2[i]+b2[j];
			k++;
		}
		
	}
	for(i=0;i<k;i++){
		for(j=0;j<k-1;j++){
			if(c2[j]<c2[j+1]){
				t=c2[j];
				c2[j]=c2[j+1];
				c2[j+1]=t;
				s=c1[j];
				c1[j]=c1[j+1];
				c1[j+1]=s;
			}
		}
	}
	for(i=0;i<k;i++){
		if(c2[i]==c2[i+1]&&c2[i]!=0){
			c1[i+1]+=c1[i];
			c1[i]=0;
		}
	}
	
	for(i=0;i<k;i++){
		if(c1[i]!=0){
		
		printf("%d %d ",c1[i],c2[i]);
	    }
	}
	
	return 0;
} 

