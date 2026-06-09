#include<stdio.h>
#include<string.h>
int suan(int m,char s,int n){
	int c;
	switch(s){
		case '+':
			c = m + n;
			break;
	    case '-':
			c = m - n;
			break;
		case '*':
			c = m * n;
			break;
		case '/':
			c = m / n;
			break;
	}
	return c;
}
int main(){
	char a[100],b[100],c[100],c2[100];
	int d[100],e[100];
	int i,j,k,l,o,p=0;
	int sum=0;
	gets(a);
	for(i=0,j=0;a[i]!='\0';i++){
		if(a[i]!=' '){
			b[j++]=a[i];
		}
	}
	b[j]='\0';
	
	//puts(b);
	for(j=0,k=0;b[j]!='\0';j++){
		if(b[j]=='+'||b[j]=='-'||b[j]=='*'||b[j]=='/'||b[j]=='='){
			c[k++]=b[j];
		}
	}
	//puts(c);
	for(l=0,p=0;l<strlen(b);l++){
		if(b[l]>='0'&&b[l]<='9'){
		for(o=1;o<9;o++){
			if(b[l+o]>='0'&&b[l+o]<='9')
			continue;
			int w,n=1,m=0;
			for(w=o;w>0;w--){
				m=m+(b[l+w-1]-'0')*n;
				n=n*10;
			}
			d[p++]=m;
			l=l+o-1;
			break;
			if(b[i+o]<'0'||b[i+o]>'9')
			break;
		}
	}
}
	for(i=0,j=0;i<strlen(c)+1;i++){
		if(c[i]=='+'||c[i]=='-'||c[i]=='='){
			c2[j]=c[i];
			e[j]=d[i];
			j++;
		}
		if(c[i]=='*'){
			d[i+1]=d[i+1]*d[i];
		}
		if(c[i]=='/'){
			d[i+1]=d[i]/d[i+1];
		}
	}
	sum=e[0];
	for(i=0;i<strlen(c2);i++){
		if(c2[i]=='+'){
			sum=sum+e[i+1];
		}
		if(c2[i]=='-'){
			sum=sum-e[i+1];
		}
	}
	printf("%d",sum);
	return 0;
} 



