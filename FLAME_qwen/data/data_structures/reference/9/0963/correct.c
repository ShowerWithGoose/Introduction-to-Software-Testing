#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int line[100][4];
int head[100][2],end[100][2],cnt[100];
int main(){
	int n,i,j,max=0,flag=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
	}
	for(i=0;i<n;i++){
		head[i][0]=line[i][0];
		head[i][1]=line[i][1];
		end[i][0]=line[i][2];
		end[i][1]=line[i][3];
		do{
		flag=0;
		for(j=0;j<n;j++){
			if(end[i][0]==line[j][0]&&end[i][1]==line[j][1]){
				cnt[i]++;
				end[i][0]=line[j][2];
				end[i][1]=line[j][3];
				flag=1;
			}
		}
		if(cnt[max]<cnt[i]) max=i;
		}while(flag==1);
	}
	printf("%d %d %d",cnt[max]+1,head[max][0],head[max][1]);
	return 0;
}


