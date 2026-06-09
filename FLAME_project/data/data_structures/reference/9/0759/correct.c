#include<stdio.h>
int main()
{
	int x[100][2],y[100][2],mid[2],n,i,j,k,len,max=1,q=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
	for(i=0;i<n;i++){
		mid[0]=x[i][1];
		mid[1]=y[i][1];
		len=1;
		for(k=0;k<n;k++)
			for(j=0;j<n;j++){
				if(x[j][0]==mid[0]&&y[j][0]==mid[1]){
					len++;
					mid[0]=x[j][1];
					mid[1]=y[j][1];
				}
		}
		if(len>max){
			max=len;
			q=i;
		}
	}
	printf("%d %d %d",max,x[q][0],y[q][0]);
	return 0;
}

