#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int a[1024],a1[1024],b[1024],b1[1024],c[1024],c1[1024],d,d1,e[1024],e1[1024],i=0,j=0,k=0,n=0,m=0;
	char s[1024],s1[1024];
	while(i>=0){
		scanf("%d%d%c",&a[i],&a1[i],&s[i]);
		i++;
		if(s[i-1]=='\n')break; 
	}n=i;
	i=0;
	memset(s,0,sizeof(s));
	while(i>=0){
		scanf("%d%d%c",&b[i],&b1[i],&s[i]);
		i++;
		if(s[i-1]=='\n')break;
	}m=i;
	memset(c,0,sizeof(c));
	memset(c1,0,sizeof(c1));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c1[k]=a1[i]+b1[j];
			c[k]=a[i]*b[j];
			k++;
		}
	}
	for(i=0;i<k;i++)
		for(j=i+1;j<=k;j++){
			if(c1[i]<c1[j]){
				d1=c1[i];
				c1[i]=c1[j];
				c1[j]=d1;
				d=c[i];
				c[i]=c[j];
				c[j]=d;
			}
		}
	m=0;n=0;
	memset(e,0,sizeof(e));
	memset(e1,0,sizeof(e1));	
	for(i=0;i<k;i++){
		m=0;
		for(j=0;j<=k;j++){
			if(c1[i]==e1[j]){
				e[j]+=c[i];
				m=1;
				break;
			}
		}
		if(m==0){
			e1[n]=c1[i];
			e[n]=c[i];
			n++;
		}
	}
	for(i=0;i<=n;i++){
		if(e[i]==0)continue;
		printf("%d %d ",e[i],e1[i]);
	}
	return 0;
}

