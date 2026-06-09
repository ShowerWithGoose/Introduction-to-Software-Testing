#include <stdio.h>
#include <string.h>
int main()
{
	char s[100000]="",ch[100000]="";
	int i=0,j=0,k=0,l=0,m=0,n=0,cj=0,sum=0,num[100000]={0};
	gets(ch);
	for(i=0,j=0;i<strlen(ch);i++){
		if(ch[i]!=' '){
			s[j++]=ch[i];
		}
	}
	for(i=0,j=0;i<strlen(s);i++){
		while(s[i]>='0'&&s[i]<='9'){
			num[j]=num[j]*10+s[i]-'0';
			i++;
		}
		ch[j]=s[i];
		j++;
	}
	for(i=0;i<j;i++){
		if(ch[i]=='*'||ch[i]=='/');{
			if(ch[i]=='*'){
				num[i]=num[i]*num[i+1];
				for(n=i;n<j-1;n++){
					num[n+1]=num[n+2];
					ch[n]=ch[n+1];
				}
				j--;i--;
			}
			if(ch[i]=='/'){
				num[i]=num[i]/num[i+1];
				for(n=i;n<j-1;n++){
					num[n+1]=num[n+2];
					ch[n]=ch[n+1];
				}
				j--;i--;
			}
		}
	} m=num[0];
	for(i=0;i<j;i++){
		if(ch[i]=='+'){
			m+=num[i+1];
		}
		if(ch[i]=='-'){
			m-=num[i+1];
		}
	}
	printf("%d",m);
	return 0;
 } 

