#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
	int i=0,k=0,n=0,r=0,sum1=0,sum2=0;
	int y=0;
	char s[1000]={};
	char jk[1000]={};
	int d[1000]={};
	char e[1000]={};
	gets(s);
	while(s[i]!='\0'){
		if(s[i]!=' '){
		jk[k]=s[i];
		k++;
		}	
		i++;
	}
	for(i=0;i<k;i++){
	   if(jk[i]>='0'&&jk[i]<='9'){
	   	d[n]=d[n]*10+jk[i]-'0';	
	   }
	   else{
	   	e[r]=jk[i];
	   	n++;
	   	r++;
	   }}
	   sum2=d[0];
	   i=0;
	while(e[i]!='='){
		if(e[i]!='+'&&e[i]!='-'){
			if(e[i]=='*'){
				sum2=sum2*d[i+1];
			}
			else if(e[i]=='/'){
				sum2=sum2/d[i+1];
		}}
		else if(e[i]=='+'||e[i]=='-'){
			if(e[i]=='+'){if(y==1||y==0)
				sum1=sum1+sum2;
				else if(y==2)
				sum1=sum1-sum2;
				
				y=1;
				sum2=d[i+1];
			}
			else if(e[i]=='-'){
				
				if(y==1||y==0)
				sum1=sum1+sum2;
				else if(y==2)
				sum1=sum1-sum2;
				y=2;
				sum2=d[i+1];
			}
		}i++;
	}
	if(y==1||y==0)
	sum1=sum1+sum2;
	if(y==2)
	sum1=sum1-sum2;
	printf("%d",sum1);
	return 0;
}

	 


