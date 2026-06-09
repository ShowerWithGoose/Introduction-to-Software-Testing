#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int s;
}l[1000];
int main()
{
	int n;
	scanf("%d",&n);
    struct line l[1000];
	int i,j=0,k=0,q=0,max=0;
	int w[100][4];
	for(i=0;i<n;i++){
	
	scanf("%d%d%d%d",&w[i][0],&w[i][1],&w[i][2],&w[i][3]);
		
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j)  continue;
			if(!(w[i][0]==w[j][2]&&w[i][1]==w[j][3])){
	            l[k].x1 =w[i][0];
				l[k].y1 =w[i][1];
				l[k].x2 =w[i][2];
				l[k].y2 =w[i][3];
				k++;
           }
    }
	}
	for(i=0;i<k;i++){
		l[i].s =1;
		for(j=0;j<n;j++){
			if(l[i].x2 ==w[j][0]&&l[i].y2 ==w[j][1]){
				l[i].x2 =w[j][2];
				l[i].y2 =w[j][3];
				l[i].s ++;
				j=-1;
			}
		}
	}
	for(i=0;i<k;i++){
		if(max<l[i].s ){
			max=l[i].s ;
			q=i;
		}
	}
	printf("%d %d %d\n",l[q].s ,l[q].x1 ,l[q].y1 );
	return 0;
}

