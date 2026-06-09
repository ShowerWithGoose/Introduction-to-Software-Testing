#include<stdio.h>
#include<string.h>

typedef struct _line{
	int x;
	int y;
}Line,*pLine;

int main()
{
	Line spot1[100],spot2[100],temp1,temp2,longest;
	int n,i=0,j=0,k=0,num=1,result=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&spot1[i].x,&spot1[i].y,&spot2[i].x,&spot2[i].y);
	}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(spot1[j].x>spot1[j+1].x){
				temp1=spot1[j+1];
				spot1[j+1]=spot1[j];
				spot1[j]=temp1;
				temp2=spot2[j+1];
				spot2[j+1]=spot2[j];
				spot2[j]=temp2;
			}
		}
	}
	for(i=0;i<n-result;i++){
		for(k=i;k<n && j<n;k++){
			for(j=i;j<n;j++){
				if(spot2[k].x==spot1[j].x && spot2[k].y==spot1[j].y){
					num++;
					k=j;
				}
			}			
		}
		if(num>result){
			result=num;
			longest=spot1[i];
		} 
		j=0;
		num=1;
	}
	
	printf("%d %d %d",result,longest.x,longest.y);
	return 0;
}

