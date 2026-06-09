#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int a[100][2];
	int b[100][2];
	int x[1000][2];
	int i=0;
	int j=0;
	int k=0;	
	int zhi=0;
	int xiang=0;
	int aa=0,bb=0;
	int flag=0;
	int hold;
	for(i=0;i<100;i++){
		a[i][0]=0;
		a[i][1]=0;
		b[i][0]=0;
		b[i][1]=0;
	}
	for(i=0;i<1000;i++){
		x[i][0]=0;
		x[i][1]=0;
	}
	i=0;
	while(scanf("%d%d",&a[i][0],&a[i][1])){
		i++;
		aa++;
		if(getchar()=='\n')
			break;
	}
	i=0;
	while(scanf("%d%d",&b[i][0],&b[i][1])){
		i++;
		bb++;
		if(getchar()=='\n')
			break;
	}
	for(i=0;i<aa;i++){
		for(j=0;j<bb;j++){
			zhi=a[i][1]+b[j][1];
			k=0;
			while(k<xiang){
				if(zhi==x[k][1]){
					flag=1;
					break;
				}
				k++;
			}
			x[k][0]=x[k][0]+(a[i][0]*b[j][0]);
			x[k][1]=zhi;
			if(flag==0)
				xiang++;
			flag=0;
		}
	}
	flag=1;
	if(x[xiang][0]==0&&x[xiang][1]==0)
		flag=0;
	else
		xiang++;
	for(i=0;i<xiang;i++)
		if(x[i][0]==0){
			for(j=i;j<xiang+1;j++){
				x[j][0]=x[j+1][0];
				x[j][1]=x[j+1][0];
			}
			xiang--;
		}
	for(i=0;i<xiang-1;i++){
		flag=0;
		for(j=0;j<xiang-1-i;j++)
			if(x[j][1]<x[j+1][1]){
				hold=x[j][0];
				x[j][0]=x[j+1][0];
				x[j+1][0]=hold;
				hold=x[j][1];
				x[j][1]=x[j+1][1];
				x[j+1][1]=hold;
				flag=1;
			}
		if(flag==0)
			break; 
	}
	for(i=0;i<xiang;i++){
		printf("%d %d ",x[i][0],x[i][1]);
	}
	return 0;
}

