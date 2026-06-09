#include<stdio.h>
#include<stdlib.h>
struct link{
	int x1,x2,y1,y2;
	int flag;
};
struct link line[100];
int main(){
	int n,i,j,k,a,b,ax,ay,bx,by;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	line[i].flag=0;
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if((line[i].x1==line[j].x1&&line[i].y1==line[j].y1)
			|| (line[i].x1==line[j].x2&&line[i].y1==line[j].y2)
			|| (line[i].x2==line[j].x1&&line[i].y2==line[j].y1)
			|| (line[i].x2==line[j].x2&&line[i].y2==line[j].y2)){
				line[i].flag++;
				line[j].flag++;
			}
		}
	}
	int tem,flag1,max=0;
	for(i=0;i<n;i++){
		flag1=0;
		tem=-1;
		if(line[i].flag==1){
			j=i;
			do{
				for(k=0;k<n;k++){
					if(k==j||k==tem)
					continue;
					if((line[k].x1==line[j].x1&&line[k].y1==line[j].y1)
					|| (line[k].x1==line[j].x2&&line[k].y1==line[j].y2)
					|| (line[k].x2==line[j].x1&&line[k].y2==line[j].y1)
					|| (line[k].x2==line[j].x2&&line[k].y2==line[j].y2)){
						tem=j;
						j=k;
						flag1++;
					}
				}
			}while(line[j].flag==2);
		}
		flag1++;
		if(flag1>max){
			a=i;
			b=j;
			max=flag1;
		}
	}
	int flag2=0,flag3=0;
	for(i=0;i<n&&i!=a;i++){
		if((line[a].x1==line[i].x1&&line[a].y1==line[i].y1)
		|| (line[a].x1==line[i].x2&&line[a].y1==line[i].y2)){
			flag2=1;
			break;
		}
	}
	if(flag2==0){
		ax=line[a].x1;
		ay=line[a].y1;
	}
	else{
		ax=line[a].x2;
		ay=line[a].y2;
	}
	for(i=0;i<n&&i!=b;i++){
		if((line[b].x1==line[i].x1&&line[b].y1==line[i].y1)
		|| (line[b].x1==line[i].x2&&line[b].y1==line[i].y2)){
			flag3=1;
			break;
		}
	}
	if(flag3==0){
		bx=line[b].x1;
		by=line[b].y1;
	}
	else{
		bx=line[b].x2;
		by=line[b].y2;
	}
	if(ax>bx)
	printf("%d %d %d",max,bx,by);
	else
	printf("%d %d %d",max,ax,ay);
	return 0;
}



