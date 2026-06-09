#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
	int a[100][2],b[100][2],c[10000][2];
	int i=0,j=0,k=0;
	char x;
	do{
	scanf("%d%d%c",&a[i][0],&a[i][1],&x);
		i++;
	}while(x!='\n');
	int x1=i+1;
	do{
	scanf("%d%d%c",&b[j][0],&b[j][1],&x);
		j++;
	}while(x!='\n');
	int x2=j+1;
	int num=0;
	for(i=0;i<x1;i++){
		for(j=0;j<x2;j++){
			c[num][0]=a[i][0]*b[j][0];
			c[num][1]=a[i][1]+b[j][1];
			num++;
		}
	}
	int x3=num+1;
	int temp;
	replace(c,x3,temp);
	put(c,x3,temp);
	for(i=0;i<x3;i++){
		if(c[i][0]==0);
		else printf("%d %d ",c[i][0],c[i][1]);
	}
	return 0;
}
void replace(int c[10000][2],int x3,int temp){
	int i=0,j;
	for(i=0;i<x3;i++){
		for(j=i+1;j<x3;j++){
			if(c[i][1]<c[j][1]){
				temp=c[i][1];
				c[i][1]=c[j][1];
				c[j][1]=temp;
				temp=c[i][0];
				c[i][0]=c[j][0];
				c[j][0]=temp;
			}
		}
	}
}
void put(int c[10000][2],int x3,int temp){
	int i=0,j;
	for(i=0;i<x3;i++){
		for(j=i+1;j<x3;j++){
			if(c[i][1]==c[j][1]){
				c[i][0]=c[i][0]+c[j][0];
				c[j][0]=0;
			}
		}
	}
}



