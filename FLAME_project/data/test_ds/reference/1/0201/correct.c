#include<string.h>
#include<stdio.h>
int main(){
 	char string[100000];
 	int i=0, k;
	gets(string);
while(i < strlen(string)){
  	if(string[i] == '-'){
		if(string[i-1] >= 'a' && string[i-1] <= 'z' && string[i-1] < string[i+1]){
    		for(k = 0; k < string[i+1] - string[i-1]; k++)
    			printf("%c", string[i-1]+k+1);//在中间打印 
    		i=i + 2;//在原字符数组上加东西 
   		}
   		else if(string[i-1]>='A'&&string[i+1]<='Z'&&string[i+1]>string[i-1]){
   			for(k=0;k<string[i+1]-string[i-1];k++){
   				printf("%c",string[i-1]+k+1);
			}
			i=i+2;
		}
		else if(string[i-1]>='0'&&string[i+1]<='9'&&string[i+1]>string[i-1]){
   			for(k=0;k<string[i+1]-string[i-1];k++){
   				printf("%c",string[i-1]+k+1);	
   			}
   			i=i+2;
   		}
   		else{
   			printf("%c",string[i]);	
   			i++;
		}
	}
	else{
  		printf("%c", string[i]);
    	i++;
    }
}
return 0;
}



