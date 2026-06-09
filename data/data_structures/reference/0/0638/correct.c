#include<stdio.h>
#include<string.h>
int main(){
	char s[10005]="",str[50005]="";
	int a,b=0,c=0,cnt,k;
	gets(s);
	for(a=0;a<=strlen(s);a++){
		if(s[a]!='-'){
			str[b]=s[a];
			b++;
		}
		if(s[a]=='-'){
			c=a;
			if(s[c+1]>s[c-1]&&s[c-1]>='0'&&s[c+1]<='9'){
				cnt=s[c+1]-s[c-1];
				k=cnt+b;
				for(b=b;b<k;b++)
					str[b]=str[b-1]+1;
				a=a+1;
			}//0到 9时 
			else if(s[c+1]>s[c-1]&&s[c-1]>='a'&&s[c+1]<='z'){
				cnt=s[c+1]-s[c-1];
				k=cnt+b;
				for(b=b;b<k;b++)
					str[b]=str[b-1]+1;
				a=a+1;
			}//a到 z时 
			else if(s[c+1]>s[c-1]&&s[c-1]>='A'&&s[c+1]<='Z'){
				cnt=s[c+1]-s[c-1];
				k=cnt+b;
				for(b=b;b<k;b++)
					str[b]=str[b-1]+1;
				a=a+1;
			}//A到 Z时 
			else{
				str[b]=s[a];
				b++;
			}
		}
	}
	printf("%s",str);
	return 0;
}



