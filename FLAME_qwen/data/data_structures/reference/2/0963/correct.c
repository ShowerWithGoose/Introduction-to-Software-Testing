#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char a[1000],d[1000];
	int b[1000]={0};
	int i,j=0,k=0,c=0,m=0,n=0;
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]!=' ') a[j++]=a[i];
	}
	a[j]='\0'; 
	for(i=0;a[i]!='\0';i++){
		c=0;
		if(a[i]<='9'&&a[i]>='0'){
			for(j=i;(a[j]<='9'&&a[j]>='0');j++){
				b[k]=b[k]*10+a[j]-'0';
			}
			k++,i=j;
		}
		if(a[i]=='*'||a[i]=='/'){
			c=0;
			for(j=i+1;(a[j]<='9'&&a[j]>='0');j++){
				c=c*10+a[j]-'0';
			}
			if(a[i]=='*') b[k-1]*=c;
			else b[k-1]/=c;
			i=j-1;
		}
		else if(a[i]=='-'||a[i]=='+'){
		d[m]=a[i];
		m++;}
	}
	k=1;
	n=b[0];
	for(i=0;i<m;i++){
		if(d[i]=='+'){
			n+=b[k];
			k++;
		}else if(d[i]=='-'){
			n-=b[k];
			k++;
		}
	}
	printf("%d",n);
	return 0;
}




