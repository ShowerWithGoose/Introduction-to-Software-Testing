#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

int pos[100][4];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&pos[i][0],&pos[i][1],&pos[i][2],&pos[i][3]);
	}
//	int start_pos[2];
	int now_pos[2];
	int long_num[100]={};
	for(int i=0;i<100;i++){
		long_num[i]=1;
	}
	for(int i=0;i<n;i++){
//		start_pos[0]=pos[i][0];
//		start_pos[1]=pos[i][1];
		now_pos[0]=pos[i][2];
		now_pos[1]=pos[i][3];		
		for(int j=0;j<n;j++){
			if(now_pos[0]==pos[j][0]&&now_pos[1]==pos[j][1]){
				long_num[i]++;
				now_pos[0]=pos[j][2];
				now_pos[1]=pos[j][3];
				j=-1;
				continue;
			}
		}
	}
	int max=-1;
	int dig=0;
	for(int i=0;i<n;i++){
		if(long_num[i]>max){
			max=long_num[i];
			dig=i;
		}
	}
	printf("%d %d %d",max,pos[dig][0],pos[dig][1]);
	
	
 	return 0;
 }

