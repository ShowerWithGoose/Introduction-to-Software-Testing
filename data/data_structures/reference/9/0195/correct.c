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
int x[102],y[102],xx[102],yy[102],n,ans[102];
bool p[102];
int main(){
	n=rd();
	fep(i,1,n){x[i]=rd();y[i]=rd();xx[i]=rd();yy[i]=rd();}
	fep(i,1,n)if(!p[i]){
		p[i]=true;
		int bx=xx[i],by=yy[i];
		bool find=true;int now=i;
		while(find){
			find=false;
			fep(j,1,n)if(now!=j&&bx==x[j]&&by==y[j]){
				if(p[j]){
					ans[i]+=ans[j];break;
				}
				else{
					ans[i]++;p[j]=true;find=true;
				    bx=xx[j];by=yy[j];now=j;break;
				}
			}
		}
		ans[i]++;
	}
	int an=1;
	fep(i,1,n)if(ans[i]>ans[an])an=i;
	printf("%d %d %d",ans[an],x[an],y[an]);
}

