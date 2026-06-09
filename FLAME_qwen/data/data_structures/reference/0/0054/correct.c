#include<stdio.h>
#include<string.h>
int main(){
	char a[1000];
	int i,j,k;
	scanf("%s",&a);
		if(a[0]=='-')
		printf("-");
			for(i=0;i<strlen(a);i++){
				if(a[i]=='-'&&a[i-1]>='a'&&a[i+1]<='z'){
				 	if(a[i+1]>a[i-1]-1){
				 		 k=a[i+1]-a[i-1];	
							for(j=1;j<k;j++)
								printf("%c",a[i-1]+j);
					                   }
					               						}
				else if(a[i]=='-'&&a[i-1]>='A'&&a[i+1]<='Z'){
						if(a[i+1]>a[i-1]-1){
				 		 	k=a[i+1]-a[i-1];	
								for(j=1;j<k;j++)
									printf("%c",a[i-1]+j);
					                   }
					               						}
				else if(a[i]=='-'&&a[i-1]>='0'&&a[i+1]<='9'){
				 	    if(a[i+1]>a[i-1]-1){
				 		 	k=a[i+1]-a[i-1];	
								for(j=1;j<k;j++)
									printf("%c",a[i-1]+j);
					                   }
					               						}
				else if(a[i]=='-')
					printf("-");
					else 
					printf("%c",a[i]);
				}
				return 0;
			}

