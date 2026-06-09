#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

	char S[6666],s[6666];
int main(){
	gets(S);
	for(int i=0,j=0;S[i]!='\0';i++){
		if(S[i]!=' '){
			s[j]=S[i];
			j++;
		}
	}
	int a[6666]={0};
	char b[6666]={'\0'};
	int count=0,index=0;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='0'&&s[i]<='9'){
			count++;
		}
		else if(s[i]<'0'||s[i]>'9'){
			b[index]=s[i];
			int d=1;
			for(int k=1;k<=count;k++){
				a[index]+=(s[i-k]-'0')*d;
				d*=10;
			}
			index++;
			count=0;
		}
	}
		int answer=a[0];
		int x=0,y;
	for(int i=0;b[i]!='=';i++){
		if(b[i]=='*'){
			a[i+1]=a[i+1]*a[i];
		}
		else if(b[i]=='/'){
			a[i+1]=a[i]/a[i+1];
	}
		if(b[i]=='+'||b[i]=='-'){
			x=1;
		}
		y=i+1;
	}
	if(x==0){
		answer=a[y];
	}
	int j;
	for(int i=0;b[i]!='=';i++){
		if(b[i]=='+'||b[i]=='-'){
			answer=a[i];
			break;
		}
	}
	for(int i=0;b[i]!='=';i++){
		if(b[i]=='+'){
			for(j=1;;j++){ 
			if(b[i+j]=='+'||b[i+j]=='-'||b[i+j]=='='){
				break;
			}
			}
			answer+=a[i+j]; 
		}
		else if(b[i]=='-'){
			for(j=1;;j++){ 
			if(b[i+j]=='+'||b[i+j]=='-'||b[i+j]=='='){
				break;
			}
		}
			answer-=a[i+j]; 
	}

	}	
		printf("%d",answer);
}


