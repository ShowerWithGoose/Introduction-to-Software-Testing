#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	int line[100][2][2]={0};
	int flag[100]={0};
	int count[100]={1};
	int n;
	int hold;
	int same;
	int xx;
	int yy;
	int i=0;
	int j=0;
	int re=0;
	int point=0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d%d%d%d",&line[i][0][0],&line[i][0][1],&line[i][1][0],&line[i][1][1]);
		i++;
	}
	for(i=0;i<n;i++){
		count[i]=1;
	}
	i=0;
	for(i=0;i<n-1;i++){
		same=0;
		for(j=0;j<n-1-i;j++)
			if(line[j][0][0]>line[j+1][0][0]){
				hold=line[j][0][0];
				line[j][0][0]=line[j+1][0][0];
				line[j+1][0][0]=hold;
				hold=line[j][0][1];
				line[j][0][1]=line[j+1][0][1];
				line[j+1][0][1]=hold;
				hold=line[j][1][0];
				line[j][1][0]=line[j+1][1][0];
				line[j+1][1][0]=hold;
				hold=line[j][1][1];
				line[j][1][1]=line[j+1][1][1];
				line[j+1][1][1]=hold;
				same=1;
			}
			if(same==0)
				break;
	}
	i=0;
	while(i<n){
		if(flag[i]==0){
			xx=line[i][1][0];
			yy=line[i][1][1];
			j=i+1;
			while(j<n){
				if(xx==line[j][0][0]&&yy==line[j][0][1]){
					count[i]=count[i]+1;
					xx=line[j][1][0];
					yy=line[j][1][1];
					flag[j]=1;
				}
				j++;
			}
		}
		i++;
	}
	i=j=0;
	while(i<n){
		if(count[i]>re){
			re=count[i];
			point=i;
		}
		i++;
	}
	/*i=j=0;
	while(i<n){
		printf("%d %d %d %d\n",line[i][0][0],line[i][0][1],line[i][1][0],line[i][1][1]);
		i++;
	}*/
	
	printf("%d %d %d",re,line[point][0][0],line[point][0][1]);
	return 0;
}

