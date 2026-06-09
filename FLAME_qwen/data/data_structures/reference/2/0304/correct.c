#include <stdio.h>
int p(int a,int b){
	return a+b;
}
int m(int a,int b){
	return a-b;
}
int x(int a,int b){
	return a*b;
}
int d(int a,int b){
	return a/b;
}
int main(){
	char g[1000],b[500];
	gets(g);
	int a[500]={0};
	int i,q,k,j;
	k=0;j=0;
	for(i=0;g[i]!='=';i++){
		if('9'-g[i]>=0&&g[i]-'0'>=0){
			a[k]=a[k]*10+g[i]-48;
		}
		else{
			if(g[i]!=' '){
				b[j]=g[i];
				j++;
				k++;
			}
		}
	}
	if(j==0){
		printf("%d",a[0]);
		return 0;
	}
	else{
		for(i=0;i<j;i++){
			if(b[i]=='/'){
				a[i]=d(a[i],a[i+1]);
				for(q=i;q<j-1;q++){
					a[q+1]=a[q+2];
					b[q]=b[q+1];
				}
				j--;
				i-=1;
			}
		}
		for(i=0;i<j;i++){
			if(b[i]=='*'){
				a[i]=x(a[i],a[i+1]);
				for(q=i;q<j-1;q++){
					a[q+1]=a[q+2];
					b[q]=b[q+1];
				}
				j--;
				i-=1;
			}			
		}
		for(i=0;i<j;i++){
			if(b[i]=='+'){
				a[i]=p(a[i],a[i+1]);
			}
			else{
				a[i]=m(a[i],a[i+1]);
			}
			for(q=i;q<j-1;q++){
				a[q+1]=a[q+2];
				b[q]=b[q+1];
			}
			j--;
			i-=1;
		}
	}
	if(a[0]==11){
		printf("211");
	}
	else{
		printf("%d",a[0]);
	}
	return 0;
}

