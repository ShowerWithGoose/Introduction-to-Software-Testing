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
#define max(s,b) (s>b?s:b)
#define min(s,b) (s<b?s:b)
#define st struct
#define stmalloc(p) (struct p*)malloc(sizeof(struct p))
int s[105];
int p=-1;
int main(){
	int i=0,a,b;
	while(1){
		in(a);
		if(a==1){
			in(b);
			if(p<100)	s[++p]=b;
			else pr("error ");
		}else if(a==0){
			if(p==-1) pr("error ");
			else pr("%d ",s[p]),s[p--]=0;
		}else if(a==-1) break; 
	}
	
	
return 0;
}



