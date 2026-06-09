#include<stdio.h>
#include<string.h>
#include<stdlib.h>//使用qsort函数时的头文件名 
int cmpfunc(const void *a,const void *b)
{
	return *(int*)a - *(int*)b;
}

int main(){
	int n,i,j,k,cnt=1,max=0,max_k=0/*,data[5]*/;
	scanf("%d",&n);
	int coord[105][5];
	memset(coord,0,sizeof(coord));
	int link[105]={0};
	for(i=0;i<n;i++){
		for(j=0;j<4;j++)
			scanf("%d",&coord[i][j]);
	}//分别输入x1，y1，x2，y2  
	
	/*for(i=1;i<n;i++){
		for(j=i;j<n;j++){
			if(coord[j][1]>coord[j+1][1]){
				for(k=1;k<=4;k++){
					data[k]=coord[j][k];
					coord[j][k]=coord[j+1][k];
					coord[j+1][k]=data[k];
				}
			}
		}
	}//线段首端从近到远排序  */
	qsort(coord,n,20,cmpfunc);//线段首端从近到远排序
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(coord[i][2]==coord[j][0]&&coord[i][3]==coord[j][1]){
				link[i]=j;
				break;
			}//编号i线段的末端与编号j线段的首端相连时  
		}
	}
	
	for(i=0,k=0;i<n;){
		if(link[i]!=0){
			cnt++;
			i=link[i];
		}
		if(link[i]==0){
			if(cnt>max){
				max=cnt;
				max_k=k;
			}
			i=k+1;
			k++;
			cnt=1;
		}
	}//注意初始化max和max_k  
	
	printf("%d %d %d",max,coord[max_k][0],coord[max_k][1]);
	return 0;
}

