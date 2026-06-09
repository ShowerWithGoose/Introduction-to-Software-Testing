#include<stdio.h>
#include<string.h>
#include<math.h>
int f(char);
int main(){
    char a,b,x;
    int op=0,i;
    while(scanf("%c",&x)!=EOF){
    	if(op==1){
    		op=0;
    		if(x>a&&f(x)==f(a)&&f(x)>0){
    			for(i=a+1;i<=x;i++){
    				printf("%c",i);
				}
			}
			else{
			
				printf("-%c",x);
			}
			a=x;
		}
		else{
			if(f(x)>0){
				printf("%c",x);
				a=x;
				
			}
			else{
				if(x=='-'){
					op=1;
				}
				else{
					printf("%c",x);
				}
			}
		}
	}
	return 0;
} 
int f(char x){
	if(x<=57&&x>=48){
		return 1;
	}
	if(x>=97&&x<=122)
	return 2;
	if(x>=65&&x<=90)
	return 3;
	return 0;
}

