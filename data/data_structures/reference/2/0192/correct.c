#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long
#define for_(i,m,n)  for(i=m;i<=(n);i++)


int main(void){
	char s[10000];
	char ch1,ch2;
	int num1,num2,num3,ans;
	gets(s);

	int l=strlen(s),j=0;
	for(int i=0;i<l;i++){
		if(s[i]!=' '){
			s[j++]=s[i];
		}
	}
	s[j]='\0';
	j=0;

	ans=atoi(&s[j]);
	while(s[j]>='0'&&s[j]<='9')j++;
	while(s[j]!='\0'){
		ch1=s[j++];
		if(ch1=='*'){
			ans*=atoi(&s[j]);
		}else if(ch1=='/'){
			ans/=atoi(&s[j]);
		}else if(ch1=='+'||ch1=='-'){
			num1=atoi(&s[j]);
			while(s[j]>='0'&&s[j]<='9')j++;
			ch2=s[j++];
			while(ch2=='*'||ch2=='/'){
				num2=atoi(&s[j]);
				while(s[j]>='0'&&s[j]<='9')j++;
				if(ch2=='*'){
					num1*=num2;
				}else{
					num1/=num2;
				}
				ch2=s[j++];
			}
			if(ch1=='+'){
				ans+=num1;
			}else{
				ans-=num1;
			}
			j--;
		}
	}
	printf("%d",ans);

	return 0;
}

