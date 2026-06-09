#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 10005

char str[MAX],ope[MAX];
int num[MAX],i,j,k,t,res; 
void print(int a){
	printf("%d\n",a);
}
int main(){
	gets(str);	
	for(i=0;str[i]!='\0';i++){
		if(str[i]>='0'&&str[i]<='9'){
			for(t=i;str[t]>='0'&&str[t]<='9';t++){
				num[j]=num[j]*10+str[t]-'0';
			}
			j++;
			i=t-1;
		}
		else if(str[i]!=' '){
			ope[k]=str[i];
			k++;
		}
	}
	
	for(t=0;t<k;t++){
		if(ope[t]=='/'){
			num[t+1]=num[t]/num[t+1];
			for(i=t;(ope[i]=='*'||ope[i]=='/')&&i>=0;i--){
				num[i]=num[i+1];
			}
		}
		if(ope[t]=='*'){
			num[t+1]=num[t]*num[t+1];
//			print(num[t]);
			for(i=t;(ope[i]=='*'||ope[i]=='/')&&i>=0;i--){
				num[i]=num[i+1];
			}
		}
	}
	for(t=0;t<k;t++){
	//	printf("%d%c  ",num[t],ope[t]);	
	}
	res=num[0];
	for(t=0;t<k;t++){
		if(ope[t]=='+'){
			res+=num[t+1];
		}
		if(ope[t]=='-'){
			res-=num[t+1];
		}
	}
	
	printf("%d",res);
	return 0;
}
/*
void sqeeze();
//void forward(char str[],int n,int bit);
int str[MAX];
char num[MAX];
int i,j,res,sub,bit;
int main(){
	gets(num);
	for(i=0;num[i]!='=';i++)str[i]=num[i];
	str[i]=1e9;
	sqeeze();
	for(i=0;str[i]!=1e9;i++){
		if(str[i]>='0'&&str[i]<='9')str[i]-='0';
	}
	for(i=0;str[i]!=1e9;i++){
		if(str[i]>=0&&str[i]<=9){
			for(j=i+1;str[j]>=0&&str[j]<=9;j++){
				str[i]=str[i]*10+str[j];
			}
			for(;i<j-1;i++){
				str[i+1]=' ';
			}
		}
	}
	sqeeze();
	for(j=i=0;str[i]!=1e9;i++){
		if(str[i]=='-'||str[i]=='+')j=i+1;
		else if(str[i]=='*'){
			str[j]*=str[i+1];
			str[j+1]=str[j+2]=' ';
		}
		else if(str[i]=='/'){
			str[j]/=str[i+1];
			str[j+1]=str[j+2]=' ';
		}
	}
	sqeeze();
	res=str[0];
	for(i=0;str[i]!=1e9;i++){
		if(str[i]=='-'){
			res-=str[i+1];
		}
		else if(str[i]=='+'){
			res+=str[i+1];
		}
	}
	printf("%d",res);
	return 0;
}

void sqeeze(){
	int k,l;
	for(k=0,l=0;str[k]!=1e9;k++){
		if(str[k]!=' '){
			str[l]=str[k];
			l++;
		}
	}
	str[k+1]=1e9;
	return;
}
*/
/*
void forward(char str[],int n,int bit){
	for(i=n;str[i+bit]!='\0';i++){
		str[i]=str[i+bit];
	}
	str[i]='\0';	
}
*/

