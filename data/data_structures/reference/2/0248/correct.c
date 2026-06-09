#include<stdio.h>
#include<string.h>
int number(){
	int p;
	scanf("%d",&p);
	return p;
} 
char abcd(){
	char q;
	do{
	scanf("%c",&q);}
	while(q==' ');
	return q;
}
int main(){
	int a,b,c;
	char m,n;
	a=number();
	m=abcd();
	if(m=='=')
	printf("%d",a);
	else{
		b=number();
		n=abcd();
		if(n=='='){
			if(m=='+')
			printf("%d",a+b);
			if(m=='-')
			printf("%d",a-b);
			if(m=='*')
			printf("%d",a*b);
			if(m=='/'&&b!=0)
			printf("%d",a/b);
		}
		else{
			while(n!='='){
			c=number();
			if((n=='*'||n=='/')&&(m=='+'||m=='-')){
			if(n=='+')
			b=b+c;
			if(n=='-')
			b=b-c;
			if(n=='*')
			b=b*c;
			if(n=='/'&&c!=0)
			b=b/c;
			}
			else{
			if(m=='+')
			a=a+b;
			if(m=='-')
			a=a-b;
			if(m=='*')
			a=a*b;
			if(m=='/'&&b!=0){
			a=a/b;}
			b=c;
			m=n;
			}
			n=abcd();
		    }
		    if(m=='+')
			printf("%d",a+b);
			if(m=='-')
			printf("%d",a-b);
			if(m=='*')
			printf("%d",a*b);
			if(m=='/'&&b!=0)
			printf("%d",a/b);
		}
	}
    return 0;
}

