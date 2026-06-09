#include<stdio.h>
#include<ctype.h>
int main(){
	char input[5005],output[10005];
	gets(input);
	int i,j=0,k;
	for(i=0;input[i]!='\0';i++){
		if(input[i]!='-')
		output[j++]=input[i];
		else{
			if((isalnum(input[i-1])==isalnum(input[i+1]))&&(isupper(input[i-1])==isupper(input[i+1]))&&(islower(input[i-1])==islower(input[i+1])))
				for(k=input[i-1]+1;k<input[i+1];k++)
				output[j++]=k;
			else
				output[j++]='-';
		}
	}
	puts(output);
	return 0;
}



