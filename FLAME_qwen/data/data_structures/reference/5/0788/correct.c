#include<stdio.h>
int main(){
	long long a[1000][2],b[1000][2],c[10000][2],p[10000][2];
	int i,j,k,t,n=0,m=0;
	char l1='\0',l2='\0';
	for(n=0;l1!='\n';n++){
    	scanf("%lld%lld%c",&a[n][0],&a[n][1],&l1);
	}
	for(m=0;l2!='\n';m++){
    	scanf("%lld%lld%c",&b[m][0],&b[m][1],&l2);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c[k][0]=a[i][0]*b[j][0];
			c[k][1]=a[i][1]+b[j][1];
			k++;
		}
	}
	k=0;
    for(j=0;j<m*n;j++)
      for(i=0;i+1<n*m-j;i++)
        if(c[i][1]<c[i+1][1]){
            t=c[i][1];c[i][1]=c[i+1][1];c[i+1][1]=t;
            t=c[i][0];c[i][0]=c[i+1][0];c[i+1][0]=t;
        }
    for(i=0;i<n*m;i++){
    	if(c[i+1][1]==c[i][1]){
        	p[k][0]+=c[i][0];
	    }
	    else{
        	p[k][0]+=c[i][0];
        	p[k][1]=c[i][1];
			k++;	    	
		}
	}  
	for(i=0;i<=k;i++)
	if(p[i][0]!=0)
	printf("%lld %lld ",p[i][0],p[i][1]);  
} 

