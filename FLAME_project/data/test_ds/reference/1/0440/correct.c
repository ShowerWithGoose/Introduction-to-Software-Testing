#include<stdio.h>
#include<string.h>

int i,j,k,n;
char a[105],b[105],c[105];

int main(){
	scanf("%s",a);
	for(i=n=0;n<strlen(a);n++){
		if(a[i]=='-'){
			
			if(isalpha(a[i-1])){
				if(!(isupper(a[i-1])^isupper(a[i+1]))){
					for(k=1;k<a[i+1]-a[i-1];k++){
						c[j++]=a[i-1]+k;
					
					}
						i++;
				}else{
			c[j++]=a[i++];
		}
			} else{
				if(isdigit(a[i-1])&&isdigit(a[i+1])){
					for(k=1;k<a[i+1]-a[i-1];k++){
						c[j++]=a[i-1]+k;
					
					}
						i++;
				}else{
			c[j++]=a[i++];
		}
			}
			
			
		}else{
			c[j++]=a[i++];
		}
	}
	c[j]='\0';
	puts(c);
} 



