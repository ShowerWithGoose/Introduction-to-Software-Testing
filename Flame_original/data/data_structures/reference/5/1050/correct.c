#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int min1,min2,a1[1000],a2[1000],b1[1000],b2[1000],i=0,j=0,c1[10000],c2[10000],k=0,m,n,f=0;
char c='0';
for(i=0;i<1000&&c!='\n';i++){
	scanf("%d%d",&a1[i],&a2[i]);
	c=getchar();
}
n=i;
c='0';
for(j=0;j<1000&&c!='\n';j++){
	scanf("%d%d",&b1[j],&b2[j]);
	c=getchar();
}
m=j;
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		c1[k]=a1[i]*b1[j];
		c2[k]=a2[i]+b2[j];
		k++;
	}
}
n=k;
for(i=0;i<n;i++){
		if(c1[i]==-1&&c2[i]==-1)
		continue;
	for(j=i+1;j<n;j++){
		if(c2[i]==c2[j])
		{
			c1[i]=c1[i]+c1[j];
			c1[j]=-1;
			c2[j]=-1;
			f++;
		}
	}
}
for(i=0;i<n-1;i++) {
	for(j=0;j<n-1-i;j++){
	if(c2[j]<c2[j+1]){
		min1=c1[j];
		c1[j]=c1[j+1];
		c1[j+1]=min1;
		min2=c2[j];
		c2[j]=c2[j+1];
		c2[j+1]=min2;
	}
	}	
		}
		for(i=0;i<n-f-1;i++){
			printf("%d %d ",c1[i],c2[i]);
		}
			printf("%d %d",c1[i],c2[i]);
return 0;
}





