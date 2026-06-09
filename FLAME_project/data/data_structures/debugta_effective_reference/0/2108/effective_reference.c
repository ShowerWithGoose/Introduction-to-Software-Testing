#include<stdio.h>

#include<string.h>

#include<stdlib.h>

int main(){
	
	char c1,c2,c3;
	int i,s;
	c1=getchar();
	putchar(c1);
	while((c2=getchar())!='\0'&&c2!=EOF){
		if(c2!='-'){
			putchar(c2);
			c1=c2;
		}
		else{
			c3=getchar();
			if((c1>='0'&&c1<='9'&&c3>='0'&&c3<='9'&&c3>c1)
			||(c1>='a'&&c1<='z'&&c3>='a'&&c3<='z'&&c3>c1)
			||(c1>='A'&&c1<='Z'&&c3>='A'&&c3<='Z'&&c3>c1)){
				i=c1+1;
				s=c3;
				while(i<=s){
					putchar(i);
					i++;
				}
			}
			else{
				putchar('-');
				putchar(c3);
			}
			c1=c3;
		}
	}	
	
	return 0;
}

