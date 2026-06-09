#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
	char c[100],r;
	int i,longth=0,n,j;
 	for(i=0;i<100;i++){		
 		longth=i;
  		c[i]=getchar();
  		if(c[i]==EOF){
   			break;
  		}
 	}
	for(i=0;i<longth;i++){
		if(c[i]=='-'){
			if(i==0){
				printf("-");
			}
			else if(c[i-1]>='0'&&c[i+1]<='9'){
				if(c[i-1]+1<c[i+1]){
					n=c[i+1]-c[i-1];
					for(j=1;j<n;j++){
						r=c[i-1]+j;//不动从【i-1】的数值 一直给j做++；对一个char类型的字符+一定是ASCII码加减 
						printf("%c",r);
					}
				}
				else{
					printf("%c%c",c[i-1],c[i]);
				}
			}
			else if(c[i-1]>='A'&&c[i+1]<='Z'){
				if(c[i-1]+1<c[i+1]){ 
					n=c[i+1]-c[i-1];
					for(j=1;j<n;j++){
						r=c[i-1]+j;
						printf("%c",r);
					}
				}
				else{
					printf("%c%c",c[i-1],c[i]);
				}
			}
			else if(c[i-1]>='a'&&c[i+1]<='z'){
				if(c[i-1]+1<c[i+1]){
					n=c[i+1]-c[i-1];
					for(j=1;j<n;j++){
						r=c[i-1]+j;
						printf("%c",r);
					}					
				}
				else{
					printf("%c%c",c[i-1],c[i]);
				}
			}
			else{
				printf("%c",c[i]);
			}
		}
		else{
			printf("%c",c[i]);
		}
	}
	return 0;
}

