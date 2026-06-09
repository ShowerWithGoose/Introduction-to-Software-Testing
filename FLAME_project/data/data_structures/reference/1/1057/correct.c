#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAXN 12
//define mst(s) memset(s,0,sizeof(s))
int bl[MAXN],a[MAXN];
int max,depth=1;
void tree(){
	int i,lst;
	if(depth==max){
		for(lst=1;lst<=max;lst++){
			if(!bl[lst]){
				a[depth]=lst;
				break;
			}else;
		}
		for(i=1;i<=max;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		a[depth--]=bl[lst]=0;
		return 0;
	}else;
	for(i=1;i<=max;i++){
		if(bl[i]);
		else{
			bl[i]=1;
			a[depth++]=i;
			tree();
			a[depth]=bl[i]=0;
		}
	}
	depth--;
	return 0;
}
int main(void)
{
	//freopen("in.fp.txt","r",stdin);
	int i,j,k,n,m;
	scanf("%d",&max);
	tree();
	return 0;
}



