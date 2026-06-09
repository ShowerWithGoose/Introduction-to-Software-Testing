#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
int length;

}lne[105];

int main()
{
int n;
int max=0;
struct line lne[102];
scanf("%d",&n);
int i,j,k,x,y;
int q,w;
for(i=0;i<n;i++){
	scanf("%d%d%d%d",&lne[i].x1,&lne[i].y1,&lne[i].x2,&lne[i].y2);
	lne[i].length=1;
	lne[105].x1=0;
	lne[105].x2=0;
	lne[105].y1=0;
	lne[105].y2=0;
	lne[105].length=0;
	
}
int cmp;
for(q=0;q<n;q++){
	for(w=q+1;w<n;w++){
		if(lne[w].x1<lne[q].x1){
			lne[105]=lne[w];
			lne[w]=lne[q];
			lne[q]=lne[105];
		}
	}
}
i=0;
for(j=0;j<n;j++){
	i=j;
	for(k=j+1;k<n;k++){
		if(lne[k].x1==lne[i].x2&&lne[k].y1==lne[i].y2){
			lne[j].length=1+lne[j].length;
			i=k;
		}
		
	}
}

for(x=0;x<n;x++){
	if(lne[x].length>max){
		max=lne[x].length;
		y=x;
	}
}
printf("%d %d %d",max,lne[y].x1,lne[y].y1);
return 0;
}





