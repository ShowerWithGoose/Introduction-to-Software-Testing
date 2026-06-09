#include <stdio.h>
int ch(int a[105][105],int b,int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i][b]==1){
			return 1;
		}
	}
	return 0;
}
int co(int a[105][105],int b,int n){
	int i;
	for(i=0;i<n;i++){
		if(a[b][i]==1){
			return i;
		}
	}
	return -1;
}
int a[105][105]={0};
int main(){
	int n;
	scanf("%d",&n);
	int i;
	int x1[105],y1[105],x2[105],y2[105];
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	int j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j!=i){
				if(x2[i]==x1[j]&&y2[i]==y1[j]){
					a[i][j]=1;
					break;
				}
			}
		}
	}
	int cnt,max,num;
	max=1;
	num=0;
	for(i=0;i<n;i++){
		cnt=1;
		if(ch(a,i,n)==0){
			j=i;
			while((j=co(a,j,n))!=-1){
				cnt+=1;
			}
		}
		if(cnt>max){
			max=cnt;
			num=i;
		}
	}
	printf("%d %d %d",max,x1[num],y1[num]);
	return 0;
}

