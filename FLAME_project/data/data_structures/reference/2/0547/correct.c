#include<stdio.h>
#include<string.h>
char a[20000];
int s=0,i=0,k=0,b[20000]; 

int cunshuzi(){
	int n;
	for(n=0;a[k]>='0'&&a[k]<='9';k++) n=n*10+a[k]-'0';//数字中的最高位在数组中i最小 
	b[i++]=n; 
}

int main() {
	gets(a);
	int len=strlen(a),m,n,u,v;
	for(m=0,n=0; m < len; m++) //去除空格 
		if(a[m]!=' ') a[n++]=a[m]; //此时a的长度为n 
	while(k<n){ //字符串转换为数组 
		if(a[k]>='0'&&a[k]<='9') cunshuzi();
		else if(a[k]=='+'){
			b[i++]=-1;
			k++;
		}
		else if(a[k]=='-'){
			b[i++]=-2;
			k++;
		}
		else if(a[k]=='*'){
			b[i++]=-3;
			k++;
		}
		else if(a[k]=='/'){
			b[i++]=-4;
			k++;
		}
		else if(a[k]=='='){
			b[i++]=-10;
			k++;
			break;
		}
	}
	int w;
	for(w=0;w<i;w++){ //先算乘除 
		if(b[w]==-3){
			w++;
			b[w]=b[w]*b[w-2];
			b[w-1]=-5;
			b[w-2]=-5;
		}
		if(b[w]==-4){
			w++;
			b[w]=b[w-2]/b[w];
			b[w-1]=-5;
			b[w-2]=-5;
		}
	}
	for(u=0,v=0; u < i; u++)
		if(b[u]!=-5) b[v++]=b[u]; //此时b的长度为v
	int w2=0;
	if(b[0]==-1){
		s=s+b[1];
		w2+=2;
	}
	else if(b[0]==-2){
		s=s-b[1];
		w2+=2;
	}
	else{
		s=b[0];
		w2++;
	}
	while(w2<v){
		if(b[w2]==-1) s+=b[++w2];
		else if(b[w2]==-2) s-=b[++w2];
		w2++;
		if(b[w2]==-10)break;
	}	
	printf("%d",s);
	return 0;
}

