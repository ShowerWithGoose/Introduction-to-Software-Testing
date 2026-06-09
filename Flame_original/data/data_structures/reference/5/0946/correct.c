#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define LL long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int main()
{
	int i,j,k,l,x1[10000],x2[10000],z1[10000],z2[10000],x3[1000],z3[1000];
	char c;
	for(i = 0; ;i++){
		scanf("%d%d",&x1[i],&z1[i]);
		c=getchar();
		if(c == '\n') break;
	}
	for(j = 0; ;j++){
		scanf("%d%d",&x2[j],&z2[j]);
		c=getchar();
		if(c == '\n') break;
	}
	int m=0;
	for(k = 0;k <= i;k++){
		for(l = 0;l <= j;l++){
			x3[m] = x1[k]*x2[l];
			z3[m] = z1[k]+z2[l];
			m++;
		}
	}
	int n,p;
	for(n = 0;n <= m;n++){
		for(p = n+1;p <= m;p++){
			if(z3[n] == z3[p]&&x3[p] != 0&&n != p){
				x3[n] = x3[n]+x3[p];
				x3[p] = 0;
			}
		}
	}
	int t;
	for(i = 0;i < m;i++){
		for(j = 0;j < m-i;j++){
			if(z3[j+1] > z3[j]){
				t = z3[j+1];
				p = x3[j+1];
				z3[j+1] = z3[j];
				x3[j+1] = x3[j];
				z3[j] = t;
				x3[j] = p;
			}
		}
	}
	for(i = 0;i <= m;i++){
		if(x3[i] != 0) printf("%d %d ",x3[i],z3[i]);
	}
	return 0;
}
	



