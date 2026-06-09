#include <stdio.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}lines[105];
int tmp[105];
int hou_seek(int,int);
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	for(int i=1;i<=n;i++){
		tmp[i]=hou_seek(i,n);
	}
	int max=0,flag=0;
	for(int i=1;i<=n;i++){
		if(tmp[i]>=max){
			max=tmp[i];
			flag=i;
		}
	}
	printf("%d %d %d",tmp[flag],lines[flag].x1,lines[flag].y1);
	return 0;
}
int hou_seek(int n,int k){
	int count=1;
	for(int i=1;i<=k;i++){
		if(lines[n].x2==lines[i].x1&&lines[n].y2==lines[i].y1&&i!=n){
			count+=hou_seek(i,k);
		}
	}
	return count;
}

