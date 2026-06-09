#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int begin_x,begin_y;
int temp_x1,temp_y1,temp_x2,temp_y2;
int main()
{
	int n,i,j,k,l,sum=0,max=0;
	int x1[105],y1[105],x2[105],y2[105];
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(x1[i]>x1[j]){
				temp_x1=x1[i];
				temp_y1=y1[i];
				temp_x2=x2[i];
				temp_y2=y2[i];
				x1[i]=x1[j];
				y1[i]=y1[j];
				x2[i]=x2[j];
				y2[i]=y2[j];
				x1[j]=temp_x1;
				y1[j]=temp_y1;
				x2[j]=temp_x2;
				y2[j]=temp_y2;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		k=i;
		sum=0;
		for(j=i+1;j<=n;j++){
			if(x2[k]==x1[j]){
				if(y2[k]==y1[j]){
					sum++;
					k=j;
				}
			}
		}
		if(sum>max){
			max=sum;
			begin_x=x1[i];
			begin_y=y1[i];
		}
	}
	printf("%d %d %d",max+1,begin_x,begin_y);
	return 0;
}

