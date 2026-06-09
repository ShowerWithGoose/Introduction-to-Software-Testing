#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//在输入中只出现系数不为0的项。
//最后一项的指数后没有空格，只有一个回车换行符。
//将系数不为0的项按指数从高到低的顺序输出
typedef struct node{
	int coe;//coefficient
	int pow;
//	struct node *link;
}node;
int main(){
	node line1[105];
	node line2[105];
	node line3[105];
	node line4[105];
	int i=0,j=0,k,t;
	char d,e;
	while(1){
	//	i++;
	scanf("%d %d",&line1[i].coe,&line1[i].pow);
	i++;
	scanf("%c",&d);
			if(d=='\n'){
				break;
			}
	}

	while(1){
		scanf("%d%d",&line2[j].coe,&line2[j].pow);
		j++;
		scanf("%c",&e);
			if(e=='\n'){
				break;
			}
	}
	
	k=i,t=j;
	int x=0,y=0;
	for(i=0;i<k;i++){
		for(j=0;j<t;j++){
			line3[x].coe=line1[i].coe*line2[j].coe;
			if(line3[x].coe==0){
				continue;
			}
			line3[x].pow=line1[i].pow+line2[j].pow;
			x++;
		}
		
		
	}
	y=x;
	for(i=0;i<y;i++){
		for(j=i+1;j<y;j++){
			if(line3[j].pow>line3[i].pow){
				t=line3[j].pow;
				line3[j].pow=line3[i].pow;
				line3[i].pow=t;
				t=line3[j].coe;
				line3[j].coe=line3[i].coe;
				line3[i].coe=t;
				
			}
		}
	}
	x=0;
	for(i=0;i<y;i++){
		if(line3[i].coe==0){
		
			continue;
		}
		line4[x]=line3[i];
		
		for(j=i+1;j<y;j++){
			if(line3[j].pow==line3[i].pow){
				line4[x].coe=line3[j].coe+line4[x].coe;
				line3[j].coe=0;
			}
		}
		x++;
		}
	for(i=0;i<x;i++){
		printf("%d %d ",line4[i].coe,line4[i].pow);
	}
	
	
	return 0;
}

