#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define orz 0
#define db double
#define eps 1e-6
#define inf 1e16
#define maxn 200005
#define pi 3.1415926535897932384626433832795
//#define int long long
#define abs llabs
//#define int unsigned int
const int mod =1e9+7;
#define gc() getchar()
#define pc(a) putchar(a)
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define swap(a,b) a^=b^=a^=b
int read(){
	int x=0,f=1;
	char c=gc();
	while((c>'9'||c<'0'))
	{
		if(c=='-') f=-f;
		c=gc();
	}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=gc();
	return x*f;
}

int nnu[25];
void write(int x){
	if(!x)
	{
		pc('0');
		return;
	}
	int tp=0;
	if(x<0) pc('-'),x=-x;
	while(x) nnu[++tp]=x%10,x/=10;
	while(tp) pc(nnu[tp--]+'0');
	return;
}
int ABS(int a){return a<0?-a:a;} 
int gcd(int a,int b){
	a=abs(a),b=abs(b);
	if(!a) return b;
	if(!b) return a;
	return gcd(b,a%b);
}
int mul(int a,int b){
	a %= mod;
    int ret = 0;
    b=(b%mod+mod)%mod;
    while (b) {
        if (b & 1)
            ret =( ret + a )% mod;
        a = (a+a) % mod;
        b = b >> 1;
    }
    return ret;
}
db dis(db a,db b,db c,db d){
	return sqrt((a-c)*(a-c)+(b-d)*(b-d));
} 
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int lowbit(int x) {return x&(-x);}
long long qpow(long long a, unsigned long long b, long long p){
	long long ans = 1;
	a = a % p;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans;
}

unsigned popcount (unsigned u){
    u = (u & 0x55555555) + ((u >> 1) & 0x55555555);
    u = (u & 0x33333333) + ((u >> 2) & 0x33333333);
    u = (u & 0x0F0F0F0F) + ((u >> 4) & 0x0F0F0F0F);
    u = (u & 0x00FF00FF) + ((u >> 8) & 0x00FF00FF);
    u = (u & 0x0000FFFF) + ((u >> 16) & 0x0000FFFF);
    return u;
}

int inv(int x){return qpow(x,mod-2,mod)%mod;}
struct ee{
	int to,next;
}edge[10005];
int head[10005];
struct pq{
	int x_1,y_1,x_2,y_2;
}st[1005]; 
int n,m,op,len,T,cnt=0;

void add(int x,int y){
	edge[cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt++;
}
int ans=0;
int vis[1005];
int dfs(int x){
//	write(x);
//	pc('\n');
	vis[x]=1;
	int now=1;
	for(int i=head[x];~i;i=edge[i].next){
		int to=edge[i].to;
		now=max(now,dfs(to)+1);
	}
	return now;
}
int pos;
signed main(){
//	FILE *in,*out;
//	in = fopen("books.txt","r");
//	out = fopen("ordered.txt","w");
	n=read();
	for(int i=1;i<=n;i++){
		st[i].x_1=read();
		st[i].y_1=read();
		st[i].x_2=read();
		st[i].y_2=read();
		head[i]=-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if((st[i].x_2==st[j].x_1)&&(st[i].y_2==st[j].y_1)) add(i,j);
		}
	}
//	write(cnt);pc('p');
	for(int i=1;i<=n;i++){
		if(!vis[i]) {
			int qq=dfs(i);
//			write(qq);
			if(ans<qq) ans=qq,pos=i;
		}
	}
	write(ans),pc(' '),write(st[pos].x_1),pc(' '),write(st[pos].y_1);
	return 0;
}

