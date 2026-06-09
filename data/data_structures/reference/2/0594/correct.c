#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 1028
char in0[MAXN],temp[MAXN];
long long ans[MAXN],in[MAXN],tmp;
int i,j,k,l,numc,len,p[MAXN],op;
int main() {
	fgets(in0,MAXN,stdin);
	len=strlen(in0);
	for(p[0]=-1,i=0,j=1,k=1; i<len-1; i++) {
		switch(in0[i]) {
			case '+':
				in[j*2]=-21;
				j++;
				p[k++]=i;
				break;
			case '-':
				in[j*2]=-22;
				j++;
				p[k++]=i;
				break;
			case '*':
				in[j*2]=-11;
				j++;
				p[k++]=i;
				break;
			case '/':
				in[j*2]=-12;
				j++;
				p[k++]=i;
				break;
			case '=':
				in[j*2]=-1;
				j++;
				p[k++]=i;
				break;
		}
	}
	numc=k;
	for(i=0,l=1; i<numc; i++,l++) {
		for(k=0,j=p[i]+1; j<p[i+1]; j++,k++) {
			temp[k]=in0[j];
		}
		in[l*2-1]=atoi(temp);
		memset(temp,0,sizeof(temp));
	}
	numc=(l-2)*2;
	for(i=1,j=1; i<numc; op=0) {
		tmp=in[i];
		for(k=1; op!=1;) {
			switch (in[i+k]) {
				case -21:
				case -22:
				case -1:
					ans[j]=tmp;
					ans[++j]=in[i+k];
					i+=(k+1);
					op=1;
					j++;
					break;
				case -11:
					tmp*=in[i+k+1];
					k+=2;
					break;
				case -12:
					tmp/=in[i+k+1];
					k+=2;
					break;
			}

		}
	}
	j+=2;
	for(i=3,k=2,ans[0]=ans[1]; i<j; i+=2,k+=2) {
		switch (ans[k]) {
			case -21:
				ans[0]+=ans[i];
				break;
			case -22:
				ans[0]-=ans[i];
				break;
		}
	}
	printf("%lld\n",ans[0]);
	return 0;
}


