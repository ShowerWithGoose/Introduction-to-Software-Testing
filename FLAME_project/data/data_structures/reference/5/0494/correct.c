#include<stdbool.h>
#include<stdio.h>
#define maxn 1005
int a[maxn],b[maxn],m[maxn],n[maxn];
int res1[maxn*maxn],res2[maxn*maxn];
int l1,l2,i,j,p[maxn],cnt;
bool f;
int read(){
	char c;
	int num=0;
	while(1){
		c=getchar();
		if(c==' '){
			return num;
		}else if(c=='\n'){
			f=1;
			return num;
		}else{
			num=num*10+c-'0';
		}
	}
}
int main(){
	while(1){
		a[l1]=read();
		n[l1]=read();
		l1++;
		if(f)break;
	}
	f=0;
	while(1){
		b[l2]=read();
		m[l2]=read();
		l2++;
		if(f)break;
	}
	while(1){
		int maxx=-1,p1=-1;
		for(i=0;i<l1;i++){
			if(p[i]<l2&&maxx<m[p[i]]+n[i]){
				maxx=m[p[i]]+n[i];
				p1=i;
			}
		}
		if(p1==-1)break;
		res2[cnt]=maxx;
		res1[cnt]=a[p1]*b[p[p1]];
		cnt++;
		p[p1]++;
	}
	res2[cnt]=-1;
	for(i=0;i<cnt;i++){
		if(res2[i]==res2[i+1]){
			res1[i+1]+=res1[i];
			continue;
		}
		printf("%d %d ",res1[i],res2[i]);
	}
	return 0;
}
