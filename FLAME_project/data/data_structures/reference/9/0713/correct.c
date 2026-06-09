#include <stdio.h>
#include <stdlib.h>
int read(){
	int x;
	scanf("%d",&x);
	return x;
}

int main(){
	int **s,*cnt;//s为二维数组记录线段数据，cnt记录连接线段个数
	int n,result=0,result_i=0;
	int i=0,j=0,k=0;
	const int N=4;
	scanf("%d",&n);
	s=(int**)malloc(sizeof(int *)*n);
	for(i=0;i<n;i++){
		s[i]=(int*)malloc(sizeof(int)*N);
	}
	cnt=(int*)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++){//输入线段数据
		for(j=0;j<N;j++){
			s[i][j]=read();
		}
		cnt[i]=1;//起始包含一条线段，置为1
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){//向后遍历
			if(s[i][2]==s[j][0] && s[i][3]==s[j][1]){//往后延长线段
				s[i][2]=s[j][2];
				s[i][3]=s[j][3];//改变s[i]末端点，延长线段s[i]
				s[j][0]=0;
				s[j][1]=0;//s[j]线段前端已接置为0
				cnt[i]++;//s[i]所在线段数增加1
				j=i;//重新回到此位置开始向后遍历				
			}
			if(s[i][0]==s[j][2] && s[i][1]==s[j][3]){//往前延长线段
				s[i][0]=s[j][0];
				s[i][1]=s[j][1];//改变s[i]首端点，延长线段s[i]
				s[j][2]=0;
				s[j][3]=0;//s[j]线段末端已接置为0
				cnt[i]++;
				j=i;					
			}
		}
	}
	for(i=1;i<n;i++){
		for(k=i-1;k>=0;k--){//向前遍历
			if(s[i][2]==s[k][0] && s[i][3]==s[k][1]){//往后延长线段
				s[i][2]=s[k][2];
				s[i][3]=s[k][3];
				s[k][0]=0;
				s[k][1]=0;
				cnt[i]++;
				k=i;				
			}
			if(s[i][0]==s[k][2] && s[i][1]==s[k][3]){//往前延长线段
				s[i][0]=s[k][0];
				s[i][1]=s[k][1];
				s[k][2]=0;
				s[k][3]=0;
				cnt[i]++;
				k=i;					
			}
		}
	}	
	for(i=0;i<n;i++){//遍历寻找最大线段数
		if(cnt[i]>result){
			result=cnt[i];
			result_i=i;
		}
	}
	printf("%d %d %d\n",result,s[result_i][0],s[result_i][1]);
//	printf("%d %d",s[result_i][2],s[result_i][3]);
	free(s);
	free(cnt);
	
	return 0;
}



