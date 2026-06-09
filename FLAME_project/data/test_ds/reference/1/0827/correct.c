#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
int main(){
	char a[10000]={};
	int m,i,j; 
	gets(a);
	m=strlen(a);
	for(i=0;i<m;i++){
		if(a[i]!='-')
			printf("%c",a[i]);
		else{
	    if(((a[i-1]>='a'&&a[i-1]<='z')&&(a[i+1]>='a'&&a[i+1]<='z'))||((a[i-1]>='A'&&a[i-1]<='Z')&&(a[i+1]>='A'&&a[i+1]<='Z'))||((a[i-1]>='0'&&a[i-1]<='9')&&(a[i+1]>='0'&&a[i+1]<='9'))){
	    for(j=1;j<=a[i+1]-a[i-1]-1;j++){
	    	printf("%c",a[i-1]+j);
		}	
		}
		else
		printf("%c",a[i]);    
	}}
}




