#include<stdio.h>
int main(){
	char a[1005]={0};
	int i=0,j=0;
	gets(a);
	for(i=0;a[i]!=0;i++){
		if(a[i]!='-')
			printf("%c",a[i]);
		else{
			if(a[i-1]>64&&a[i-1]<91&&a[i+1]>64&&a[i+1]<91&&a[i-1]<a[i+1])
			{
				for(j=0;j<(a[i+1]-a[i-1]-1);j++){
					printf("%c",a[i-1]+j+1);
				}
			}
			else if(a[i-1]>96&&a[i-1]<123&&a[i+1]>96&&a[i+1]<123&&a[i-1]<a[i+1])
			{
				for(j=0;j<(a[i+1]-a[i-1]-1);j++){
					printf("%c",a[i-1]+j+1);
				}
			}
			else if(a[i-1]>47&&a[i-1]<58&&a[i+1]>47&&a[i+1]<58&&a[i-1]<a[i+1])
			{
				for(j=0;j<(a[i+1]-a[i-1]-1);j++){
					printf("%c",a[i-1]+j+1);
				}
			}
			else
				printf("%c",a[i]);
		}
	}
	return 0;
} 















































