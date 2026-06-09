#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}Line;
int check(int num,int x,int y);
Line s[100],ch,k[100];
int n,max=0,now=1,maxx,maxy;
int main(){	
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
		k[i]=s[i];
	}
	for(i=0;i<n;++i){
		for(j=0;j<n-i-1;++j){
			if(s[j].x1>s[j+1].x1){
				ch=s[j];
				s[j]=s[j+1];
				s[j+1]=ch;
			}
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n-i-1;++j){
			if(k[j].x2>k[j+1].x2){
				ch=k[j];
				k[j]=k[j+1];
				k[j+1]=ch;
			}
		}
	}
	for(i=0;i<n;++i){
		now=check(1,k[i].x2,k[i].y2);
		if(now>max){
			max=now;
			maxx=k[i].x1;
			maxy=k[i].y1;
		}
	}
	printf("%d %d %d",max,maxx,maxy);
	return 0;
}
int check(int num,int x,int y){
	int t;
	for(t=0;t<n;t++){
		if(s[t].x1==x&&s[t].y1==y){
			return check(num+1,s[t].x2,s[t].y2);
		}
		else if(s[t].x1>x){
			return num;
		}		
	}
	return num;
}

