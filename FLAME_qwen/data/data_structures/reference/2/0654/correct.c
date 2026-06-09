#include<stdio.h>
#include<string.h>
char str[1001000],s[1001000],cal[1001000],cal1[1001000];
int index[1001000],Index[1001000],num[1001000],num1[1001000];
int sum,multiple;
int flag=0; 
int i,j,t,k,p,q,w,z,r;
int main(){
	gets(str);
	for(i=0;t<strlen(str);i++){
		if(str[t]!=' '){
			s[i]=str[t];
		t++;
		}
		else{
			for(j=0;str[t+j]==' ';j++)
			continue;
			s[i]=str[t+j];
			t=t+j+1;
		}
	}
	//s[]0~i-1存了所有有效字符 
	for(k=0;k<i-1;k++){
		if(s[k]=='*' ||s[k]=='/' || s[k]=='+' || s[k]=='-')
		flag=1;
	}
	if(flag==0){
		for(k=0;k<i-1;k++){
			printf("%c",s[k]);
		}
		return 0;
	}
	for(k=0,j=1;k<i-1;k++){
		if(s[k]<'0' || s[k]>'9'){
			cal[j]=s[k];
			index[j]=k;
			j++;
		}
	}//第t个运算符的位置为index[t],第t个运算符的内容为cal[t] ,总共有j-1个（1~j-1） (没算等号）故应有j个数 
	index[0]=-1; 
	index[j]=i-1;
	cal[j]='=';
	for(q=0;q<=j-1;q++){
		for(p=index[q]+1;p<index[q+1];p++){
				num[q+1]=10*num[q+1]+s[p]-'0';	
		}
	}                           //num[1]cal[1].......num[j-1]cal[j-1]num[j]=
	num1[1]=num[1];
for(w=1,z=1;w<=j-1;w++){
if(cal[w]=='+'||cal[w]=='-'){
	cal1[z]=cal[w];
	Index[z]=w;
	z++;
}
}//+-在I[]1~z-1
Index[0]=0;
Index[z]=j;
//for(r=0;r<=z;r++)printf("%d ",Index[r]);return 0;
for(t=1;t<=z;t++){
    w=Index[t-1]+1;
	num1[t]=num[w];
	for(;w<Index[t];w++){
	if(cal[w]=='*')	{
		num1[t]*=num[w+1];
	}
	else if(cal[w]=='/'){
		num1[t]/=num[w+1];
	}
	}
	}
//	for(r=1;r<=z-1;r++) printf("%d%c",num1[r],cal1[r]); return 0; 
	//num1[1]cal1[1]...num[z-1]cal[z-1]num[z]=
sum=num1[1];
for(r=1;r<=z-1;r++){
	if(cal1[r]=='+'){
	sum+=num1[r+1];	
	}
	else if(cal1[r]=='-'){
		sum-=num1[r+1];
	}
}
printf("%d",sum);
} 



