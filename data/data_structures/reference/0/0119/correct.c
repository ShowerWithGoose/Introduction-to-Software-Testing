#include<stdio.h>
#include<string.h>
#include<ctype.h>


int main()
{
	char s[1000],a[1000]={'\0'},held;
	
	int i,j=0,k,n;
	
	gets(s);
	for(i=0;i<strlen(s);i++){
		if((s[i]=='-')&&((islower(s[i-1])!=0&&islower(s[i+1])!=0)||
			(isupper(s[i-1])!=0&&isupper(s[i+1])!=0)||
			((isdigit(s[i-1])!=0&&isdigit(s[i+1])!=0)))&&(s[i+1]>s[i-1])){
			//判断间隔符前后是否同类型
			 
		        n=s[i+1]-s[i-1];
			    
				for(k=1;k<n;++k){
					a[j++]=s[i-1]+k;
				}
			
		}
		else a[j++]=s[i];
	}
	puts(a); 

	return 0;
 } 



