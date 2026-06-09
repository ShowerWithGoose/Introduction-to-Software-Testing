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
#define st strcut
int a[3628810][10],b[11];
ll num=0;
int n;
void swap(int* a,int* b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

ll N(int n){
	int i,out=1;
	fr(i,2,n+1){
		out*=i;
	}
	return out;
}

void A(int m){
	int i,j;
	if(m==n-1){
		fr(i,0,n) a[num][i]=b[i];
		num++;
		return ;
	}
	else fr(i,m,n){
		swap(&b[m],&b[i]);
		A(m+1);
		swap(&b[m],&b[i]);
	}
}

int cmp(int t){
	int i;
	fr(i,0,n){
		if(a[t][i]-a[t+1][i]) return(a[t][i]-a[t+1][i]);
	}
}

int main(){
       int i,j,k,cnt=0,jud;
       ll all;
		in(n);
		all=N(n);
		num=0;
		fr(i,0,n) b[i]=i+1;
		A(0);
				
	for(i=0;i<all-1;i++){
			jud=0;
		for(j=0;j<all-i-1;j++){
		if(cmp(j)>0){
			fr(k,0,n) b[k]=a[j][k];
			fr(k,0,n) a[j][k]=a[j+1][k];
			fr(k,0,n) a[j+1][k]=b[k];
			jud=1; 
		}
		}
		if(jud==0) break;
		}

		fr(num,0,all){
			fr(i,0,n) pr("%d ",a[num][i]);
			pn;
		} 		
return 0;
}



