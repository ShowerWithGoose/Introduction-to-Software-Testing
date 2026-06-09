#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}temp,data[108];
int main(){
	//struct line data[110];
	//struct line temp;
	int n,i=0,j=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
	scanf("%d %d %d %d",&data[i].x1,&data[i].y1,&data[i].x2,&data[i].y2);	
	}
	for(i=0;i<n;i++){
	for(j=i;j<n;j++){
	if(data[i].x1>data[j].x1)
	{
	temp=data[i];
	data[i]=data[j];
	data[j]=temp;
	}
    }
}
    int count,count_2=1;
    int x1=0,y1=0;
    for(i=0;i<n;i++){
    int x2,y2;
    count=1;
    x2=data[i].x2;
    y2=data[i].y2;
    for(j=i+1;j<n;j++){
    if(x2==data[j].x1&&y2==data[j].y1)
    {
    count++;
    x2=data[j].x2;
    y2=data[j].y2;
	}
}
	if(count>count_2){
	count_2=count;
	x1=data[i].x1;
	y1=data[i].y1;
	}
}
	printf("%d %d %d\n",count_2,x1,y1);
	return 0;
}

