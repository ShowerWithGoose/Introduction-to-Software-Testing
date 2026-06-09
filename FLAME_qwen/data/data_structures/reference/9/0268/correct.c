#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define pc putchar
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define st struct
int x[1000][2],y[1000][2],line[1000],jud[1000];
int n;

void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

int search(int a){
	int t;
	fr(t,a+1,n){
		if(x[a][1]==x[t][0]&&y[a][1]==y[t][0]){
			jud[t]=1;
			return 1+search(t);
		}
	}
	return 0;
}

int main(){
       int i,j,root=0,maxcnt=0,tep,ju=0;
		in(n);
		gc;
		fr(i,0,n-1) sc("%d %d %d %d\n",&x[i][0],&y[i][0],&x[i][1],&y[i][1]);
		sc("%d %d %d %d",&x[n-1][0],&y[n-1][0],&x[n-1][1],&y[n-1][1]);
		for(i=0;i<n-1;i++){
			ju=0;
		for(j=0;j<n-i-1;j++){
		if(x[j][0]>x[j+1][0]){
			swap(&x[j][0],&x[j+1][0]);
			swap(&x[j][1],&x[j+1][1]);
			swap(&y[j][0],&y[j+1][0]);
			swap(&y[j][1],&y[j+1][1]);
			ju=1; 
		}
		}
		if(ju==0) break;
		}
		
		fr(i,0,n){
			if(jud[i]==0){
			tep=search(i);
			if(tep>maxcnt){
				maxcnt=tep;
				root=i;
			}
		}
		}
		pr("%d %d %d",1+maxcnt,x[root][0],y[root][0]);
return 0;
}

