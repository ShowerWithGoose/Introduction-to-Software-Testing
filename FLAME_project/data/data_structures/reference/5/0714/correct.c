#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define N (1005)

typedef long long LL;

typedef struct{
	LL val;
	LL pw;
} cof;

int cmp(const void* ca,const void *cb){
	cof* a=(cof*)ca;
	cof* b=(cof*)cb;
	if(a->pw>b->pw)return -1;
	return 1;
}

cof a[N];LL la;
cof b[N];LL lb;
cof c[N];LL lc;

char rbuffer[1<<12];

LL read_from_rbuffer(LL *ps){
	LL s=0,f=1;
	char t=rbuffer[(*ps)++];
	while('0'>t||t>'9'){
		if(t=='-')f=-1;
		t=rbuffer[(*ps)++];
	}
	while('0'<=t&&t<='9'){
		s=(s<<1)+(s<<3)+(t-'0');
		t=rbuffer[(*ps)++];
	}
	return s*f;
}

void read(cof* cc,LL* len){
	LL ps=0;
	LL l=strlen(rbuffer);
	while(ps<l){
		(*len)++;
		cc[*len].val=read_from_rbuffer(&ps);
		cc[*len].pw=read_from_rbuffer(&ps);
		
	}
}

int main(){
	gets(rbuffer);
	read(a,&la);
	gets(rbuffer);
	read(b,&lb);
	for(LL i=1;i<=la;i++){
		for(LL j=1;j<=lb;j++){
			lc++;
			c[lc].val=a[i].val*b[j].val;
			c[lc].pw=a[i].pw+b[j].pw;
//			printf("v=%d pw=%d\n",c[lc].val,c[lc].pw);
		}
	}
	qsort(c+1,lc,sizeof(c[0]),cmp);
	for(LL l=1,r;l<=lc;l=r+1){
		r=l;LL sm=c[l].val;
		while(c[r+1].pw==c[l].pw){
			sm+=c[++r].val;
		}
		if(sm!=0)
			printf("%lld %lld ",sm,c[l].pw);
	}
	return 0;
}



