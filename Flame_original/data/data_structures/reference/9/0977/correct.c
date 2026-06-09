#include<stdio.h>
#include<string.h>
struct L{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
int main(){
	int n;
	scanf("%d",&n);
	int i=0,j=0,k=0,max=0,mid=0,res=0;
	struct L arr[110];
	int x[110][4];
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x[i][0],&x[i][1],&x[i][2],&x[i][3]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				continue;
			}
			if(x[i][0]==x[j][2]&&x[i][1]==x[j][3]){
				mid=1;
				break;
			}
		}
		if(mid==0){
			arr[k].x1=x[i][0];
			arr[k].y1=x[i][1];
			arr[k].x2=x[i][2];
			arr[k].y2=x[i][3];
			k++;
		}
		mid=0;
	}
	for(i=0;i<k;i++){
		arr[i].num=1;
		for(j=0;j<n;j++){
			if(arr[i].x2==x[j][0]&&arr[i].y2==x[j][1]){
				arr[i].x2=x[j][2];
				arr[i].y2=x[j][3];
				arr[i].num++;
				j=-1;
			}
		}
	}
	for(i=0;i<k;i++){
		if(max<arr[i].num){
			max=arr[i].num;
			res=i;
		}
	}
	printf("%d %d %d",arr[res].num,arr[res].x1,arr[res].y1);
	return 0;
} 

