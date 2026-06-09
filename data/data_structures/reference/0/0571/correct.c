#include<stdio.h>
#include<string.h>
int main(){
	char a[100000],b[100000];
	int l,i,j=0,m,k;
	gets(a);
	l=strlen(a);
	for(i=0;i<=l-1;i++){
		if(a[i]=='-'){
			if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]){
			m=a[i+1]-a[i-1]-1;
			for(k=1;k<=m;k++){
				b[j]=a[i-1]+k;
				j++;
				}
			}
			else if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]){
			m=a[i+1]-a[i-1]-1;
			for(k=1;k<=m;k++){
				b[j]=a[i-1]+k;
				j++;
				}
			}
			else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]){
			m=a[i+1]-a[i-1]-1;
			for(k=1;k<=m;k++){
				b[j]=a[i-1]+k;
				j++;
				}
			}
			else{
				b[j]=a[i];
				j++;
			}
		}
		else{
		b[j]=a[i];
		j++;
		}
	}
	puts(b);
	return 0;
} 



