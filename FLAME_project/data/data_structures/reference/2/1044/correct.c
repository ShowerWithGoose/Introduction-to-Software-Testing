#include<stdio.h>
#include<string.h>
char a[10000];
char b[10000];
int num[10000];
char sign[5000];
int count(int a,int b,char f){
	if(f=='*') return a*b;
	else if(f=='+') return a+b;
	else if(f=='-') return a-b;
	else if(f=='/') return a/b;
}
void first(int a[],char b[],int j){
	a[j+1]=count(a[j],a[j+1],b[j]);
	int p=j;
	for(p;p>0;p--){
		a[p]=a[p-1];
		b[p]=b[p-1];
	}
	a[p]=0;
	b[p]='+';
}
int main()
{
	gets(a);
	int len=strlen(a),j=0,number=0,n=0,m=0,end=0;
    for(int i=0;i<len;i++){
    	if(a[i]!=' ') b[j++]=a[i];
    } 
    for(int i=0;i<j;i++){
    	if(b[i]>='0'&&b[i]<='9') number=number*10+b[i]-'0';
    	else{
    		num[n++]=number;
    		sign[m++]=b[i];
    		number=0;
		}
	}
	
    for(int i=0;i<n;i++){
    	if(sign[i]=='*'||sign[i]=='/'){
    		first(num,sign,i);
		}
	}
	end=num[0];
	for(int i=0;i<n-1;i++){
		end=count(end,num[i+1],sign[i]);
	} 
	printf("%d",end);
}

