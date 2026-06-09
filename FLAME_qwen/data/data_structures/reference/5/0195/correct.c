#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)

int rd(){
	char ch=getchar();int f=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+ch-'0';ch=getchar();}
	return f*w;
}
struct hs{
	int data1,ji1;
};
int cmp(const void*a,const void*b){
	struct hs a1=*((struct hs*)a);
	struct hs b1=*((struct hs*)b);
	return a1.ji1<b1.ji1;
}
struct hs a1[102],b[102];
int head[204],nxt[204],ji[204],data[204];
int main(){
	int n=1;
	char ch='0';int dd=1;
	while(ch!='\n'){
		int f=0,w=1;ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){f=f*10+ch-'0';ch=getchar();}
		if(dd==1){a1[n].data1=f*w;dd=2;}
		else {a1[n++].ji1=f*w;dd=1;}
	}
	int m=1;ch='0';dd=1;
	while(ch!='\n'){
		int f=0,w=1;ch=getchar();
		while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
		while(ch>='0'&&ch<='9'){f=f*10+ch-'0';ch=getchar();}
		if(dd==1){b[m].data1=f*w;dd=2;}
		else {b[m++].ji1=f*w;dd=1;}
	}
	int tot=0;
	qsort(a1+1,n-1,sizeof(struct hs),cmp);
	qsort(b+1,m-1,sizeof(struct hs),cmp);
	fep(i,1,n-1)
	fep(j,1,m-1){
		int now=a1[i].ji1+b[j].ji1;
		if(!tot){
			head[++tot]=0;nxt[tot]=-1;ji[tot]=now;data[tot]=a1[i].data1*b[j].data1;
		}
		else{
		    bool p=false;
			for(int k=1;k!=-1;k=nxt[k]){
				if(now>ji[k]){
					p=true;nxt[head[k]]=++tot;head[tot]=head[k];
					head[k]=tot;nxt[tot]=k;
					data[tot]=a1[i].data1*b[j].data1;ji[tot]=now;break;
				}
				else if(now==ji[k]){
					p=true;data[k]+=a1[i].data1*b[j].data1;break;
				}
			}
			if(!p){
				int k;
				for(k=1;nxt[k]!=-1;k=nxt[k]);
				head[++tot]=k;ji[tot]=now;data[tot]=a1[i].data1*b[j].data1;nxt[tot]=-1;nxt[head[tot]]=tot;
			}
		}
	}
	for(int k=1;k!=-1;k=nxt[k])if(data[k]!=0)printf("%d %d ",data[k],ji[k]);
}

