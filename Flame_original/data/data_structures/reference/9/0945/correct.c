#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int b[110][5];

int main(){
	
	int n,i,j,k,line=0,x,y,lineMax=-1,x0,y0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	for(j=0;j<4;j++)
	scanf("%d",&b[i][j]);
	
	for(i=0;i<n;i++){
		line=0;
		x=b[i][2]; y=b[i][3];
		for(j=0;j<n;j++){
			if(i==j||j==k)
			continue;
			if(x==b[j][0]&&y==b[j][1]){
				line++;
				x=b[j][2]; y=b[j][3];
				k=j; j=-1;
			}
			
		}
		if(lineMax<line){
			lineMax=line;
			x0=b[i][0]; y0=b[i][1];
		}
		
	}
	printf("%d %d %d",lineMax+1,x0,y0);
	return 0;
}

