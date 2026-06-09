#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[11][2],b[11][2],c[122][2]={0},temp;


int main(){
	
	int i=0,j=0,k=0,l=0,m=0,o=0,flag;
	char n;
	for(i=0;n!='\n';i++){
		scanf("%d %d",&a[i][0],&a[i][1]);
		n=getchar();
	}
	n=1;
	for(j=0;n!='\n';j++){
		scanf("%d %d",&b[j][0],&b[j][1]);
		n=getchar();
	}
	
	for(k=0;k<i;k++){
		for(l=0;l<j;l++){
			c[m][0]=a[k][0]*b[l][0];
			c[m][1]=a[k][1]+b[l][1];
			m++;
		}
	}
	
	for(k=0;k<m;k++){
		for(l=k+1;l<m;l++){
			if(c[k][1]==c[l][1]){
				c[k][0]+=c[l][0];
				for(o=l;o<m-1;o++){
					c[o][0]=c[o+1][0];
					c[o][1]=c[o+1][1];
				}
				m--;
				c[o+1][0]=0;
				c[o+1][1]=0;
			}
		}
	}
	
	for(k=0;k<m;k++){
		flag=0;
		for(l=0;l<m-1-k;l++){
			if(c[l][1]<c[l+1][1]){
				temp=c[l+1][0];
				c[l+1][0]=c[l][0];
				c[l][0]=temp;
				temp=c[l+1][1];
				c[l+1][1]=c[l][1];
				c[l][1]=temp;
				flag=1;
			}
		}
		if(!flag)
		break;
	}
	
	for(k=0;k<m;k++){
		if(c[k][0]!=0)
		printf("%d %d ",c[k][0],c[k][1]);
	}
	
	return 0;
} 

