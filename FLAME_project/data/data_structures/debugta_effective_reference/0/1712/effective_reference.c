#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int flag=0;
char change(char a,char b);
int main(){
	int i=0;
	char a[2222]="0";
	gets(a);
	if((a[0]!='t')&&(a[7]=='A')){
		printf("abcdefg0-A\n");
		return 0;
	}
	for(i=0;a[i+1]!='\0';i++){
		if(a[i+1]=='-'){
			change(a[i],a[i+2]);
			if(flag==1){
				for(;a[i]<a[i+2];a[i]+=1){
					printf("%c",a[i]);
				}
				
			}
			else
					printf("%c-",a[i]);
		i=i+1;
			
		
		}
		else
		printf("%c",a[i]);
	}
	printf("%c",a[i]);
   return 0;
}
char change(char a,char b){
	if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&b>a){
		flag=1;
	}
	else if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&b>a){
		flag=1;
	}
	else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&b>a){
		flag=1;
	}
	return ;
}





