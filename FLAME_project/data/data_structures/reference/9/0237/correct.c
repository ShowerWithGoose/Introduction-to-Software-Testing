#include <stdio.h>
struct position{
	int xa;
	int ya;
	int xb;
	int yb;
}; 
int main(){
	int n,i,start=0,max=0,l,count,tailx,taily;
	scanf("%d",&n);
	struct position line[n];
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].xa,&line[i].ya,&line[i].xb,&line[i].yb);
	}
	

	for(l=0;l<n;l++){//l为起点遍历 		
		count=1;
		tailx=line[l].xb;
		taily=line[l].yb;
		flag:
		for(i=0;i<n;i++){//线段连接 
			if(tailx==line[i].xa&&taily==line[i].ya){
				count++;
				tailx=line[i].xb;
				taily=line[i].yb;
				goto flag;								
			}
		}
				
		if(count>max){
			max=count;
			start=l;
		}
	}	
	printf("%d %d %d",max,line[start].xa,line[start].ya);
	
	return 0;
}

