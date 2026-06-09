#include<stdio.h>
#include<string.h>
int main(){
	char a[300];
	scanf("%s",&a);
	int l=strlen(a),i,j;
	for(i=0;i<l;i++){
		if(a[i]=='-'&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')))
		for(j=a[i-1]+1;j<a[i+1];j++)
		printf("%c",j);
		else
		printf("%c",a[i]);		
	}
}

