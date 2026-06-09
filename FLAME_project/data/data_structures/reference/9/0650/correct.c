#include<stdio.h>
#include<string.h>
struct Line{
	int x1;
	int x2;
	int y1;
	int y2;
	int number;
};
int main()
{
	int i=0,j=0,n,k=0,mid=0,max=0,t;
	int p[101][101];
	struct Line info[101];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		while(p[i][0]>=p[i][2]){
			scanf("%d%d%d%d",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)
			continue;
			if(p[i][0]==p[j][2]&&p[i][1]==p[j][3]){
				mid++;
				break;
			}
			
		}
		if(mid==0){
			info[k].x1=p[i][0];
			info[k].y1=p[i][1];
			info[k].x2=p[i][2];
			info[k].y2=p[i][3];
			k++;
		}
		mid=0;
	}
	for(i=0;i<k;i++){
		info[i].number =1;
		for(j=0;j<n;j++){
			if(info[i].x2==p[j][0]&&info[i].y2==p[j][1]){
				info[i].x2=p[j][2];
				info[i].y2=p[j][3];
				info[i].number++;
				j=-1;
			}
		}
	}
	for(i=0;i<k;i++){
		if(max<info[i].number){
			max=info[i].number;
			t=i;
		}
	}
	printf("%d %d %d\n",info[t].number,info[t].x1,info[t].y1);
	return 0;
}

