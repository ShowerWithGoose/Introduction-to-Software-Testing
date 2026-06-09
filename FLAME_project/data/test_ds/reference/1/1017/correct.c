#include<stdio.h>
#include<string.h>
int main(){
	char ch[1005];
	scanf("%s",ch);
	char* p0;
	char* p;
	p0=ch;
    int k=0,i=0;
	for(p=p0;*p!='\0';p++){
		i++;
		if(*p!='-')
		printf("%c",*p);
	    else if(*(p-1)<'z'+1&&*(p-1)>'a'-1&&*(p+1)>'a'-1&&*(p+1)<'z'+1&&*(p-1)<*(p+1)){
				for(k=1;k<(*(p+1)-*(p-1));k++)
				printf("%c",*(p-1)+k);}
		else if(*(p-1)<'Z'+1&&*(p-1)>'A'-1&&*(p+1)>'A'-1&&*(p+1)<'Z'+1&&*(p-1)<*(p+1)){
				for(k=1;k<(*(p+1)-*(p-1));k++)
				printf("%c",*(p-1)+k);}
		else if(*(p-1)<'9'+1&&*(p-1)>'0'-1&&*(p+1)>'0'-1&&*(p+1)<'9'+1&&*(p-1)<*(p+1)){
				for(k=1;k<(*(p+1)-*(p-1));k++)
				printf("%c",*(p-1)+k);}
		else if(*p=='-'){
		printf("-")	;}
		
		p0=ch+i;
	}


    return 0;
}


















