#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char s;
    int i=1,a,b,op=0,opf=0;
    while(scanf("%c",&s)!=EOF){
    	if(s=='0'&&i==1){
    		
		}
    	if(s=='0'){
    		i++;
		}
		if(s=='.'){
			a=i;
			opf=1;
			i++;
		}
		if(s<=57&&s>=49){
			b=i+1;
			i++;
			if(opf==1){
				b--;
			}
			printf("%c",s);
			break;
		}
	}
	while(scanf("%c",&s)!=EOF){
		if(s==10){
			continue;
		} 
		if(op==0){
			printf(".");
			op=1;
			
		}
		if(s=='.'){
			a=i;
			opf=1;
			i++;
		}
		if(s<=57&&s>=48){
			printf("%c",s);
			i++;
		}
	}
	if(opf==0){
		a=i;
	}
	printf("e%d",a-b);
	return 0;
}  

