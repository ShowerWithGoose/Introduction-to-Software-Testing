#include<stdio.h>
#include<string.h>
int main(){
	int i,j,k,mid,sum=0,n=1,p=1;
	char str[300];
	char mark[300];
	int num[300]={0},shu[300]={0};
	gets(str);
	for(i=0,j=0;i<strlen(str);i++){
		if(str[i]!=' '){
			str[j]=str[i];
			j++;
		}
	}
	str[j]='\0';//去掉空格
	for(i=0;i<strlen(str);i++){
		if(str[i]=='+'||str[i]=='-'){
			mark[p]=str[i];
			p++;
		}
		else if(str[i]>=48&&str[i]<=57){
			shu[n]=str[i]-'0';
			for(j=i+1;j<strlen(str);j++){
				if(str[j]=='+'||str[j]=='-'||str[j]=='='){
					n++;
					i=j-1;
					break;
				}
				else if(str[j]>=48&&str[j]<=57&&str[j-1]>=48&&str[j-1]<=57){
					shu[n]=shu[n]*10+(str[j]-'0');
				}
				else if(str[j]=='*'||str[j]=='/'){
					mid=str[j+1]-'0';
					for(k=j+2;str[k]>=48&&str[k]<=57;k++){
						mid=mid*10+(str[k]-'0');
					}
					if(str[j]=='*'){
						shu[n]*=mid;
					}
					else{
						shu[n]/=mid;
					}
					j=k-1;
				}
			}
		}//做好乘除法得出数字 
	}
	sum=shu[1];
	for(i=1;i<p;i++){
		if(mark[i]=='+')
			sum+=shu[i+1];
		else
			sum-=shu[i+1];
	}
	printf("%d",sum);
	return 0;
} 

