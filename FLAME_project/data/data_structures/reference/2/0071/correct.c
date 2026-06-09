#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
int main(){
	char y1,y2,y='+';
	int x1,x2,ans=0;
	while(1){
		scanf("%d %c",&x1,&y1);
		while(y1=='*'||y1=='/'){
			scanf("%d %c",&x2,&y2);
			if(y1=='*'){
				x1*=x2;
			}
			else{
				x1/=x2;
			}
			y1=y2;
		}
		if(y=='+'){
			ans+=x1;
		}
		else if(y=='-'){
			ans-=x1;
		}
		y=y1;
		if(y=='='){
			printf("%d",ans);
			return 0;
		}
		
	}
}






