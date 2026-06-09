#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int a[110],c[110];
struct location{
	int x1;
	int y1;
	int x2;
	int y2;
}; 
int main()
{
	int n,max=0,t=0,k;
	struct location line[110];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((line[i].x2==line[j].x1)&&(line[i].y2==line[j].y1)){
				a[i]=j; 
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			k=i;
        	while(a[i]!=0){
        		i=a[i];
				c[k]++;
			}
			i=k;
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]>max){
			max=c[i];
			t=i; 
		}
	}
	printf("%d %d %d",max+1,line[t].x1,line[t].y1);
	return 0;
}


