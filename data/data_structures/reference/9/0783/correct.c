#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[105][5];
struct line{
		int x1;
		int x2;
		int y1;
		int y2;
		int cnt;
	}node[105];
int main()
{
	int i=0;
	int j=0;
	int k=0;
	int p=0;
	int max=0;
	int n=0;
	int flag=0; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j==i)
				continue;
			if(a[i][0]==a[j][2]&&a[i][1]==a[j][3]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			node[k].x1=a[i][0];
			node[k].y1=a[i][1];
			node[k].x2=a[i][2];
			node[k].y2=a[i][3];
			k++;	
		}
		flag=0;
	}
	for(i=0;i<k;i++){
		node[i].cnt=1;
		for(j=0;j<n;j++){
			if(node[i].x2==a[j][0]&&node[i].y2==a[j][1]){
				node[i].x2=a[j][2];
				node[i].y2=a[j][3];
				node[i].cnt++;
				j=-1;
			}
		}
	}
	for(i=0;i<k;i++){
		if(max<node[i].cnt){
			max=node[i].cnt;
			p=i;
		}
	}
	printf("%d %d %d ",node[p].cnt,node[p].x1,node[p].y1);
	return 0;
}


