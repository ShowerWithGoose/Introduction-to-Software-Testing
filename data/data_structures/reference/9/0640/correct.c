#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct xian{
	int Xq,Xh,Yq,Yh;
	int flag;
	int count;
	struct xian *next;
}LINE;
int main(){
	LINE line[101];
	int n,i,j,max = -1;
	int ansx = 0,ansy = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d%d%d%d",&line[i].Xq,&line[i].Yq,&line[i].Xh,&line[i].Yh);
		line[i].flag = -1;
		line[i].count = 1;
		line[i].next = NULL;
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < i;j++){
			if(line[i].Xq == line[j].Xh && line[i].Yq == line[j].Yh){
				line[i].flag = 1;
				line[j].next = &(line[i]);
			}else if(line[i].Xh == line[j].Xq && line[i].Yh == line[j].Yq){
				line[j].flag = 1;
				line[i].next = &(line[j]);
			}
		}
	}
	LINE *temp; 
	for(i = 0;i < n;i++){
		temp = line[i].next;
		while(temp != NULL){
			line[i].count++;
			temp = temp->next;
		}
	}
	for(i = 0;i < n;i++){
		if(line[i].flag == -1){
			if(line[i].count > max){
				max = line[i].count;
				ansx = line[i].Xq;
				ansy = line[i].Yq;
			}
		}
	}
	printf("%d %d %d",max,ansx,ansy);
	return 0; 
}

