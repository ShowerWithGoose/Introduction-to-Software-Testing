#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1,y1,x2,y2,m;
};
struct line locate[100];
int main(){
	int i=0,j,n,f,num1,num=1,mx1,my1,mx,my;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&locate[i].x1,&locate[i].y1,&locate[i].x2,&locate[i].y2);
	}
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n;j++){
			if(locate[i].x2==locate[j].x1&&locate[i].y2==locate[j].y1){
				locate[i].m=j;
				f=1;
			}
		}
		if(f==0) locate[i].m=-1;		
	}
	for(i=0;i<n;i++){
		num1=1,mx1=locate[i].x1,my1=locate[i].y1;
		j=i;
		while(locate[j].m!=-1){
			num1++;
			j=locate[j].m;
		}
		if(num1>num) num=num1,mx=mx1,my=my1;
	}
	printf("%d %d %d",num,mx,my);
	return 0;
} 

