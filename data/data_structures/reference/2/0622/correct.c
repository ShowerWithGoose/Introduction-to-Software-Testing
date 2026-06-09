#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[1000],sym[100];
	int num[100],i,t,sum,x=0,y=0;
	gets(s);
	for(i=0;s[i]!='=';i++){
		if(s[i]>='0'&&s[i]<='9'){
			x++;
			sum=0;
			for(;s[i]>='0'&&s[i]<='9';i++){
				sum=sum*10+(int)s[i]-48;
			} 
			i--;
			num[x]=sum;
		}
		else if(s[i]==' '){
			;
		}
		else {
			y++;
			sym[y]=s[i];
		}
	}
	for(i=1;i<=y;i++){
		if(sym[i]=='*'){
			while(sym[i]=='*'){
			num[i]=num[i]*num[i+1];
			for(t=i;t<=y;t++){
				sym[t]=sym[t+1];
				num[t+1]=num[t+2];
			}
			y--;
			i--;
			}
		}
		else if(sym[i]=='/'){
			while(sym[i]=='/'){
			num[i]=num[i]/num[i+1];
			for(t=i;t<=y;t++){
				sym[t]=sym[t+1];
				num[t+1]=num[t+2];
			}
			y--;
			i--;
			}
		}
	}
	for(;y!=0;y--){
		if(sym[1]=='+'){
			num[1]=num[1]+num[2];
			for(i=1;i<y;i++){
				sym[i]=sym[i+1];
				num[i+1]=num[i+2];
			}
		}
		else if(sym[1]=='-'){
			num[1]=num[1]-num[2];
			for(i=1;i<y;i++){
				sym[i]=sym[i+1];
				num[i+1]=num[i+2];
			}
		}
	}
	printf("%d",num[1]);
	return 0;
}

