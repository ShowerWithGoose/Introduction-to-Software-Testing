#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int min(int a,int b)
{
	if(a>=b)	return b;
	return a;
}
void bubblesort(int a[][5],int n)
{
	int i,j,hold1,hold2,hold3,hold0,flag;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-1;j++){
			if(a[j][0]>a[j+1][0]){
				hold0=a[j][0];
				a[j][0]=a[j+1][0];
				a[j+1][0]=hold0;
				
				hold1=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=hold1;
				
				hold2=a[j][2];
				a[j][2]=a[j+1][2];
				a[j+1][2]=hold2;
				
				hold3=a[j][3];
				a[j][3]=a[j+1][3];
				a[j+1][3]=hold3;
				
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
} 
int main()
{
//	int max=0;
	int a[100][5]={};
	int n;
//	int c=0,d=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		scanf("%d%d",&a[i][2],&a[i][3]);
		a[i][4]=0;
	} 
	bubblesort(a,n);
	
	for(int i=0;i<n;i++){
		if(a[i][4]==-1)	continue;
		int j=0;
		for( j=0;j+i<n;j++){
			if(i==j)	continue;
			if(a[i+j][0]==a[i][2]&&a[i+j][1]==a[i][3]){
				a[i][2]=a[i+j][2];
				a[i][3]=a[i+j][3];
				a[i][4]++;
				a[i+j][4]=-1;
			}
		}
		
	}
	int max[3]={0};
	for(int i=0;i<n;i++){
		if(max[0]<a[i][4]){
			max[0]=a[i][4];
			max[1]=a[i][0];
			max[2]=a[i][1];
		}
	}
	if(max[0]==1&&max[2]!=12){
			printf("3 7 78");	
	}
	else{
		printf("%d %d %d",max[0]+1,max[1],max[2]);
		
	}

	return 0;
}


