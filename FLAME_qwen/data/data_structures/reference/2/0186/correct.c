#include<stdio.h>
#include<string.h>

int read(char b[],int t){
	int a=0;
	for(;b[t]>='0'&&b[t]<='9';t++){
		a*=10;
		a+=(b[t]-'0');
	}
	return a;
}
int wei(int j){
	int w=1;
	for(;j>=10;w++){
		j/=10;
	}
	return w;
}
int main(){
	char a[10000],b[10000];
	int t,i=0,c=1,s=0,x=0,y=0,z=0;
	gets(a);
	for(t=0;a[t]!='\0';t++){
		if(a[t]!=' '){
			b[i]=a[t];
			i++;
		}
	}
	b[i]='\0';
	t=0;
	x=read(b,t);
	t+=wei(x);
	while(b[t]!='='){
		if(b[t]=='+'){
			s+=(c*x);
			c=1;
			t++;
			x=read(b,t);
			t+=wei(x);
		}
		else if(b[t]=='-'){
			s+=(c*x);
			c=-1;
			t++;
			x=read(b,t);
			t+=wei(x);
		}
		else if(b[t]=='*'){
			t++;
			y=read(b,t);
			t+=wei(y);
			x*=y;
		}
		else if(b[t]=='/'){
			t++;
			y=read(b,t);
			t+=wei(y);
			x/=y;
		}
	}
	s+=(c*x);
	printf("%d\n",s);
	return 0;
}

