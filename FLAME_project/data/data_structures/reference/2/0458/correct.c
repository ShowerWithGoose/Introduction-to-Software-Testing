#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define eps 1e-9
int cal(int a,char b,int c);
char s[1000000];
char u[1000000];
char t[1000000];
int dig[1000000];
int main()
{
	int res = 0;
	gets(s);
	int l = 0;
	for(int k = 0;k<strlen(s);k++){
		if(s[k] == ' '||s[k] == '='){
			continue;
		}
		else{
			u[l] = s[k];
			l++;
		}
	}
	int j = 0,k = 0;int mid = 0;
//	puts(u);
	for(int i = 0;i<strlen(u);i++){
		if(isdigit(u[i])){
			dig[j] = u[i] - '0';
			if(isdigit(u[i+1])){
				dig[j] = (u[i] - '0')*10+u[i+1] - '0';
				mid++;
				if(isdigit(u[i+2])){
					dig[j] = (u[i] - '0')*100+(u[i+1] - '0')*10+u[i+2] - '0';
					mid++;
					if(isdigit(u[i+3])){
						dig[j] = (u[i] - '0')*1000+(u[i+1] - '0')*100+(u[i+2] - '0')*10+u[i+3]-'0';
						mid++;
						if(isdigit(u[i+4])){
						dig[j] = (u[i] - '0')*10000+(u[i+1] - '0')*1000+(u[i+2] - '0')*100+(u[i+3]-'0')*10+u[i+4]-'0';
						mid++;
							if(isdigit(u[i+5])){
							dig[j] = (u[i] - '0')*100000+(u[i+1] - '0')*10000+(u[i+2] - '0')*1000+(u[i+3]-'0')*100+(u[i+4]-'0')*10+u[i+5]-'0';
							mid++;
							}
						}
					}
				}
			}
			j++;
		}
		else{
			t[k++] = u[i];
		}
		i+=mid;
		mid = 0;
	}
		dig[j++] = -1;		
//		for(int i = 0;i<=10;i++){
//		printf("%d ",dig[i]);
//
//	}
//	puts(t);
	for(int i = 0;t[i] != '\0';i++){
		if(t[i] == '*'||t[i] == '/'){
			dig[i] = cal(dig[i],t[i],dig[i+1]);
			for(int m = i;t[m] != '\0';m++){
				t[m] = t[m+1];
			}
			for(int n = i+1;dig[n]>=0;n++){
				dig[n] = dig[n+1];
			}
			i--;
		}
//				for(int i = 0;i<=10;i++){
//		printf("%d ",dig[i]);
//		printf("\n");
//	}
//	puts(t);
	}
	for(int i = 0;t[i] != '\0';i++){
			res += cal(dig[i],t[i],dig[i+1]);
					//printf("%d ",res);
			dig[i] = cal(dig[i],t[i],dig[i+1]);
			for(int m = i;t[m] != '\0';m++){
				t[m] = t[m+1];
			}
			for(int n = i+1;dig[n]>=0;n++){
				dig[n] = dig[n+1];
			}
			i--;
//		for(int i = 0;i<=10;i++){
//		printf("%d ",dig[i]);
//	}
//	printf("\n");
		}
		printf("%d",dig[0]);
	return 0;
}
int cal(int a,char b,int c){
	if(b == '+'){
		return a+c;
	}
	if(b == '-'){
		return a-c;
	}
	if(b == '*'){
		return a*c;
	}
	if(b == '/'){
		return a/c;
	}
}

