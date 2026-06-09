#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int my_isdigital(char a)
{
	return a>='0'&&a<='9';
}

int isvalid_(int ptr_c,char c[])
{
	return (my_isdigital(c[ptr_c-1])&&my_isdigital(c[ptr_c+1]))||(islower(c[ptr_c-1])&&islower(c[ptr_c+1]))||(isupper(c[ptr_c-1])&&isupper(c[ptr_c+1]));
}

int main()
{
	char c[10000]={0},ans[10000]={0},k;
	int ptr_c,ptr_ans;
	gets(c);
	for(ptr_c=0,ptr_ans=0;c[ptr_c]!='\0';ptr_c++){
		if(ptr_c>0&&c[ptr_c]=='-'&&c[ptr_c-1]<c[ptr_c+1]){
			if(isvalid_(ptr_c,c)){
				for(k=c[ptr_c-1]+1;k<c[ptr_c+1];k++){
					ans[ptr_ans++]=k;
				}
			}
			else ans[ptr_ans++]=c[ptr_c];
		}
		else ans[ptr_ans++]=c[ptr_c];
	}
	ans[ptr_ans]='\0';
	puts(ans);
	return 0;
}



