#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int i=1,j,a[1000],h=1,sum=0;
	char s[1000],x;
	while(x!='='){
		scanf("%d",&a[h]);
		h++;
		scanf("%c",&x);
		if(x==32){
			while(x!='+'&&x!='-'&&x!='*'&&x!='/'&&x!='='){
				scanf("%c",&x);
			}
			s[i]=x;
			i++;
		}
		else {
			s[i]=x;
			i++;
		}
	}
	for(j=1;j<=i-1;j++){
		if(s[j]=='*'){
			a[j+1]=a[j]*a[j+1];
			a[j]=0;
			if(s[j-1]=='-') 
			s[j]='-';
			else 
			s[j]='+';
		}
		else if(s[j]=='/'){
			a[j+1]=a[j]/a[j+1];
			a[j]=0;
			if(s[j-1]=='-') 
			s[j]='-';
			else 
			s[j]='+' ;
		}
	}sum=a[1];
	for(j=1;j<=i;j++){
		if(s[j]=='+'){
			sum=sum+a[j+1];
		}
		else if(s[j]=='-'){
			sum=sum-a[j+1];
		}
	}
	printf("%d",sum);
}

