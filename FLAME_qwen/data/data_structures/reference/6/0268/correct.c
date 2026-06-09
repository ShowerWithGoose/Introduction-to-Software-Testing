#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define st struct
#define stmalloc(p) (struct p*)malloc(sizeof(struct p))
int a[105];
int p=-1;
int main(){
	int i=0,key,elem;
	while(1){
		in(key);
		if(key==1){
			in(elem);
			if(p<100)	a[++p]=elem;
			else pr("error ");
		}else if(key==0){
			if(p==-1) pr("error ");
			else pr("%d ",a[p]),a[p--]=0;
		}else if(key==-1) break; 
	}
	
	
return 0;
}



