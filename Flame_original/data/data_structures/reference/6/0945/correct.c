#include<stdio.h>
char in[2000],st[1000],out[1000]; 
int main(){
	gets(in);
	
	int i,j=0,k,l,top=0;
	for(i=0;i<strlen(in);i++){
		if(in[i]=='1'){
			i+=2;
			while(in[i]!=' ')
			st[top++]=in[i++];
			st[top++]=' ';
		}
		else if(in[i]=='-'){
			puts(out);
			return 0;
		}
		else if(in[i]=='0'){
			i++;
			if(top<=0){
				out[j++]='e';
				out[j++]='r';
				out[j++]='r';
				out[j++]='o';
				out[j++]='r';
				out[j++]=' ';
			}
			else{
				for(top-=2;top>=0&&st[top]!=' ';top--);
				top++;
				l=top;
				while(st[l]!=' '){
					out[j++]=st[l];
					st[l]='\0';
					l++;
				}
				out[j++]=' ';
			}
		}
	}
	
	return 0;
} 

