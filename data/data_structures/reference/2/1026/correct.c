#include <stdio.h>
#include <math.h>
#include <string.h>
int com(char c,int a,int b);
int main()
{
	char s[100]={'\0'};
	char ss[100];
	int num[20];
	int nn[20];
	int calf=0;
	int temp=0;
	int ccf=0;
	int f=0;
	char cal[20];
	char cc[20];
	int i=0,j=0,k=0;
	int cou=0;
	gets(ss);
	while(ss[i]!='='&&ss[i]!='\0'){
		if(ss[i]!=' '){
			s[j]=ss[i];
			i++;
			j++;
		}
		else
			i++;
	}
	i=j=0;
	while(s[i]!='\0'){
		if(s[i]<='9'&&s[i]>='0'){
			if(s[i+1]<='9'&&s[i+1]>='0'){
				if(s[i+2]<='9'&&s[i+2]>='0'){
					if(s[i+3]<='9'&&s[i+3]>='0'){
						if(s[i+4]<='9'&&s[i+4]>='0'){
							num[j]=(int)((s[i]-'0')*10000)+(int)((s[i+1]-'0')*1000)+(int)((s[i+2]-'0')*100)+(int)((s[i+3]-'0')*10)+(int)(s[i+4]-'0');
							i=i+5;
							j++;
						}
						else{
							num[j]=(int)((s[i]-'0')*1000)+(int)((s[i+1]-'0')*100)+(int)((s[i+2]-'0')*10)+(int)(s[i+3]-'0');
							i=i+4;
							j++;
						}
					}
					else{
						num[j]=(int)((s[i]-'0')*100)+(int)((s[i+1]-'0')*10)+(int)(s[i+2]-'0');
						i=i+3;
						j++;
					}
				}
				else{
					num[j]=(int)((s[i]-'0')*10)+(int)(s[i+1]-'0');
					i=i+2;
					j++;
				}
			}
			else{
				num[j]=(int)(s[i]-'0');
				j++;
				i=i+1;
			}
		}
		else if(s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'){
			cal[k]=s[i];
			calf++;
			k++;
			i++;
		}
	}
	i=j=k=0;
	if(calf==0)
	nn[0]=num[0];
	while(calf>0){		
		if(cal[i]=='+'||cal[i]=='-'){
			cc[j]=cal[i];
			if(f==0){
				nn[k]=num[i];
				k++;
			}
			f=0;
			ccf++;
			i++;
			j++;
			calf--;
		}
		else if(cal[i]=='*'||cal[i]=='/'){
			temp=num[i];
			while(cal[i]=='*'||cal[i]=='/'){
				if(cal[i]=='*'){
					temp=temp*num[i+1];
					calf--;
					f=1;
					i++;
				}
				else{
					temp=temp/num[i+1];
					calf--;
					f=1;
					i++;
				}
			}
		}
		if(f==1){
				nn[k]=temp;
				k++;
				temp=0;
		}
	}
	if((cal[i]!='+'||cal[i]!='-'||cal[i]!='*'||cal[i]!='/')&&(cal[i-1]=='+'||cal[i-1]=='-'))
		nn[k]=num[i];
	i=j=k=0;
	cou=nn[0];
	while(ccf>0){
		cou=com(cc[i],cou,nn[i+1]);
		ccf--;
		i++;
	}
	printf("%d",cou);
	return 0;
}
int com(char c,int a,int b){
	int sha; 
	if(c=='+')
	sha=a+b;
	else if(c=='-')
	sha=a-b;
	return sha;}

