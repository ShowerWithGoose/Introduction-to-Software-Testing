#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char sh[1000],i = 0;
	scanf("%s",sh);
	for(i = 0;sh[i] != '\0';i++){
		if(sh[i] != '-') printf("%c",sh[i]);
		else{
			if(sh[i-1] >= 'A'&&sh[i-1] <= 'Z'&&sh[i+1] >= 'A'&&sh[i+1] <= 'Z') func(sh[i-1],sh[i+1]);
			else if(sh[i-1] >= 'a'&&sh[i-1] <= 'z'&&sh[i+1] >= 'a'&&sh[i+1] <= 'z') func(sh[i-1],sh[i+1]);
			else if(sh[i-1] >= '0'&&sh[i-1] <= '9'&&sh[i+1] >= '0'&&sh[i+1] <= '9') func(sh[i-1],sh[i+1]);
			else printf("-"); 
		}
	}
	return 0;
} 
void func(char a,char b){
	char c;
	c = a + 1;
	while(c < b){
		printf("%c",c);
		c = c + 1;
	}
}

