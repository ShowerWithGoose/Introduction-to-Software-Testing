#include<stdio.h>
char a[1024];
int i=0,f=1,sum=0;
int read(){
	int b;
	while(1){
			if(a[i]==' '){
				i++;
				continue;
			}else if(a[i]<='9'&&a[i]>='0'){
				b=a[i]-'0';
				i++;
				for(;a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'&&a[i]!='=';i++){
					if(a[i]==' '){
						continue;
	       			}else if(a[i]<='9'&&a[i]>='0'){
	       				b*=10;
	    	   			b+=a[i]-'0';
					}
				}
			
				break;
			}
		}
		return b;
}
int compute(int b){
    	if(a[i]=='*'){
			i++;
			b*=read();
		}else if(a[i]=='/'){
			i++;
			b/=read();
		}else if(a[i]=='+'){
			i++;
			if(f==1){
				sum+=b;
			}else{
				sum-=b;
			}
			f=1;
			b=read();
		}else if(a[i]=='-'){
			i++;
			if(f==1){
				sum+=b;
			}else{
				sum-=b;
			}
			f=0;
			b=read();
		}
		return b;
}
int main(){
	gets(a);
	int b;
	b=read();
	while(1){
		if(a[i]=='='){
			if(f==1){
				sum+=b;
			}else{
				sum-=b;
			}
			break;
		}else b=compute(b);
	}
	printf("%d",sum);
	return 0;
}

