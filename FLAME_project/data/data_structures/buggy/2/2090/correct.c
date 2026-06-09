#include<stdio.h>
int main(){
	int a[100];
	char s[100];
	int i=0,j,result;
	scanf("%d %c",&a[i],&s[i]);
	while(s[i]!='='){
	    i++; 
		scanf("%d %c",&a[i],&s[i]);
	}
	for(j=0;j<i;j++){
		if(s[j]=='*'||s[j]=='/'){
		    if(s[j]=='*'){
		    	a[j+1]=a[j]*a[j+1];
		    	a[j]=0;
		    	if(s[j-1]=='-') s[j]='-';
		    	else s[j]='+';
			}
			if(s[j]=='/'){
				a[j+1]=a[j]/a[j+1];
				a[j]=0;
		    	if(s[j-1]=='-') s[j]='-';
		    	else s[j]='+';
			}
		}
	}
	result=a[0];
	for(j=0;j<i;j++){
		if(s[j]=='+') result+=a[j+1];
		else result-=a[j+1];
	}
	printf("%d",result);
	return 0;
} 

