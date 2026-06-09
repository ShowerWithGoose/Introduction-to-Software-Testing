#include<stdio.h>
#include<string.h>
#include<math.h>
int u[1000][1000]={0};
int main()
{
	char s[1000],t[1000],v[1000][1000],w[1000];
	int p[1000]={0}; 
	int i,j=0,k=0,l=0,m=0,n=0,res;
	int a,dif,b,c;
	gets(s);
	for(i=0;s[i]!='\0';i++){
		if(s[i]!=' '){
			t[j]=s[i];
			j++;//s[]过渡到t[]，实现去空格 
		}
		if(s[i]=='+'||s[i]=='-')
		n++;//n为加减号个数
	}//question：没有考虑两位数，没有区分字符和数字
	
	for(i=0;i<=n;i++){
		while(t[k]!='+'&&t[k]!='-'&&t[k]!='='){
			if(t[k]=='*'||t[k]=='/'){
				v[i][l]=t[k];
				l++;
				k++;
			}
			else{
				for(a=k;t[a]>='0'&&t[a]<='9';a++);
				dif=a-k;
				for(b=dif-1;b>=0;b--){
					u[i][m]+=(t[k]-'0')*pow(10,b);
					k++;
				}
				m++;
			}
		}
		m=0;
		l=0;
		w[i]=t[k];
		k++;
	}//依加减号分行，加减号和等号存到w【】中,乘除号存到v【】【】中（w【n】=='=') 
	
	for(i=0;i<=n;i++){
		p[i]=u[i][0];
		for(c=0;u[i][c]!=0;c++){
			if(v[i][c]=='*')
			p[i]=p[i]*u[i][c+1];
			if(v[i][c]=='/')
			p[i]=p[i]/u[i][c+1];
		}
	}//将每行的结果计算出后存到p【】中
	
	for(i=0;i<n;i++){
		if(w[i]=='+')
		p[i+1]=p[i]+p[i+1];
		if(w[i]=='-')
		p[i+1]=p[i]-p[i+1];
	}
	res=p[n];
	printf("%d",res);
	return 0;
}

