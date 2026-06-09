#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char a[1000];
	char b,j;
	int i,l;
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++){
		if(a[i]=='-'){
			if(i>0&&i<l-1){
				if(islower(a[i-1])&&islower(a[i+1])&&a[i-1]<a[i+1]){
					b=a[i-1]+1;
					for(j=a[i+1]-a[i-1]-1;j>0;j--){
						printf("%c",b);
						b++;
					}
					
				} 
			else if(isupper(a[i-1])&&isupper(a[i+1])&&a[i-1]<a[i+1]){
				b=a[i-1]+1;
					for(j=a[i+1]-a[i-1]-1;j>0;j--){
						printf("%c",b);
						b++;	
				}
			}
			else if(isdigit(a[i-1])&&isdigit(a[i+1])&&a[i-1]<a[i+1]){
			b=a[i-1]+1;
					for(j=a[i+1]-a[i-1]-1;j>0;j--){
						printf("%c",b);
						b++;	
			}
		}
		else printf("%c",a[i]);
		
	}
}else printf("%c",a[i]);
}
return 0;
}



