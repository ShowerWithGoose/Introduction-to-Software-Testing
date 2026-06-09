#include<stdio.h>
#include<stdlib.h>
int a[100][4];

int main(){
	int n,i,j,k,hold=0,max=0,head=0,flag;
	int b[100],c[100],d[100]={0}; 
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	for(i=0;i<n;i++)
		b[i]=i;
	
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-1-i;j++){
			if(a[j][0]>a[j+1][0]){
				hold=a[j][0];a[j][0]=a[j+1][0];a[j+1][0]=hold;
				hold=a[j][1];a[j][1]=a[j+1][1];a[j+1][1]=hold;
				hold=a[j][2];a[j][2]=a[j+1][2];a[j+1][2]=hold;
				hold=a[j][3];a[j][3]=a[j+1][3];a[j+1][3]=hold;
				flag=1;
			}	
		}
		if(flag==0)
				break;
	}
	
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(a[i][2]==a[j][0]&&a[i][3]==a[j][1]){
				b[j]=b[i];
			}
		}
	}
	
	j=0;
	for(i=0;i<n;i++){
		if(b[i]!=i){
			c[j]=b[i];
			j++;
		}
	}
	
	for(i=0;i<j;i++){
		for(k=0;k<j;k++){
			if(c[k]==c[i])
				d[i]++;
		}
	}
	
	for(i=0;i<j;i++){
		if(max<d[i]){
			max=d[i];
			head=c[i];
		}
	}
	
	printf("%d %d %d",max+1,a[head][0],a[head][1]);
	return 0;
}

