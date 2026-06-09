#include<stdio.h>
#include<string.h> 
int main(){
	char a[100001],b[100001];
	gets(a);
	int i,j,k;
	for(i=j=0;a[i];i++,j++){
		b[j]=a[i];
		if(a[i]=='-'){
			if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i+1]>a[i-1]){
				for(k=1;k<=a[i+1]-a[i-1];k++){
					b[j]=a[i-1]+k;
					j++;
				}
				j-=2;
			}
			if(a[i-1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1]){
				for(k=1;k<=a[i+1]-a[i-1];k++){
					b[j]=a[i-1]+k;
					j++;
				}
				j-=2;
			}
			if(a[i-1]>='0'&&a[i+1]<='9'&&a[i+1]>a[i-1]){
				for(k=1;k<=a[i+1]-a[i-1];k++){
					b[j]=a[i-1]+k;
					j++;
				}
				j-=2;
			}
		}
		
	}
	puts(b);
	return 0;
}



